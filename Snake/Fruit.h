#ifndef Fruit_h__
#define Fruit_h__
#include "Python.h"


class Fruit
{
public:
	size_t x, y;
	friend bool operator==(const Fruit& left, const Python& right);
	friend bool operator==(const Python& left, const Fruit& right);

	
};


#endif // Fruit_h__



