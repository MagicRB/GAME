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

        enum rotations {none, up, down, left, right};

        rotations rot1;
        rotations rot2;

        int render(databank* db);
        int init(databank* db);
        void setPos(int x, int y);
        void setRot(rotations rot1x, rotations rot2x);
        bool getCollision(databank* db/*, player* pl*/);

        position getPos();


        std::string tPath;

    protected:

        int x = 0;
        int y = 0;

        SDL_Texture* texture = NULL;
        SDL_Rect rect;

    private:
};

#endif // BLOCK_H
