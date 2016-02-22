#include "MainDefinitions.h"

#include "GameWorld.h"
#include "ConsoleView.h"
#include "ConsoleController.h"



int main()
{
	// Create view/controller
	ConsoleView consoleView;
	const ConsoleController consoleController;

	do {

		// Create the World!!!
		GameWorld gameWorld(consoleView, consoleController);

		// Game loop, send keyboard messages into the World
		gameWorld.Be();

	} while (consoleController.GetCommand() != ESC);

	return 0;	
}
