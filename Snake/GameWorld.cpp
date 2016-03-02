#include "GameWorld.h"

#include <windows.h>
#include <typeinfo>


using namespace std;



GameWorld::GameWorld(AbstractView & v, const AbstractController & c) : view(v), controller(c)
{
	view.SetMap(&map);

	gameObjects.push_back(new Fruits(*this));
	gameObjects.push_back(new Poisons(*this));
	gameObjects.push_back(new Turns(*this));
	gameObjects.push_back(new SuperFruits(*this));
//	gameObjects.push_back(new Python(*this));
	gameObjects.push_back(new Border(*this));


	view.Redraw();
}



GameWorld::~GameWorld()
{
	// Deleting gameWorld objects from heap
	for (const auto & obj : gameObjects)
		delete obj;
	// Deleting pointers
	gameObjects.clear();
}



GameWorld & GameWorld::operator<<(int ch)
{
	if (Pete.GetAlive())
		if (ch == ESC)
			Pete.Die();
		else
		{
			// Change python's direction
			switch (ch)
			{
			case UP:
				Pete.ToUp();
				break;
			case RIGHT:
				Pete.ToRight();
				break;
			case DOWN:
				Pete.ToDown();
				break;
			case LEFT:
				Pete.ToLeft();
				break;
			}
		}
	return *this;
}



void GameWorld::Be()
{
	// Game loop, send keyboard messages into the World
	view.ClearField();
	do {
		if (controller.KeyHit())				    // If any key is pressed
			*this << controller.GetCommand();		// Send message from controller into the Game World
		Sleep(SLEEP_TIME);
	} while (Do());				            // Do while the World state is true

	// Completion
	view.PrintResult(score);
}



bool GameWorld::Do()
{
	// Game step
	// Main objects activity
	if (numOfGrows > 0)
	{
		++score;
		Pete.Grow();
		--numOfGrows;
	}
	Pete.Do();
	// Other objects activity
	for (const auto & obj : gameObjects)
		obj->Do();
	// Redraw the scene
	view.Redraw();
	// Check for being alive and return the state
	return Pete.GetAlive();
}



bool GameWorld::operator()()
{
	return Do();
}



GameWorld::operator bool() const
{
	return Pete.GetAlive();
}



void GameWorld::Interact(AbstractGameObject & aggressor, AbstractGameObject & victim)
{
	if (typeid(aggressor) == typeid(Python))
		if (typeid(victim) == typeid(Python))
			Interact(dynamic_cast<Python &>(aggressor), dynamic_cast<Python &>(victim));
		else if (typeid(victim) == typeid(Border))
			Interact(dynamic_cast<Python &>(aggressor), dynamic_cast<Border &>(victim));
		else if (typeid(victim) == typeid(Fruits))
			Interact(dynamic_cast<Python &>(aggressor), dynamic_cast<Fruits &>(victim));
		else if (typeid(victim) == typeid(SuperFruits))
			Interact(dynamic_cast<Python &>(aggressor), dynamic_cast<SuperFruits &>(victim));
		else if (typeid(victim) == typeid(Poisons))
			Interact(dynamic_cast<Python &>(aggressor), dynamic_cast<Poisons &>(victim));
		else if (typeid(victim) == typeid(Turns))
			Interact(dynamic_cast<Python &>(aggressor), dynamic_cast<Turns &>(victim));
		else if (typeid(victim) == typeid(Python))
			Interact(dynamic_cast<Python &>(aggressor), dynamic_cast<Python &>(victim));
}



void GameWorld::Interact(Python & aggressor, Border & victim)
{
	aggressor.Die();
}



void GameWorld::Interact(Python & aggressor, Fruits & victim)
{
	++score;
	if (aggressor.GetGrowing())
		++numOfGrows;
	aggressor.Grow();
	victim.NewFruit();
}



void GameWorld::Interact(Python & aggressor, SuperFruits & victim)
{
	++score;
	numOfGrows += NumOfSuperFruitGrows - 1;
	if (aggressor.GetGrowing())
		++numOfGrows;
	aggressor.Grow();
	victim.NewFruit();

}



void GameWorld::Interact(Python & aggressor, Poisons & victim)
{
	victim.NewPoison();
	if (score > 1)
	{
		--score;
		aggressor.Shrink();
	}
	else
		#ifndef DEBUG
			aggressor.Die();
		#else
			;
		#endif
}



void GameWorld::Interact(Python & aggressor, Turns & victim)
{
	aggressor.Turn();
	victim.NewTurn();
}



void GameWorld::Interact(Python & aggressor, Python & victim)
{
	#ifndef DEBUG
	victim.Die();
	#endif
}


