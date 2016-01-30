#include "Python.h"

#include "GameWorld.h"



void Python::moove()
{
    // Change coordinates
    x += dx;
    y += dy;
	
    // Check for a border touch
    #ifdef DEBUG
    if (world.map(x, y) == BORDER)
    {
        dx *= -1;
        x += 2 * dx;
        dy *= -1;
        y += 2 * dy;
    }
    #else
    if (world.map(x, y) == BORDER)
        alive = false;
    #endif

    // Check for self eating
    if (world.map(x, y) == PYTHON)
        #ifdef DEBUG
           ;
        #else
            alive = false;
        #endif

    // Check for fruit eating
    if (world.map(x, y) == FRUIT)
    {
		++world.score;
		world.fruit.newFruit();
    }
    else
    {
		if (world.map(x, y) == POISON)
		{
			if (world.score > 1)
			{
				--world.score;
				world.map(body.front().x, body.front().y) = BLANK;
				world.poison.newPoison();
				body.pop();
			}
			else
			{
				world.poison.newPoison();
				#ifndef DEBUG
				    alive = false;
				#endif
			}
		}
		world.map(body.front().x, body.front().y) = BLANK;
        body.pop();
    }
    body.push(PlainVector(x, y));
	world.map(x, y) = PYTHON;
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


