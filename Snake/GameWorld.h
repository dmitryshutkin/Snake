#ifndef GameWorld_h__
#define GameWorld_h__

#include "MainDefinitions.h"

#include "AbstractGameWorld.h"
#include "AbstractView.h"
#include "AbstractController.h"

#include <list>


#include "Border.h"
#include "Fruits.h"
#include "Poisons.h"
#include "Turns.h"
#include "Python.h"
#include "SuperFruits.h"



class GameWorld : protected AbstractGameWorld
{

public:

	GameWorld(AbstractView &, const AbstractController &);
	~GameWorld();
	void Be();                                     // Game loop

private:

	GameWorld & operator<< (int);                  // keyboard stream reading
	bool Do();                                     // Game step, returns false to exit the game loop
	bool operator() ();                            
	operator bool() const;                         // returns false to exit the program
	const size_t GetScore() { return score; };
	AbstractView & view;
	const AbstractController & controller;

	
	
	size_t score = 1;

	Python Pete = Python(*this); friend Python;    // By the way, his name is Pete	
	Border border = Border(*this); friend Border;

	friend AbstractGameObject;
	std::list<AbstractGameObject *> gameObjects;

	//TODO Check the possibility of friend definitions deleting 
	friend Fruits;
	friend SuperFruits; 
	friend Poisons;
	friend Turns;


	////TODO delete objects
	//Fruits fruits = Fruits(*this);	
	//SuperFruits superFruits = SuperFruits(*this); 
	//Poisons poisons = Poisons(*this);
	//Turns turns = Turns(*this); 


	virtual void Interact(AbstractGameObject &, AbstractGameObject &);

	void Interact(Python &, Border &);
	void Interact(Python &, Fruits &);
	void Interact(Python &, SuperFruits &);
	void Interact(Python &, Poisons &);
	void Interact(Python &, Turns &);
	void Interact(Python &, Python &);

	size_t numOfGrows = 0;

};




#endif // GameWorld_h__
