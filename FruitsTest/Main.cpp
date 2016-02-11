#include "MainDefinitions.h"

#include "FruitsTestGameWorld.h"

#include <iostream>

using namespace std;



int main()
{
	FruitsTestGameWorld world;

	size_t numOfTests = sizeX * sizeY;
	size_t count = 0;

	for (size_t i = 0; i < numOfTests; ++i)
	{
		cout << "Test: " << i << " - ";
		if (world.FruitsSouldCreateNewFruit())
		{
			++count;
			cout << "success" << endl;
		}
		else
			cout << "fail" << endl;
	}
	cout << "Number of success tests " << count << " of " << numOfTests << endl;
	cin.get();

	return 0;
}

