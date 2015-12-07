#include "Main.h"
#include "GameWorld.h"

#include <iostream>


using namespace std;





GameWorld::GameWorld()
{	
}



GameWorld & GameWorld::operator<<(int ch)
{
    if (python.getAlive())
        if (ch == ESC)
            python.die;
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
        canvas.redraw();

        // Check for a border touch, self eating, fruit eating
        if (gameSituationAnalysis())
            python.next();
        else python.die();


    }
    else   
    {
        //x Clear screen for Windows and Linux versions
        //x if (system("cls")) system("clear");
        cout << 
            "\n" "!!!!!!!!!!!!!!!!!!!!!!!" 
            "\n" "!!!    Game Over    !!!" 
            "\n" "!!!!!!!!!!!!!!!!!!!!!!!" 
            << endl;
    }
    return python.getAlive();
}



bool GameWorld::gameSituationAnalysis()
{
    // Game situation analysis

    // Check for a border touch
    if (python.x <= 0 || python.y <= 0 || python.x >= sizeX || python.y >= sizeY)
    {
        //#ifdef DEBUG
        //if (python.x <= 0)
        //{
        //    python.right();
        //}
        //else if (python.y <= 0)
        //{
        //    python.down();
        //}
        //else if (python.x >= sizeX)
        //{
        //    python.left();
        //}
        //else if (python.y >= sizeY)
        //{
        //    python.up();
        //}
        //#elif
            python.die();
        //#endif // DEBUG
    }
    // Check for a self touch
    else if (python.selfEating())
        python.die();
    // Check for a fruit eating
    else if (python == fruit)
    {
        ++score;
        fruit.next();
        canvas.rearrangeFruit();
    }
    return python.getAlive();
}

GameWorld::operator bool() const
{
    return python.getAlive();
}



