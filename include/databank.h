#ifndef DATABANK_H
#define DATABANK_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <vector>
#include <functional>

#include <block.h>

#ifdef _WIN32
#include <windows.h>
#endif // _WIN32

class databank
{
    public:
        databank();
        ~databank();

        struct position
        {
            float x;
            floatb= y;
        };

        void setSDL_WINDOW(SDL_Window* win);
        SDL_Window* getSDL_WINDOW();

        void setSDL_RENDERER(SDL_Renderer* rendererx);
        SDL_Renderer* getSDL_RENDERER();

        void setSDL_EVENT(SDL_Event eventx);
        SDL_Event* getSDL_EVENT();

        bool shouldQuit();
        void setQuit(bool q);

        std::string vstr(std::vector<std::string> v, unsigned int i);

        void subscribeEvent(std::function<void(databank*)> func);
        void subscribeGEvent(std::function<void(databank*)> func);
        void subscribeLEvent(std::function<void(databank*, std::vector<std::string>)> func);
        void subscribeEEvent(std::function<void(databank*)> func);

        int getCX();
        int getCY();

        void setCX(int chxx);
        void setCY(int chyx);

        int getCHX();
        int getCHY();

        void setCHX(int chxx);
        void setCHY(int chyx);

        int getResX();
        int getResY();

        void setResX(int resxx);
        void setResY(int resyx);

        void setControls(std::string cont);
        std::string getControls();


        void setPlayerMod(std::string plmx);
        std::string getPlayerMod();

        std::vector<std::function<void(databank*)>> renderEvent;
        std::vector<std::function<void(databank*)>> generalEvent;
        std::vector<std::function<void(databank*, std::vector<std::string>)>> loadEvent;
        std::vector<std::function<void(databank*)>> eventEvent;

        #ifdef _WIN32
        std::vector<HINSTANCE> hvdll;
        std::vector<std::string> svdll;
        #else
        std::vector<void*> hvdll;
        std::vector<std::string> svdll;
        #endif // _WIN32


        void safeQuit();

        long long int fps_ctime = 80;
        long long int fps_ltime = 0;
        long long int fps_dtime = 0;

        std::vector<block*> bl_v;
        std::vector<position> blp_v;

        float plx = 0;
        float ply = 0;

    protected:

        bool quit = false;

        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
        SDL_Event event;

        int cx = 0;
        int cy = 0;

        int chx = 40;
        int chy = 40;

        std::string controls;
        std::string plm;

        int resx = 640;
        int resy = 480;

    private:
};

#endif // DATABANK_H
