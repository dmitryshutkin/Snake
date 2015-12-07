#include "Canvas.h"

Canvas::Canvas()
{
    for (int j = 0; j < sizeY - 2; ++j)
        for (int i = 0; i < sizeX - 2; ++i)
            cells[i][j] = Blank;

}

void Canvas::redraw()
{
    // Drawing
    size_t i;
    // Top
    for (i = 0; i < sizeX; ++i)
        cout << '#';
    cout << endl;
    // Sides with the field and Pete
    for (size_t j = 1; j < sizeY - 1; ++j)
    {
        // Draw border
        cout << '#';
        // Draw the line with field and Python parts
        for (i = 0; i < sizeX - 2; ++i)
            cout << interpretCell(cells[i][j - 1]);
        // Draw border
        cout << '#';
        // Next line
        cout << endl;
    }
    // Bottom
    for (i = 0; i < sizeX; ++i)
        cout << '#';
    cout << endl;

}

char Canvas::interpretCell(size_t cell)
{
    switch (cell)
    {
    case Pete:
        return 'O';
    case Bord:
        return '#';
    case Fruit:
        return 'F';
    }
    return ' ';
}

void Canvas::rearrangePython()
{
    // Rearrange Pete
    // Delete Pete
    cells[python.x - python.dx - 1][python.y - python.dy - 1] = Blank;
    // Put Pete to a new position
    cells[python.x - 1][python.y - 1] = Pete;
    return;
}

void Canvas::rearrangeFruit()
{
    return;
}
