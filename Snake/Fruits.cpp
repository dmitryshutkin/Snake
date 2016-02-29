#include "Fruits.h"

#include "AbstractGameWorld.h"

#include <ctime>
#include <cstdlib>




Fruits::Fruits(AbstractGameWorld & w) : AbstractGameObject(w) 
{
	for (size_t i = 0; i < NumOfFruits; ++i)
		NewFruit();
}



void Fruits::NewFruit()
{
	size_t x, y;
	do	{
		srand(static_cast<unsigned int>(time(0)));
		x = rand() % (sizeX - FruitBorder * 2) + FruitBorder;
		y = rand() % (sizeY - FruitBorder * 2) + FruitBorder;
	} while (*world.map(x,y) != nullptr);
	*world.map(x,y) = this;
}
