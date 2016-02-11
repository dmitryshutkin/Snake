#ifndef FruitsTestGameWorld_h__
#define FruitsTestGameWorld_h__

#include "MainDefinitions.h"

#include "AbstractGameWorld.h"
#include "Fruits.h"





class FruitsTestGameWorld : protected AbstractGameWorld
{
public:
	bool FruitsSouldCreateNewFruit();
private:
	Fruits fruits = Fruits(*this);
	friend Fruits;
	virtual void Interact(AbstractGameObject &, AbstractGameObject &) { throw; };

};




#endif // FruitsTestGameWorld_h__
