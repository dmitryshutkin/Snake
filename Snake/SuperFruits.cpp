#include "SuperFruits.h"

#include "GameWorld.h"

#include <ctime>
#include <cstdlib>






void SuperFruits::NewFruit()
{
	size_t x, y;
	do {
		srand(static_cast<unsigned int>(time(0)));
		x = rand() % (sizeX - FruitBorder * 2) + FruitBorder;
		y = rand() % (sizeY - FruitBorder * 2) + FruitBorder;
	} while (*world.map(x, y) != nullptr);
	*world.map(x, y) = this;
}


