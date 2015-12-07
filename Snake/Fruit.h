#ifndef Fruit_h__
#define Fruit_h__
// #include "Python.h"

class Python;

class Fruit
{
public:
    size_t x = 15;
    size_t y = 15;

    friend bool operator==(const Fruit &, const Python &);
    friend bool operator!=(const Fruit &, const Python &);

    friend bool operator==(const Python &, const Fruit &);
    friend bool operator!=(const Python &, const Fruit &);

    void next();

};



#endif // Fruit_h__



