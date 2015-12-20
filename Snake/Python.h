#ifndef Python_h__
#define Python_h__

#include "MainDefinitions.h"
#include "Field.h"

#include <queue>



class PlainVector
{
public:
    PlainVector(int X, int Y) :x(X), y(Y) { };
    int x, y;
};




class Python
{
    Field & field;

public:

    Python(Field & fi) : field(fi) { body.push(PlainVector(x, y)); };
       
    void toUp();
    void toRight();
    void toDown();
    void toLeft();
    
    void moove();
    void die();

    bool getAlive() const { return alive; }

private:

    bool alive = true;                        // Python is alive
    int length = 1;

    int x = sizeX / 2, y = sizeY / 2;
    int dx = 0, dy = 1;

    std::queue<PlainVector> body;

};



#endif // Python_h__
