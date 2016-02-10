#include "MainDefinitions.h"

#include "ConsoleController.h"

#include <iostream>
#include <conio.h>



bool ConsoleController::KeyHit() const
{
	return static_cast<bool>(_kbhit());
}



int ConsoleController::GetCommand() const
{
	return _getch();
}


