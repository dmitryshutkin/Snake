#ifndef SuperFruits_h__
#define SuperFruits_h__

#include "AbstractGameObject.h"



class SuperFruits : public AbstractGameObject
{
public:
	SuperFruits(GameWorld & w) : AbstractGameObject(w) { };
	virtual void Do() { };
	void NewFruit();

};




#endif // SuperFruits_h__
