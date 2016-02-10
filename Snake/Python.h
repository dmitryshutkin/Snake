#ifndef Python_h__
#define Python_h__

#include "MainDefinitions.h"

#include "AbstractGameObject.h"

#include <deque>



class PlainVector
{
public:
	PlainVector(size_t X, size_t Y) :x(X), y(Y) { };
	size_t x, y;
};



class Python : public AbstractGameObject
{

public:

	Python(AbstractGameWorld & w) : AbstractGameObject(w) { body.push_front(PlainVector(x, y)); };

	virtual void Do();
	   
	void ToUp();
	void ToRight();
	void ToDown();
	void ToLeft();
	void Turn();
	
	void BeGrowing();
	void Shrink();
	void Die();

	bool GetAlive() const { return alive; }
	bool GetGrowing() const { return growing; }

private:

	bool alive = true;                        // Python is alive
	bool growing = false;

	size_t x = sizeX / 2, y = sizeY / 2;
	size_t dx = 1, dy = 0;

	std::deque<PlainVector> body;

};



#endif // Python_h__
