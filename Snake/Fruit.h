#ifndef Fruit_h__
#define Fruit_h__

#include "MainDefinitions.h"

#include "AbstractGameObject.h"


class GameWorld;



class Fruit : public AbstractGameObject
{
public:
	Fruit(GameWorld & w) : AbstractGameObject(w) { };
	virtual void Do() { };
	virtual void Draw() { };
	void newFruit();
};

#endif // Fruit_h__
