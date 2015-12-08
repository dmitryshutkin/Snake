#ifndef GameWorld_h__
#define GameWorld_h__

#include "MainDefinitions.h"

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
    Python python;                            // By the way, his name is Pete
    Fruit fruit;

    int score = 0;

    Canvas canvas;

    void setPythToCanv();
    void setFruitToCanv();
    void movePythonCanv();

    bool gameSituationAnalysis();
};







#endif // GameWorld_h__
