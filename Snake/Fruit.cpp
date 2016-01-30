#include "Fruit.h"

#include "GameWorld.h"

#include <ctime>
#include <cstdlib>




void Fruit::newFruit()
{
	size_t x, y;
	do	{
		srand(static_cast<unsigned int>(time(0)));
		x = rand() % (sizeX - FruitBorder * 2) + FruitBorder;
		y = rand() % (sizeY - FruitBorder * 2) + FruitBorder;
	} while (world.map(x,y) != BLANK);
	world.map(x,y) = FRUIT;
}
