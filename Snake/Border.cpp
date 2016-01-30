#include "Border.h"

#include "GameWorld.h"


void Border::newBorder()
{
    size_t i;
    for (i = 0; i < sizeX; ++i)
        world.map(i, 0) = world.map(i, sizeY-1) = BORDER;
    for (i = 1; i < sizeY-1; ++i)
        world.map(0, i) = world.map(sizeX-1, i) = BORDER;
    #ifdef INNER_BARRIER
        for (i = static_cast<size_t>(sizeX*0.3); i < static_cast<size_t>(sizeX*0.5); ++i)
            world.map(i, 7) = BORDER;
		for (i = static_cast<size_t>(sizeX*0.3); i < static_cast<size_t>(sizeX*0.5); ++i)
			world.map(sizeX-i, sizeY-7) = BORDER;
	#endif
}
