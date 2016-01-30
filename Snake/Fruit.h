#ifndef Fruit_h__
#define Fruit_h__

#include "MainDefinitions.h"


class GameWorld;



class Fruit
{
	GameWorld & world;
public:
	Fruit(GameWorld & w) : world(w) { };
	void newFruit();
};

#endif // Fruit_h__
