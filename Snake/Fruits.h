#ifndef Fruits_h__
#define Fruits_h__

#include "MainDefinitions.h"

#include "AbstractGameObject.h"



class Fruits : public AbstractGameObject
{
public:
	Fruits(AbstractGameWorld & w) : AbstractGameObject(w) { };
	virtual void Do() { };
	void NewFruit();
};

#endif // Fruits_h__
