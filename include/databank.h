#ifndef DATABANK_H
#define DATABANK_H

#include <SDL2/SDL.h>
#include <vector>
#include <functional>

class databank
{
    public:
        databank();
        ~databank();

        void setSDL_WINDOW(SDL_Window* win);
        SDL_Window* getSDL_WINDOW();

        void setSDL_RENDERER(SDL_Renderer* rendererx);
        SDL_Renderer* getSDL_RENDERER();

        void setSDL_EVENT(SDL_Event eventx);
        SDL_Event* getSDL_EVENT();

        bool shouldQuit();
        void setQuit(bool q);

        void subscribeEvent(std::function<void(databank*)> func);

        bool quit = false;

        std::vector<std::function<void(databank*)>> renderEvent;

    protected:

        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
        SDL_Event event;


    private:
};

#endif // DATABANK_H
