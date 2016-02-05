#ifndef GameWorld_h__
#define GameWorld_h__

#include "MainDefinitions.h"

#include "Map.h"
#include "Border.h"
#include "Fruit.h"
#include "Poison.h"
#include "Turn.h"
#include "Python.h"



class GameWorld
{

public:

    GameWorld();
    GameWorld & operator<< (int);                  // keyboard stream reading
	bool Do();                                     // Game step, returns false to exit the program 
    bool operator() ();                            
    operator bool() const;                         // returns false to exit the program
	const size_t GetScore() { return score; };

private:

    Map map;
    size_t score = 1;

    Border border = Border(*this); friend Border;
	Fruit fruit = Fruit(*this);	friend Fruit;
	Poison poison = Poison(*this); friend Poison;
	Turn turn = Turn(*this); friend Turn;

    Python Pete = Python(*this); friend Python;    // By the way, his name is Pete	
	void Interact(Python &, Border &);
	void Interact(Python &, Fruit &);
	void Interact(Python &, Poison &);
	void Interact(Python &, Turn &);
	void Interact(Python &, Python &);

};




#endif // GameWorld_h__
