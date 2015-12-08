#include "Fruit.h"
#include <ctime>
#include <cstdlib>



Fruit::Fruit()
{
    srand(static_cast<unsigned int>(time(0)));
    x = rand() % sizeX;
    y = rand() % sizeY;
}



void Fruit::newFr()
{
    srand(static_cast<unsigned int>(time(0)));
    x = rand() % sizeX;
    y = rand() % sizeY;
    return;
}
