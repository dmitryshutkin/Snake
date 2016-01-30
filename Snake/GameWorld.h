#ifndef GameWorld_h__
#define GameWorld_h__

#include "MainDefinitions.h"

#include "Map.h"
#include "Border.h"
#include "Fruit.h"
#include "Poison.h"
#include "Python.h"



class GameWorld
{
public:
    GameWorld();
    GameWorld & operator<< (int);             // keyboard stream reading
    bool operator() ();                       // Game step, returns false to exit the program 
    operator bool() const;                    // returns false to exit the program
	const size_t GetScore() { return score; };
private:
    Map map;
    size_t score = 1;
    Border border = Border(*this);
	Fruit fruit = Fruit(*this);
	Poison poison = Poison(*this);
    Python Pete = Python(*this);              // By the way, his name is Pete
	friend Border;
	friend Fruit;
	friend Poison;
	friend Python;
};




#endif // GameWorld_h__
