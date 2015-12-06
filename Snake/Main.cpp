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
	


	// Create the World!!!
	GameWorld gameWorld;

	// Loop send keyboard messages into the World
	char ch = 0;
	while (cin.get(ch) && gameWorld << ch);



	// Completion
	cout << "Temporary version return code is -1" << endl;
	return -1;
	
}