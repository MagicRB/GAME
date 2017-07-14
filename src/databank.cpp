#include "databank.h"

databank::databank()
{
    //ctor
}

void databank::setSDL_WINDOW(SDL_Window* win)
{
    databank::window = win;
}

SDL_Window* databank::getSDL_WINDOW()
{
    return databank::window;
}

void databank::setSDL_RENDERER(SDL_Renderer* rendererx)
{
    databank::renderer = rendererx;
}

SDL_Renderer* databank::getSDL_RENDERER()
{
    return databank::renderer;
}

void databank::setSDL_EVENT(SDL_Event eventx)
{
    databank::event = eventx;
}

SDL_Event* databank::getSDL_EVENT()
{
    return &event;
}

bool databank::shouldQuit()
{
    return quit;
}

void databank::setQuit(bool q)
{
    quit = q;
}

void databank::subscribeEvent(std::function<void(databank*)> func)
{
    renderEvent.push_back(func);
}

databank::~databank()
{
    //dtor
}
