#include "Poisons.h"

#include "GameWorld.h"

#include <ctime>
#include <cstdlib>



void Poisons::NewPoison()
{
	size_t x, y;
	do	{
		srand(static_cast<unsigned int>(time(0)));
		x = rand() % (sizeX - PoisonBorder * 2) + PoisonBorder;
		y = rand() % (sizeY - PoisonBorder * 2) + PoisonBorder;
	} while (*world.map(x, y) != nullptr);
	*world.map(x, y) = this;
}


