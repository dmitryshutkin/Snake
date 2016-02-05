#include "GameWorld.h"

#include <iostream>


using namespace std;



GameWorld::GameWorld()
{
	size_t i;
    border.newBorder();
	for (i = 0; i < NumOfFruits; ++i)
		fruit.newFruit();
	for (i = 0; i < NumOfPoisons; ++i)
		poison.newPoison();
	for (i = 0; i < NumOfTurns; ++i)
		turn.newTurn();
	map.reDraw();
}



GameWorld & GameWorld::operator<<(int ch)
{
    if (Pete.getAlive())
        if (ch == ESC)
            Pete.die();
        else
        {
            // Change the Python direction
            switch (ch)
            {
            case UP:
                Pete.toUp();
                break;
            case RIGHT:
                Pete.toRight();
                break;
            case DOWN:
                Pete.toDown();
                break;
            case LEFT:
                Pete.toLeft();
                break;
            }
        }
    return *this;
}



bool GameWorld::Do()
{
    // Game step
	border.Do();
	fruit.Do();
	poison.Do();
    Pete.Do();
    map.reDraw();
    return Pete.getAlive();
}



bool GameWorld::operator()()
{
	return Do();
}



GameWorld::operator bool() const
{
    return Pete.getAlive();
}



void GameWorld::Interact(Python & aggressor, Border & victim)
{
	aggressor.die();
}



void GameWorld::Interact(Python & aggressor, Python & victim)
{
	victim.die();
}



void GameWorld::Interact(Python & aggressor, Fruit & victim)
{
	++score;
	victim.newFruit();
}



void GameWorld::Interact(Python & aggressor, Poison & victim)
{
	victim.newPoison();
	if (score > 1)
	{
		--score;
		aggressor.shrink();
	}
	else
		#ifndef DEBUG
		    aggressor.die();
	    #else
		    ;
		#endif
}



void GameWorld::Interact(Python & aggressor, Turn & victim)
{
	aggressor.turn();
	victim.newTurn();
}



