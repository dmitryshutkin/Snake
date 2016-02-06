#include "Map.h"

#include "GameWorld.h"

#include <iostream>
//#include <ctime>
//#include <cstdlib>



using namespace std;



Map::Map()
{
    for (size_t j = 0; j < sizeY; ++j)
        for (size_t i = 0; i < sizeX; ++i)
            cells[i][j] = nullptr;
}



AbstractGameObject * * Map::operator()(size_t x, size_t y)
{
    return &cells[x][y];
}



char Map::interpretCell(AbstractGameObject * cell)
{
    if (cell == nullptr)
        return ' ';
    else if (typeid(*cell) == typeid(Border))
        return BORDER_SYMB;
    else if (typeid(*cell) == typeid(Python))
        return PYTHON_SYMB;
    else if (typeid(*cell) == typeid(Fruit))
        return FRUIT_SYMB;
	else if (typeid(*cell) == typeid(Poison))
		return POISON_SYMB;
	else if (typeid(*cell) == typeid(Turn))
		return TURN_SYMB;

    return '!';
}




void Map::reDraw()
{
	if (system("cls")) system("clear");
    for (size_t j = 0; j < sizeY; ++j)
    {
        for (size_t i = 0; i < sizeX; ++i)
            cout << interpretCell(cells[i][j]);
        cout << endl;
    }       
}


