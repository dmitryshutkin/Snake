#include "Border.h"





void Border::newBorder()
{
    int i;
    for (i = 0; i < sizeX; ++i)
        phisics(i, 0) = phisics(i, sizeY-1) = BORDER;
    for (i = 1; i < sizeY-1; ++i)
        phisics(0, i) = phisics(sizeX-1, i) = BORDER;
    for (i = sizeX*0.3; i < sizeX*0.5; ++i)
        phisics(i, 7) = BORDER;

}
