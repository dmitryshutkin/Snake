#include "Border.h"





void Border::newBorder()
{
    int i;
    for (i = 0; i < sizeX; ++i)
        field(i, 0) = field(i, sizeY-1) = BORDER;
    for (i = 1; i < sizeY-1; ++i)
        field(0, i) = field(sizeX-1, i) = BORDER;
    #ifdef INNER_BARRIER
        for (i = static_cast<int>(sizeX*0.3); i < static_cast<int>(sizeX*0.5); ++i)
            field(i, 7) = BORDER;
    #endif
}
