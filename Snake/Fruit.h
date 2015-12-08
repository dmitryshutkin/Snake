#ifndef Fruit_h__
#define Fruit_h__

#include "MainDefinitions.h"


class Python;

class Fruit
{
public:
    Fruit();

    int x;
    int y;
    
    void newFr();
    
    friend bool operator==(const Fruit &, const Python &);
    friend bool operator!=(const Fruit &, const Python &);

    friend bool operator==(const Python &, const Fruit &);
    friend bool operator!=(const Python &, const Fruit &);

};



#endif // Fruit_h__



