#ifndef Phisics_h__
#define Phisics_h__

#include "MainDefinitions.h"



class Phisics 
{
public:
    Phisics();
    void draw();
    int & operator() (int, int);
    void newFruit();
private:
    int cells[sizeX][sizeY];
    char interpretCell(int);
};



#endif // Phisics_h__



