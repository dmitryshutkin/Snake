#ifndef Canvas_h__
#define Canvas_h__

#include "MainDefinitions.h"




class Canvas 
{
public:
    Canvas();
    void draw();
    int & operator() (int, int);

private:
    int cells[sizeX][sizeY];
    char interpretCell(int);

};



#endif // Canvas_h__



