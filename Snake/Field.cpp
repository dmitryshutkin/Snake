#include "Field.h"
#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;



Field::Field()
{
    for (int j = 0; j < sizeY; ++j)
        for (int i = 0; i < sizeX; ++i)
            cells[i][j] = BLANK;

}



void Field::draw()
{
    for (int j = 0; j < sizeY; ++j)
    {
        for (int i = 0; i < sizeX; ++i)
            cout << interpretCell(cells[i][j]);
        cout << endl;
    }
       
}



int & Field::operator()(int x, int y)
{
    return cells[x][y];
}



void Field::newFruit()
{
    static const int FruitBorder = 3;
    int x, y;
    do {
        srand(static_cast<unsigned int>(time(0)));
        x = rand() % (sizeX - FruitBorder * 2) + FruitBorder;
        y = rand() % (sizeY - FruitBorder * 2) + FruitBorder;
    } while (cells[x][y] != BLANK);
    cells[x][y] = FRUIT;
}



char Field::interpretCell(int cell)
{
    if (cell == BLANK)
        return ' ';
    else if (cell == BORDER)
        return '#';
    else if (cell == PYTHON)
        return '@';
    else if (cell == FRUIT)
        return 'F';
    return 'x';
}



