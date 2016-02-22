#include "MainDefinitions.h"

#include "FruitsTestGameWorld.h"

#include <iostream>

using namespace std;



int main()
{
	FruitsTestGameWorld world;

	size_t numOfTests = sizeX * sizeY / 4;
	size_t countOfSuccess = 0;

	for (size_t i = 0; i < numOfTests; ++i)
	{
		cout << "Test " << i << " - ";
		if (world.FruitsSouldCreateNewFruit())
		{
			++countOfSuccess;
			cout << "success" << endl;
		}
		else
			cout << "fail" << endl;
	}
	cout << "Number of success " << countOfSuccess << " of " << numOfTests << " tests" << endl;
	cin.get();

	return 0;
}

