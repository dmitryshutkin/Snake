#ifndef GameWorld_h__
#define GameWorld_h__


#include "Border.h"
#include "Python.h"
#include "Fruit.h"
#include "Canvas.h"



class GameWorld
{
public:
    GameWorld();	
    GameWorld & operator<< (int);             // keyboard stream reading
    bool operator() ();                       // Game step, returns false to exit the program 
    operator bool() const;                    // returns false to exit the program
private:
    bool Alive = true;                        // Python is alive
    Border border;
    Python python;                            // By the way, his name is Pete
    Fruit fruit;
    Canvas canvas;
    size_t score = 0;
};



enum VKey { UP = 72, LEFT = 75, RIGHT = 77, DOWN = 80, F12 = 134, ESC = 27, ENTER = 13 };



#endif // GameWorld_h__
