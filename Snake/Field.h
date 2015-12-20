#ifndef Field_h__
#define Field_h__

#include "MainDefinitions.h"



class Field 
{
public:
    Field();
    void draw();
    int & operator() (int, int);
    void newFruit();
private:
    int cells[sizeX][sizeY];
    char interpretCell(int);
};



#endif // Field_h__



