#include "Main.h"
#include "GameWorld.h"

#include <iostream>

using namespace std;


GameWorld::GameWorld()
{	
}




GameWorld & GameWorld::operator<<(int ch)
{
    if (Alive)
        if (ch == ESC)
            Alive = false;
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
    if (Alive)
    {
        // Game step

        // Clear screen for Windows and Linux versions
        if (system("cls")) system("clear");

        // Redraw the World
        redraw();

        // Move Python virtually
        python.virtualMove();         

        // Game situation analysis
        // Check for a border touch 
        if (python.x <= 0 || python.y <= 0 || python.x >= sizeX || python.y >= sizeY)
            Alive = false;
            // Check for a self touch
            else if (python.selfEating())
                Alive = false;
                // Check for a fruit eating
                else if (python == fruit)
                    ++score;
    }
    else
    {
        // Clear screen for Windows and Linux versions
        // if (system("cls")) system("clear");
        cout << 
            "\n" "!!!!!!!!!!!!!!!!!!!!!" 
            "\n" "!!!   Game Over   !!!" 
            "\n" "!!!!!!!!!!!!!!!!!!!!!" 
            << endl;
    }
    return Alive;
}

GameWorld::operator bool() const
{
    return Alive;
}

void GameWorld::redraw()
{
    // Drawing
    size_t i;
    // Top
    for (i = 0; i < sizeX; ++i)
        cout << '#';
    cout << endl;
    // Sides
    for (size_t j = 1; j < sizeY - 1; ++j)
    {
        cout << '#';
        // Draw the field with Python
        for (i = 1; i < sizeX - 1; ++i)
            cout << ' '; // P[i][j];
        cout << '#';
        cout << endl;
    }
    // Bottom
    for (i = 0; i < sizeX; ++i)
        cout << '#';
    cout << endl;

}
