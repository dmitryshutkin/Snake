#include "Main.h"
#include "GameWorld.h"


GameWorld::GameWorld()
{
}

GameWorld::~GameWorld()
{
}

GameWorld & GameWorld::operator<<(char)
{
	return *this;
}

GameWorld::operator bool() const
{
	return false;
}

