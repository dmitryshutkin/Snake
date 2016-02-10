#ifndef Poisons_h__
#define Poisons_h__

#include "MainDefinitions.h"

#include "AbstractGameObject.h"



class Poisons : public AbstractGameObject
{
public:
	Poisons(GameWorld & w) :AbstractGameObject(w) { };
	virtual void Do() { };
	void NewPoison();
};


#endif // Poisons_h__
