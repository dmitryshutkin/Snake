#include "TestMap.h"



using namespace std;



TestMap::TestMap() 
{
	for (size_t j = 0; j < sizeY; ++j)
		for (size_t i = 0; i < sizeX; ++i)
			cells[i][j] = nullptr;
}



AbstractGameObject * * TestMap::operator()(size_t x, size_t y)
{
	return &cells[x][y];
}




