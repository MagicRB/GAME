#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

#include <databank.h>

class block
{
    public:
        block();
        ~block();

        int render(databank* db);
        int init(databank* db);

    protected:

    private:
};

#endif // BLOCK_H
