#include "FruitsTestGameWorld.h"

bool FruitsTestGameWorld::FruitsSouldCreateNewFruit()
{

	size_t countBefore = 0, countAfter = 0;
	for (size_t j = 0; j < sizeY; ++j)
		for (size_t i = 0; i < sizeX; ++i)
			if (*map(i, j) == &fruits)
				++countBefore;

	fruits.NewFruit();

	for (size_t j = 0; j < sizeY; ++j)
		for (size_t i = 0; i < sizeX; ++i)
			if (*map(i, j) == &fruits)
				++countAfter;

	return  countAfter - countBefore == 1;
}

