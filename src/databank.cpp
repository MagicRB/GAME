#include "databank.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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

std::string databank::vstr(std::vector<std::string> v, unsigned int i)
{
    if (v.size() - 1 >= i)
    {
        return v.at(i);
    }
    return "";
}

void databank::subscribeEvent(std::function<void(databank*)> func)
{
    renderEvent.push_back(func);
}

void databank::subscribeLEvent(std::function<void(databank*, std::vector<std::string>)> func)
{
    loadEvent.push_back(func);
}

void databank::subscribeEEvent(std::function<void(databank*)> func)
{
    eventEvent.push_back(func);
}

int databank::getCX()
{
    return cx;
}

int databank::getCY()
{
    return cy;
}

void databank::setCX(int cxx)
{
    cx = cxx;
}

void databank::setCY(int cyx)
{
    cy = cyx;
}

int databank::getCHX()
{
    return chx;
}

int databank::getCHY()
{
    return chy;
}

void databank::setCHX(int chxx)
{
    chx = chxx;
}

void databank::setCHY(int chyx)
{
    chy = chyx;
}

int databank::getResX()
{
    return resx;
}

int databank::getResY()
{
    return resy;
}

void databank::setResX(int resxx)
{
    resx = resxx;
}

void databank::setResY(int resyx)
{
    resy = resyx;
}


void databank::setControls(std::string cont)
{
    controls = cont;
}

std::string databank::getControls()
{
    return controls;
}

void databank::setPlayerMod(std::string plmx)
{
    plm = plmx;
}

std::string databank::getPlayerMod()
{
    return plm;
}

void databank::safeQuit()
{
    SDL_DestroyWindow(getSDL_WINDOW());
    SDL_DestroyRenderer(getSDL_RENDERER());
    SDL_Quit();
    IMG_Quit();

    exit(0);
}

databank::~databank()
{
    //dtor
}
