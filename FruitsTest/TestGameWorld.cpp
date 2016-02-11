#include "TestGameWorld.h"

bool TestGameWorld::FruitsSouldCreateNewFruit()
{
	fruits.NewFruit();
	fruits.NewFruit();

	size_t count = 0;
	for (size_t j = 0; j < sizeY; ++j)
		for (size_t i = 0; i < sizeX; ++i)
			if (*map(i, j) == &fruits)
				++count;
	return count == 2;
}

