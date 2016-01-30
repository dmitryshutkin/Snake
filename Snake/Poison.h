#ifndef Poison_h__
#define Poison_h__

#include "MainDefinitions.h"



class GameWorld;



class Poison
{
	GameWorld & world;
public:
	Poison(GameWorld & w) : world(w) { };
	void newPoison();
};


#endif // Poison_h__
