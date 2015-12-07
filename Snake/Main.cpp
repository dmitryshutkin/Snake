﻿#include "Main.h"
#include "GameWorld.h"

#include <iostream>
#include <conio.h>


using std::cout;
using std::cin;
using std::endl;


int main()
{
    // Russian language 
    setlocale(LC_ALL, "Russian");

    // Clear screen for Windows and Linux versions
    if (system("cls")) system("clear");	

    // Create the World!!!
    GameWorld gameWorld;

    // Game loop, send keyboard messages into the World
    do {
        if (_kbhit())                   // If any key is pressed
            gameWorld << _getch();      // Send message from console into the Game World
    } while (gameWorld());              // Do while the World state is true

    // Completion
    cout << "\n""Temporary version return code is -1" << endl;
    _getch();
    return -1;	
}
