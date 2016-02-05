#ifndef Python_h__
#define Python_h__

#include "MainDefinitions.h"

#include "AbstractGameObject.h"

#include <queue>



class GameWorld;



class PlainVector
{
public:
    PlainVector(size_t X, size_t Y) :x(X), y(Y) { };
    size_t x, y;
};



class Python : public AbstractGameObject
{

public:

	Python(GameWorld & w) : AbstractGameObject(w) { body.push(PlainVector(x, y)); };

	virtual void Do();
	virtual void Draw() { };

       
    void toUp();
    void toRight();
    void toDown();
    void toLeft();
	void turn();
    
	void shrink();
    void die();

    bool getAlive() const { return alive; }

private:

    bool alive = true;                        // Python is alive

    size_t x = sizeX / 2, y = sizeY / 2;
    size_t dx = 1, dy = 0;

    std::queue<PlainVector> body;

};



#endif // Python_h__
