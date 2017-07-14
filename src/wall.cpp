#include "wall.h"

wall::wall()
{
    //ctor
}

int block::render(databank* db)
{
    std::cout << "rendering" << std::endl;
}

int block::init(databank* db)
{
    db->subscribeEvent([this](databank* db)
    {
    this->render(db);
    });
}

wall::~wall()
{
    //dtor
}
