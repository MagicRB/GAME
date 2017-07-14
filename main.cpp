#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL2/SDL.h>
#include <windows.h>
#include <functional>

#include <wall.h>
#include <databank.h>

typedef void (__stdcall *f_funci)(databank*);

void quit(databank* db)
{
    SDL_DestroyWindow(db->getSDL_WINDOW());
    SDL_Quit();

    exit(0);
}

void SDL_INIT(databank* db)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        exit(-1);
    }

    db->setSDL_WINDOW(SDL_CreateWindow("GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN));
    db->setSDL_RENDERER(SDL_CreateRenderer(db->getSDL_WINDOW(), -1, SDL_RENDERER_ACCELERATED));

    SDL_SetRenderDrawColor( db->getSDL_RENDERER(), 0, 0, 0, 255 );
}

void SDL_Events(databank* db)
{
    SDL_PollEvent(db->getSDL_EVENT());

    if (db->getSDL_EVENT()->type == SDL_QUIT)
    {
        quit(db);
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

int main()
{
    databank db;

    HINSTANCE  hdll  = LoadLibrary("Main.dll");
    f_funci funci = (f_funci)GetProcAddress(hdll, "initMod");
    std::cout << db.shouldQuit();
    funci(&db);

    SDL_INIT(&db);

    SDL_Render(&db);

    while (db.shouldQuit() != true)
    {
        SDL_Events(&db);
        SDL_Render(&db);
    }

}

//void handleBlock(const std::string& rest_of_line, databank* db) {
//    db->addMyBlock(somehow extract the params from the rest of the line here);
//}
//
//int main() {
//std::map<std::string, std::function<void(const std::string&, databank*)>> map;
//map["block"] = handleBlock;
//// set other here
//
////when actually parsing:
////(assuming your current line is named line and of type string)
////somehow get the part until the first ";" and store it in `type`
//map[type](rest of the line here, your_database_instance);
//}
