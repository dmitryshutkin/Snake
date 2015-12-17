#ifndef GameWorld_h__
#define GameWorld_h__

#include "MainDefinitions.h"

#include "Border.h"
#include "Python.h"
#include "Phisics.h"



class GameWorld
{
    Phisics thePhisics;
    Border theBorder = Border(thePhisics);
    Python Pete = Python(thePhisics);         // By the way, his name is Pete
    int score = 0;
public:
    GameWorld();
    GameWorld & operator<< (int);             // keyboard stream reading
    bool operator() ();                       // Game step, returns false to exit the program 
    operator bool() const;                    // returns false to exit the program
};




#endif // GameWorld_h__
