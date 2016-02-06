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
            // Change python's direction
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
	// Object activity
	border.Do();
	fruit.Do();
	poison.Do();
    Pete.Do();
	// Redraw the scene
    map.reDraw();
	// Check for being alive and return the state
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
	#ifndef DEBUG
	victim.die();
	#endif
}



void GameWorld::Interact(Python & aggressor, Fruit & victim)
{
	++score;
	aggressor.beGrowing();
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



void GameWorld::Interact(AbstractGameObject & aggressor, AbstractGameObject & victim)
{
	if (typeid(aggressor) == typeid(Python))
		if (typeid(victim) == typeid(Python))
			Interact(dynamic_cast<Python &>(aggressor), dynamic_cast<Python &>(victim));
		else if (typeid(victim) == typeid(Border))
			Interact(dynamic_cast<Python &>(aggressor), dynamic_cast<Border &>(victim));
		else if (typeid(victim) == typeid(Fruit))
			Interact(dynamic_cast<Python &>(aggressor), dynamic_cast<Fruit &>(victim));
		else if (typeid(victim) == typeid(Poison))
			Interact(dynamic_cast<Python &>(aggressor), dynamic_cast<Poison &>(victim));
		else if (typeid(victim) == typeid(Turn))
			Interact(dynamic_cast<Python &>(aggressor), dynamic_cast<Turn &>(victim));
		else if (typeid(victim) == typeid(Python))
			Interact(dynamic_cast<Python &>(aggressor), dynamic_cast<Python &>(victim));
}



