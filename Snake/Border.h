#ifndef Border_h__
#define Border_h__

#include "MainDefinitions.h"

#include "AbstractGameObject.h"



class Border : public AbstractGameObject
{
public:
    Border(GameWorld & w) : AbstractGameObject(w) { };
	virtual void Do() { }; 
	virtual void SetImage() { }; 
    void newBorder();
};


#endif // Border_h__


