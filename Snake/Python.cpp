#include "Python.h"

Python::Python()
{

}

void Python::draw()
{

}

void Python::virtualMove()
{
    x += dx;
    y += dy;
}

void Python::up()
{
    dx = 0;
    dy = -1;
}

void Python::right()
{
    dx = 1;
    dy = 0;
}

void Python::down()
{
    dx = 0;
    dy = 1;
}


void Python::left()
{
    dx = -1;
    dy = 0;

}

bool Python::selfEating()
{
    return false;
}

