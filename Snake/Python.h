#ifndef Python_h__
#define Python_h__

#include "MainDefinitions.h"
#include "Fruit.h"


class Python
{

public:

    bool getAlive() const { return alive; }
    void next();
    void up();
    void right();
    void down();
    void left();
    bool selfEating();
    int x = sizeX / 2, y = sizeY / 2;
    int dx = 0, dy = 1;
    void die();

private:

    bool alive = true;                        // Python is alive

    friend bool operator==(const Fruit &, const Python &);
    friend bool operator!=(const Fruit &, const Python &);

    friend bool operator==(const Python &, const Fruit &);
    friend bool operator!=(const Python &, const Fruit &);

};




inline bool operator==(const Fruit & left, const Python & right) {
    return (left.x == right.x) && (left.y == right.y);
}



inline bool operator!=(const Fruit & left, const Python & right) {
    return !operator==(left, right);
}



inline bool operator==(const Python & left, const Fruit & right) {
   return operator==(right, left);
}



inline bool operator!=(const Python & left, const Fruit & right) {
    return operator!=(right, left);
}


#endif // Python_h__
