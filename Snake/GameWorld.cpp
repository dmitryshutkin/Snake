#include "Main.h"
#include "GameWorld.h"
#include <iostream>

using namespace std;


GameWorld::GameWorld()
{
}

GameWorld::~GameWorld()
{
}

GameWorld & GameWorld::operator<<(int ch)
{
	if (ch != 'x')
	{
		cout << ch << ' ';
	}
	else
		State = false;
	return *this;
}

bool GameWorld::operator()()
{
	return State;
}

