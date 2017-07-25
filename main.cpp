#define SDL_MAIN_HANDLED

#include <windows.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <functional>

#include <chrono>

#include <fstream>
#include <string>
#include <sstream>

#include <databank.h>

typedef void (__stdcall *f_funci)(databank*);
typedef void (__stdcall *f_funco)(databank*, std::vector<std::string>);

void SDL_INIT(databank* db)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        exit(-1);
    }

    db->setSDL_WINDOW(SDL_CreateWindow("GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, db->getResX(), db->getResY(), SDL_WINDOW_SHOWN));
    db->setSDL_RENDERER(SDL_CreateRenderer(db->getSDL_WINDOW(), -1, SDL_RENDERER_ACCELERATED | SDL_WINDOW_OPENGL));

    //SDL_SetRenderDrawColor( db->getSDL_RENDERER(), 0, 0, 0, 255 );

    db->setCX((-1)*(db->getResX() / db->getCHX() / 2) + db->plx);
    db->setCY((-1)*(db->getResY() / db->getCHY() / 2) + db->ply);
}

void loadConfig(databank* db)
{
    std::ifstream infile;
    infile.open("data/config.txt");

    while (!infile.eof()) // To get you all the lines.
    {
        std::string obj_l;
        std::vector<std::string> Obj_V;

        getline(infile, obj_l); // Saves the line in STRING.

        std::istringstream ss(obj_l);
        std::string token;

        if (obj_l == "")
        {
            break;
        }

        while (std::getline(ss, token, ';'))
        {
            Obj_V.push_back(token);
        }

        if (db->vstr(Obj_V, 0) == "controls")
        {
            db->setControls(db->vstr(Obj_V, 1));
        } else if (db->vstr(Obj_V, 0) == "player")
        {
            db->setPlayerMod(db->vstr(Obj_V, 1));
        }
        Obj_V.clear();
    }
    infile.close();
}

void loadSave(databank* db)
{
    std::ifstream infile;
    infile.open("maps/Test/world.txt");

    while (!infile.eof()) // To get you all the lines.
    {
        std::string obj_l;
        std::vector<std::string> Obj_V;

        getline(infile, obj_l); // Saves the line in STRING.

        std::istringstream ss(obj_l);
        std::string token;

        if (obj_l == "")
        {
            break;
        }

        while (std::getline(ss, token, ';'))
        {
            Obj_V.push_back(token);
        }

        for (unsigned i = 0; i < db->svdll.size(); i++)
        {
            if (db->svdll.at(i) == db->vstr(Obj_V, 0))
            {
                f_funco funci = (f_funco)GetProcAddress(db->hvdll.at(i), "loadObjects");
                funci(db, Obj_V);
            }
        }
        Obj_V.clear();
    }
    infile.close();
}

void loadMods(databank* db)
{
    std::ifstream file("data/modlist.txt");
    std::string str;
    while (std::getline(file, str))
    {
        db->hvdll.push_back(LoadLibrary(("mods/" + str + ".dll").c_str()));
        db->svdll.push_back(str);
        f_funci funci = (f_funci)GetProcAddress(db->hvdll.at(db->hvdll.size() - 1), "initMod");
        funci(db);
    }
}

void SDL_Events(databank* db)
{
    SDL_PollEvent(db->getSDL_EVENT());

    if (db->getSDL_EVENT()->type == SDL_QUIT)
    {
        db->safeQuit();
    }

    for(unsigned short int i = 0; i < db->eventEvent.size(); i++)
    {
        db->eventEvent.at(i)(db);
    }
}

void SDL_Render(databank* db)
{
    SDL_RenderClear(db->getSDL_RENDERER());

    for(unsigned short int i = 0; i < db->renderEvent.size(); i++)
    {
        db->renderEvent.at(i)(db);
    }

    SDL_RenderPresent(db->getSDL_RENDERER());
}

bool fpsControl(databank* db)
{
    auto time = std::chrono::system_clock::now();

    auto since_epoch = time.time_since_epoch();

    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(since_epoch);

    db->fps_ctime = millis.count();

    db->fps_dtime = db->fps_ctime - db->fps_ltime;

    if (db->fps_dtime >= 20)
    {
        return true;
    }
    return false;
}

int main()
{
    databank db;

    SDL_INIT(&db);

    loadConfig(&db);

    loadMods(&db);

    loadSave(&db);

    SDL_Render(&db);

    while (db.shouldQuit() != true)
    {
        if (fpsControl(&db) == true)
        {
            SDL_Events(&db);
            SDL_Render(&db);

            db.fps_ltime = db.fps_ctime;
        }
    }

    db.safeQuit();
}
