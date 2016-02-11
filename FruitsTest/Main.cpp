#include "MainDefinitions.h"

#include "TestGameWorld.h"

#include <iostream>

using namespace std;



int main(int argc, char * * argv)
{
	TestGameWorld world;

	if (world.FruitsSouldCreateNewFruit())
		cout << "New fruit created - Ok" << endl;
	else
		cout << "New fruit created - Fail!" << endl;
	cin.get();

	return 0;
}

