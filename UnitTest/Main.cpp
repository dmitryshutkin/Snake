#include "MainDefinitions.h"

#include "TestGameWorld.h"

#include <iostream>

using namespace std;



int main(int argc, char * * argv)
{
	TestGameWorld world;

	cout << "Objects created" << endl;
	if (world.FruitsSouldCreateNewFruit())
		cout << "New fruit created " << endl;
	else
		cout << "New fruit not created " << endl;
	cin.get();

	return 0;
}

