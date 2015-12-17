#include "Python.h"



void Python::moove()
{
    // Change coordinates
    x += dx;
    y += dy;

    // Check for a border touch
    #ifdef DEBUG
    if (phisics(x, y) == BORDER)
    {
        dx *= -1;
        x += 2 * dx;
        dy *= -1;
        y += 2 * dy;
    }
    #else
    if (phisics(x, y) == BORDER)
        alive = false;
    #endif

    // Check for self eating
    if (phisics(x, y) == PYTHON)
        #ifdef DEBUG
            ;
        #else
            alive = false;
        #endif

    // Check for fruit eating
    if (phisics(x, y) == FRUIT)
    {
        length++;
        phisics.newFruit();
        body.push(PlainVector(x, y));
        phisics(x, y) = PYTHON;
    }
    else
    {
        phisics(body.front().x, body.front().y) = BLANK;
        body.pop();
        body.push(PlainVector(x, y));
        phisics(x, y) = PYTHON;
    }


}



void Python::die()
{
    alive = false;
}



void Python::toUp()
{
    dx = 0;
    dy = -1;
}



void Python::toRight()
{
    dx = 1;
    dy = 0;
}



void Python::toDown()
{
    dx = 0;
    dy = 1;
}



void Python::toLeft()
{
    dx = -1;
    dy = 0;

}


