#ifndef Poison_h__
#define Poison_h__

#include "MainDefinitions.h"

#include "AbstractGameObject.h"



class GameWorld;



class Poison : public AbstractGameObject
{
public:
	Poison(GameWorld & w) :AbstractGameObject(w) { };
	virtual void Do() { };
	virtual void Draw() { };
	void newPoison();
};


#endif // Poison_h__
