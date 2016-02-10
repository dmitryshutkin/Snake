#ifndef GameWorld_h__
#define GameWorld_h__

#include "MainDefinitions.h"

#include "AbstractView.h"
#include "AbstractController.h"

#include "Map.h"

#include "Border.h"
#include "Fruits.h"
#include "Poisons.h"
#include "Turns.h"
#include "Python.h"
#include "SuperFruits.h"



class GameWorld
{

public:

	GameWorld(AbstractView &, const AbstractController &);
	GameWorld & operator<< (int);                  // keyboard stream reading
	void Be();                                     // Game loop
	bool Do();                                     // Game step, returns false to exit the game loop
	bool operator() ();                            
	operator bool() const;                         // returns false to exit the program
	const size_t GetScore() { return score; };

private:

	AbstractView & view;
	const AbstractController & controller;

	Map map;
	
	void Interact(AbstractGameObject &, AbstractGameObject &);
	
	size_t score = 1;

	Border border = Border(*this); friend Border;
	Fruits fruits = Fruits(*this);	friend Fruits;
	SuperFruits superFruits = SuperFruits(*this); friend SuperFruits;
	Poisons poisons = Poisons(*this); friend Poisons;
	Turns turns = Turns(*this); friend Turns;

	Python Pete = Python(*this); friend Python;    // By the way, his name is Pete	
	void Interact(Python &, Border &);
	void Interact(Python &, Fruits &);
	void Interact(Python &, SuperFruits &);
	void Interact(Python &, Poisons &);
	void Interact(Python &, Turns &);
	void Interact(Python &, Python &);

	size_t numOfGrows = 0;

};




#endif // GameWorld_h__
