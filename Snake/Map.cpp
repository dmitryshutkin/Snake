#include "Map.h"

#include <iostream>
//#include <ctime>
//#include <cstdlib>



using namespace std;



Map::Map()
{
    for (size_t j = 0; j < sizeY; ++j)
        for (size_t i = 0; i < sizeX; ++i)
            cells[i][j] = BLANK;
}



size_t & Map::operator()(size_t x, size_t y)
{
    return cells[x][y];
}



char Map::interpretCell(size_t cell)
{
    if (cell == BLANK)
        return ' ';
    else if (cell == BORDER)
        return BORDER_SYMB;
    else if (cell == PYTHON)
        return PYTHON_SYMB;
    else if (cell == FRUIT)
        return FRUIT_SYMB;
	else if (cell == POISON)
		return POISON_SYMB;
	else if (cell == TURN)
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


