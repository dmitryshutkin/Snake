#include "Main.h"
#include "GameWorld.h"

#include <iostream>


using std::cout;
using std::cin;
using std::endl;


int main()
{
	// Russian language 
	setlocale(LC_ALL, "Russian");
	// Clear screen for Windows and Linux versions
	if (system("cls")) system("clear");
	
	
	// Cycle with
	// game world drawing
	// keyboard inquire 
	// until exit situation

	GameWorld gameWorld;

	char ch = 0;

	while (cin.get(ch) && gameWorld << ch);

	
	cout << "Temporary version return code is -1" << endl;
	return -1;
	
}