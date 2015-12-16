#include "GameWorld.h"

#include <iostream>


using namespace std;


enum VKey { UP = 72, LEFT = 75, RIGHT = 77, DOWN = 80, F12 = 134, ESC = 27, ENTER = 13 };





GameWorld & GameWorld::operator<<(int ch)
{
    if (python.getAlive())
        if (ch == ESC)
            python.die();
        else
        {
            // Change the Python direction
            switch (ch)
            {
            case UP:
                python.up();
                break;
            case RIGHT:
                python.right();
                break;
            case DOWN:
                python.down();
                break;
            case LEFT:
                python.left();
                break;
            }
        }
    return *this;
}



bool GameWorld::operator()()
{
    if (python.getAlive())
    {
        // Game step

        // Clear screen for Windows and Linux versions
        if (system("cls")) system("clear");

        // Redraw the World
        phisics.draw();

        #ifdef DEBUG
            cout << "\n""X: " << python.x << "  Y: " << python.y << "       dx: " << python.dx << "  dy: " << python.dy << endl;
        #endif // DEBUG


        // Check for a border touch, self eating, fruit eating
        if (gameSituationAnalysis())
        {
            python.next();
            movePythonPh();            
        }            
        else python.die();
    }
    return python.getAlive();
}



bool GameWorld::gameSituationAnalysis()
{
    // Game situation analysis

    // Check for a border touch
    #ifdef DEBUG
        if (python.x <= 0)
        {
            phisics(python.x, python.y) = BLANK;
	        python.x = sizeX-1;
        }
        else if (python.y <= 0)
        {
            phisics(python.x, python.y) = BLANK;
	        python.y = sizeY - 1;
        }
        else if (python.x >= (sizeX-1))
        {
            phisics(python.x, python.y) = BLANK;
	        python.x = 0;
        }
        else if (python.y >= (sizeY-1))
        {
            phisics(python.x, python.y) = BLANK;
            python.y = 0;
        }

    #else
        if ((python.x <= 0) || (python.y <= 0) || (python.x >= sizeX-1) || (python.y >= sizeY-1))
            python.die();
    #endif // DEBUG

    // Check for a self touch
    else if (python.selfEating())
        python.die();

    // Check for a fruit eating
    else if (python == fruit)
    {
        ++score;
        fruit.newFr();
    }
    return python.getAlive();
}



void GameWorld::movePythonPh()
{
    phisics(python.x - python.dx, python.y - python.dy) = BLANK;
    setPythonToPh();
}



void GameWorld::setPythonToPh()
{
    phisics(python.x, python.y) = PYTH;
}



void GameWorld::setFruitToPh()
{
    phisics(fruit.x, fruit.y) = FRUIT;
}



GameWorld::operator bool() const
{
    return python.getAlive();
}



