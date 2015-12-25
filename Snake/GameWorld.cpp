#include "GameWorld.h"

#include <iostream>


using namespace std;



GameWorld::GameWorld()
{
    theBorder.newBorder();
    theField.newFruit();
    theField.draw();
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
    if (system("cls")) system("clear");
    Pete.moove();
    theField.draw();
    return Pete.getAlive();
}



GameWorld::operator bool() const
{
    return Pete.getAlive();
}



