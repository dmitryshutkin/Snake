#ifndef Map_h__
#define Map_h__

#include "MainDefinitions.h"

#include "AbstractGameObject.h"



class Map 
{
public:
    Map();
    void reDraw();
    AbstractGameObject * * operator() (size_t, size_t);
private:
	AbstractGameObject * cells[sizeX][sizeY];
    char interpretCell(AbstractGameObject *);
};



#endif // Map_h__



