#include "Turn.h"

#include "GameWorld.h"

#include <ctime>
#include <cstdlib>



void Turn::newTurn()
{
	size_t x, y;
	do
	{
		srand(static_cast<unsigned int>(time(0)));
		x = rand() % (sizeX - TurnBorder * 2) + TurnBorder;
		y = rand() % (sizeY - TurnBorder * 2) + TurnBorder;
	} while (world.map(x, y) != BLANK);
	world.map(x, y) = TURN;
}


