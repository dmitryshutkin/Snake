#include "Fruit.h"
#include <ctime>
#include <cstdlib>



const int FruitBorder = 3;



Fruit::Fruit()
{
    srand(static_cast<unsigned int>(time(0)));
    x = rand() % (sizeX - FruitBorder * 2) + FruitBorder;
    y = rand() % (sizeY - FruitBorder * 2) + FruitBorder;
}



void Fruit::newFr()
{
    srand(static_cast<unsigned int>(time(0)));
    x = rand() % (sizeX - FruitBorder * 2) + FruitBorder;
    y = rand() % (sizeY - FruitBorder * 2) + FruitBorder;
    return;
}
