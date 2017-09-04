#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <string>

#include <SDL2/SDL.h>

class databank;

class block
{
    public:
        block();
        ~block();

        struct position
        {
            int x;
            int y;
        };

        virtual int render(databank* db) = 0;
        virtual int init(databank* db) = 0;
        virtual void setPos(float x, float y) = 0;
        virtual bool getCollision(databank* db/*, player* pl*/) = 0;
        virtual position getPos() = 0;


        std::string tPath;

    protected:

        float x = 0;
        float y = 0;

        SDL_Texture* texture = NULL;
        SDL_Rect rect;

    private:
};

#endif // BLOCK_H
