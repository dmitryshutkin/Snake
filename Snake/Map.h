#ifndef Map_h__
#define Map_h__

#include "MainDefinitions.h"

#include "AbstractGameObject.h"
#include "AbstractView.h"



class Map 
{
public:
	Map();
	AbstractGameObject * * operator() (size_t, size_t);
private:
	AbstractGameObject * cells[sizeX][sizeY];
};



#endif // Map_h__



