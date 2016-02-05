#ifndef Map_h__
#define Map_h__

#include "MainDefinitions.h"



class Map 
{
public:
    Map();
    void reDraw();
    size_t & operator() (size_t, size_t);
private:
    size_t cells[sizeX][sizeY];
    char interpretCell(size_t);
};



#endif // Map_h__



