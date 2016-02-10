#ifndef SuperFruits_h__
#define SuperFruits_h__

#include "AbstractGameObject.h"



class SuperFruits : public AbstractGameObject
{
public:
	SuperFruits(GameWorld & w) : AbstractGameObject(w) { };
	virtual void Do() { };
	virtual void SetImage() { };
	void NewFruit();

};




#endif // SuperFruits_h__
