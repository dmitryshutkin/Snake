#ifndef AbstractView_h__
#define AbstractView_h__

// Test of new way of game drawing using some graphic library

#include "MainDefinitions.h"


class Map;


class Sprite
{

};



class AbstractView
{
public:
	virtual void DrawSprite(const Sprite &, size_t, size_t) = 0;
	virtual void DeleteSprite(size_t, size_t) = 0;
	virtual void ClearField() = 0;
	virtual void Redraw() = 0;
	virtual void PrintResult(size_t) = 0;

	void SetMap(Map * m) { gameMap = m; };
protected:
	Map * gameMap;
};




#endif // AbstractView_h__
