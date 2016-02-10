#include "Python.h"

#include "GameWorld.h"

#include <typeinfo>



void Python::Do()
{
  	#ifdef DEBUG
		if (*world.map(x + dx, y + dy) != nullptr)
			if (typeid(**world.map(x + dx, y + dy)) == typeid(Border))
			{
				dx *= -1;
				dy *= -1;
			}
	#endif
	// Change coordinates
    x += dx;
    y += dy;
	// Do we touch anything?!
	if (*world.map(x, y) != nullptr)
		world.Interact(*this, **world.map(x, y));
	// Move
	if (growing)
	{
		body.push_front(PlainVector(x, y));
		*world.map(x, y) = this;
		growing = false;
	}
	else
	{
		body.push_front(PlainVector(x, y));
		*world.map(x, y) = this;
		Shrink();
	}
}



void Python::SetImage()
{
	// Set sprites in view object
	// Depending on neighbor coordinates we can decide what sprite to use: head, tail, horizontal, vertical or corner
	

}



void Python::Die()
{
    alive = false;
}



void Python::BeGrowing()
{
	growing = true;
}



void Python::ToUp()
{
    if (dy != 1)  // Prevent self eating on a back moving try 
    {
        dx = 0;
        dy = -1;
    }
}



void Python::ToRight()
{
    if (dx != -1)
    {
        dx = 1;
        dy = 0;
    }
}



void Python::ToDown()
{
    if (dy != -1)
    {
        dx = 0;
        dy = 1;
    }
}



void Python::ToLeft()
{
    if (dx != 1)
    {
        dx = -1;
        dy = 0;
    }
}

void Python::Turn()
{
	if (dx == 1)
	{
		dx = 0;
		dy = 1;
	}
	else if (dy == 1)
	{
		dy = 0;
		dx = -1;
	}
	else if (dx == -1)
	{
		dx = 0;
		dy = -1;
	}
	else
	{
		dy = 0;
		dx = 1;
	}
}



void Python::Shrink()
{
	*world.map(body.back().x, body.back().y) = nullptr;
	body.pop_back();
}


