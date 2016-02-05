#ifndef Turn_h__
#define Turn_h__

#include "MainDefinitions.h"

#include "AbstractGameObject.h"


class GameWorld;



class Turn : public AbstractGameObject
{
public:
	Turn(GameWorld & w) : AbstractGameObject(w) { };
	virtual void Do() { };
	virtual void Draw() { };
	void newTurn();
};



#endif // Turn_h__
