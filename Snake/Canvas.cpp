#include "Canvas.h"
#include <iostream>


using namespace std;



Canvas::Canvas()
{
    for (int j = 0; j < sizeY; ++j)
        for (int i = 0; i < sizeX; ++i)
            cells[i][j] = BLANK;

}



void Canvas::draw()
{
    // Drawing
    int i;
    // Top
    for (i = 0; i < sizeX + 2; ++i)
        cout << '#';
    cout << endl;
    // Sides with the field and Pyth
    for (int j = 0; j < sizeY; ++j)
    {
        // Draw border
        cout << '#';
        // Draw the line with field and Python parts
        for (i = 0; i < sizeX; ++i)
            cout << interpretCell(cells[i][j]);
        // Draw border
        cout << '#';
        // Next line
        cout << endl;
    }
    // Bottom
    for (i = 0; i < sizeX + 2; ++i)
        cout << '#';
    cout << endl;

}



int & Canvas::operator()(int x, int y)
{
    return cells[x][y];
}



char Canvas::interpretCell(int cell)
{
    if (cell == BLANK)
        return ' ';
    else if (cell == PYTH)
        return '@';
    else if (cell == FRUIT)
        return 'F';
    return 'x';
}



