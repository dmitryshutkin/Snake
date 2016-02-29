#include "SuperFruits.h"

#include "AbstractGameWorld.h"

#include <ctime>
#include <cstdlib>






SuperFruits::SuperFruits(AbstractGameWorld & w) : AbstractGameObject(w)
{
	for (size_t i = 0; i < NumOfSuperFruits; ++i)
		NewFruit();
}



void SuperFruits::NewFruit()
{
	size_t x, y;
	do {
		srand(static_cast<unsigned int>(time(0)));
		x = rand() % (sizeX - SuperFruitBorder * 2) + SuperFruitBorder;
		y = rand() % (sizeY - SuperFruitBorder * 2) + SuperFruitBorder;
	} while (*world.map(x, y) != nullptr);
	*world.map(x, y) = this;
}


