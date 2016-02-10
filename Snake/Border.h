#ifndef Border_h__
#define Border_h__

#include "MainDefinitions.h"

#include "AbstractGameObject.h"



class Border : public AbstractGameObject
{
public:
	Border(AbstractGameWorld & w) : AbstractGameObject(w) { };
	virtual void Do() { }; 
	void newBorder();
};


#endif // Border_h__


