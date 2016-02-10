#include "Turns.h"

#include "AbstractGameWorld.h"

#include <ctime>
#include <cstdlib>



void Turns::NewTurn()
{
	size_t x, y;
	do
	{
		srand(static_cast<unsigned int>(time(0)));
		x = rand() % (sizeX - TurnBorder * 2) + TurnBorder;
		y = rand() % (sizeY - TurnBorder * 2) + TurnBorder;
	} while (*world.map(x, y) != nullptr);
	*world.map(x, y) = this;
}


