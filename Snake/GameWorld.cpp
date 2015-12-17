#include "GameWorld.h"

#include <iostream>



using namespace std;


enum VKey { UP = 72, LEFT = 75, RIGHT = 77, DOWN = 80, F12 = 134, ESC = 27, ENTER = 13 };





GameWorld::GameWorld()
{

    theBorder.newBorder();
    thePhisics.newFruit();
    thePhisics.draw();
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
    thePhisics.draw();
    return Pete.getAlive();
}



GameWorld::operator bool() const
{
    return Pete.getAlive();
}



