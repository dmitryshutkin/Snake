#include "Poison.h"

#include "GameWorld.h"

#include <ctime>
#include <cstdlib>



void Poison::newPoison()
{
	size_t x, y;
	do	{
		srand(static_cast<unsigned int>(time(0)));
		x = rand() % (sizeX - PoisonBorder * 2) + PoisonBorder;
		y = rand() % (sizeY - PoisonBorder * 2) + PoisonBorder;
	} while (world.map(x, y) != BLANK);
	world.map(x, y) = POISON;
}


