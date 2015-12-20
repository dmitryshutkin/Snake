#include "Python.h"



void Python::moove()
{
    // Change coordinates
    x += dx;
    y += dy;

    // Check for a border touch
    #ifdef DEBUG
    if (field(x, y) == BORDER)
    {
        dx *= -1;
        x += 2 * dx;
        dy *= -1;
        y += 2 * dy;
    }
    #else
    if (field(x, y) == BORDER)
        alive = false;
    #endif

    // Check for self eating
    if (field(x, y) == PYTHON)
        #ifdef DEBUG
            ;
        #else
            alive = false;
        #endif

    // Check for fruit eating
    if (field(x, y) == FRUIT)
    {
        length++;
        field.newFruit();
    }
    else
    {
        field(body.front().x, body.front().y) = BLANK;
        body.pop();
    }
    body.push(PlainVector(x, y));
    field(x, y) = PYTHON;


}



void Python::die()
{
    alive = false;
}



void Python::toUp()
{
    if (dy != 1)  // Prevent self eating on a back moving try 
    {
        dx = 0;
        dy = -1;
    }
}



void Python::toRight()
{
    if (dx != -1)
    {
        dx = 1;
        dy = 0;
    }
}



void Python::toDown()
{
    if (dy != -1)
    {
        dx = 0;
        dy = 1;
    }
}



void Python::toLeft()
{
    if (dx != 1)
    {
        dx = -1;
        dy = 0;
    }
}


