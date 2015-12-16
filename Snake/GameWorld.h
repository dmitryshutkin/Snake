#ifndef GameWorld_h__
#define GameWorld_h__

#include "MainDefinitions.h"

#include "Python.h"
#include "Fruit.h"
#include "Phisics.h"
#include "Border.h"



class GameWorld
{
public:
    GameWorld & operator<< (int);             // keyboard stream reading
    bool operator() ();                       // Game step, returns false to exit the program 
    operator bool() const;                    // returns false to exit the program

private:
    Border border = Border(phisics);
    Python python = Python(phisics);          // By the way, his name is Pete
    Fruit fruit = Fruit(phisics);

    int score = 0;

    Phisics phisics;

    void setPythonToPh();
    void setFruitToPh();
    void movePythonPh();

    bool gameSituationAnalysis();
};







#endif // GameWorld_h__
