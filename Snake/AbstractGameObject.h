#ifndef AbstractGameObject_h__
#define AbstractGameObject_h__

#include "MainDefinitions.h"


class GameWorld;



class AbstractGameObject
{
protected:
	GameWorld & world;
public:
	AbstractGameObject(GameWorld & w) : world(w) { };
	virtual void Do() = 0;
	virtual void Draw() = 0;
	// virtual ~AbstractGameObject();
};


#endif // AbstractGameObject_h__

