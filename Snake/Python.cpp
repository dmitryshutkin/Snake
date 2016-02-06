#include "Python.h"

#include "GameWorld.h"



void Python::Do()
{
    // Change coordinates
    x += dx;
    y += dy;
	// Do we touch anything?!
	if (*world.map(x, y) != nullptr)
		world.Interact(*this, **world.map(x, y));
	// Move
	if (growing)
	{
		body.push_back(PlainVector(x, y));
		*world.map(x, y) = this;
		growing = false;
	}
	else
	{
		body.push_back(PlainVector(x, y));
		*world.map(x, y) = this;
		shrink();
	}
}



void Python::Draw()
{
	//std::deque<PlainVector>::iterator iter;
	//for (iter = body.begin(); iter != body.end(); ++iter)
	//	*(world.map(iter->x,iter->y)) = this;
}



void Python::die()
{
    alive = false;
}



void Python::beGrowing()
{
	growing = true;
}



void Python::toUp()
{
    if (dy != 1)  // Prevent self eating on a back moving try 
    {
        dx = 0;
        dy = -1;
    }
}



void Python::toRight()
{
    if (dx != -1)
    {
        dx = 1;
        dy = 0;
    }
}



void Python::toDown()
{
    if (dy != -1)
    {
        dx = 0;
        dy = 1;
    }
}



void Python::toLeft()
{
    if (dx != 1)
    {
        dx = -1;
        dy = 0;
    }
}

void Python::turn()
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



void Python::shrink()
{
	*world.map(body.front().x, body.front().y) = nullptr;
	body.pop_front();
}


