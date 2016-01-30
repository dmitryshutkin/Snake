#include "GameWorld.h"

#include <iostream>


using namespace std;



GameWorld::GameWorld()
{
	size_t i;
    border.newBorder();
	for (i = 0; i < NumOfFruits; ++i)
		fruit.newFruit();
	for (i = 0; i < NumOfPoisons; ++i)
		poison.newPoison();
	map.reDraw();
}



GameWorld & GameWorld::operator<<(int ch)
{
    if (Pete.getAlive())
        if (ch == ESC)
            Pete.die();
        else
        {
            // Change the Python direction
            switch (ch)
            {
            case UP:
                Pete.toUp();
                break;
            case RIGHT:
                Pete.toRight();
                break;
            case DOWN:
                Pete.toDown();
                break;
            case LEFT:
                Pete.toLeft();
                break;
            }
        }
    return *this;
}



bool GameWorld::operator()()
{
    // Game step
    Pete.moove();
    map.reDraw();
    return Pete.getAlive();
}



GameWorld::operator bool() const
{
    return Pete.getAlive();
}



