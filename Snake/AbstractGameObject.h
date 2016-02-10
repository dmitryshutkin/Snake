#ifndef AbstractGameObject_h__
#define AbstractGameObject_h__

#include "MainDefinitions.h"


class AbstractGameWorld;



class AbstractGameObject
{
protected:
	AbstractGameWorld & world;
public:
	AbstractGameObject(AbstractGameWorld & w) : world(w) { };
	virtual void Do() = 0;
};


#endif // AbstractGameObject_h__

