#ifndef Turns_h__
#define Turns_h__

#include "MainDefinitions.h"

#include "AbstractGameObject.h"



class Turns : public AbstractGameObject
{
public:
	Turns(AbstractGameWorld & w) : AbstractGameObject(w) { };
	virtual void Do() { };
	void NewTurn();
};



#endif // Turns_h__
