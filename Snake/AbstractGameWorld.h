#include "MainDefinitions.h"

#include "Map.h"
#include "AbstractGameObject.h"


class AbstractGameWorld
{
public:
	virtual void Interact(AbstractGameObject &, AbstractGameObject &) { throw; };
	Map map;

};

