#ifndef Border_h__
#define Border_h__

#include "MainDefinitions.h"



class GameWorld;



class Border
{
	GameWorld & world;
public:
    Border(GameWorld & w) : world(w) { };
    void newBorder();
};


#endif // Border_h__


