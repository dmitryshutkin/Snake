#ifndef Border_h__
#define Border_h__

#include "Field.h"



class Border
{
    Field & field;
public:
    Border(Field & fi) : field(fi) { };
    void newBorder();
};


#endif // Border_h__


