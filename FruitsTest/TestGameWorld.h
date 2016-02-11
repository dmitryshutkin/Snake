#ifndef TestGameWorld_h__
#define TestGameWorld_h__

#include "MainDefinitions.h"

#include "AbstractGameWorld.h"
#include "Fruits.h"





class TestGameWorld : protected AbstractGameWorld
{
public:
	bool FruitsSouldCreateNewFruit();
private:
	Fruits fruits = Fruits(*this);
	friend Fruits;
	virtual void Interact(AbstractGameObject &, AbstractGameObject &) { throw; };

};




#endif // TestGameWorld_h__
