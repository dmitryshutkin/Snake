#ifndef TestGameWorld_h__
#define TestGameWorld_h__

#include "MainDefinitions.h"

#include "TestMap.h"
#include "Fruits.h"





class TestGameWorld
{

	TestMap testMap;
	Fruits fruts = Fruits(*this);
	friend Fruits;
};




#endif // TestGameWorld_h__
