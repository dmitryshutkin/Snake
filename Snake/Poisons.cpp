#include "Poisons.h"

#include "AbstractGameWorld.h"

#include <ctime>
#include <cstdlib>



Poisons::Poisons(AbstractGameWorld & w) : AbstractGameObject(w)
{
	for (size_t i = 0; i < NumOfPoisons; ++i)
		NewPoison();
}



void Poisons::NewPoison()
{
	size_t x, y;
	do	{
		srand(static_cast<unsigned int>(time(0)));
		x = rand() % (sizeX - PoisonBorder * 2) + PoisonBorder;
		y = rand() % (sizeY - PoisonBorder * 2) + PoisonBorder;
	} while (*world.map(x, y) != nullptr);
	*world.map(x, y) = this;
}


