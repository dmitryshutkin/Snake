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

    friend bool operator==(const Fruit &, const Python &);
    friend bool operator!=(const Fruit &, const Python &);

    friend bool operator==(const Python &, const Fruit &);
    friend bool operator!=(const Python &, const Fruit &);

    void newFr();

};



#endif // Fruit_h__



