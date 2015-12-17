#ifndef Border_h__
#define Border_h__

#include "Phisics.h"



class Border
{
    Phisics & phisics;
public:
    Border(Phisics & ph) : phisics(ph) { };
    void newBorder();
};


#endif // Border_h__


