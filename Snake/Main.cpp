#include "MainDefinitions.h"
#include "GameWorld.h"

#include <iostream>
#include <conio.h>
#include <windows.h>


using std::cout;
using std::cin;
using std::endl;


int main()
{
    do {
	    // Clear screen both for Windows and Linux versions
	    if (system("cls")) system("clear");	
	
	    // Create the World!!!
	    GameWorld gameWorld;
	
	    // Game loop, send keyboard messages into the World
	    do {
	        if (_kbhit())					// If any key is pressed
	            gameWorld << _getch();		// Send message from console into the Game World
	        Sleep(SLEEP_TIME);
	    } while (gameWorld());				// Do while the World state is true
		
	    // Completion
	    cout << "\n Esc to exit ";
    } while (_getch() != ESC);

    return 0;	
}
