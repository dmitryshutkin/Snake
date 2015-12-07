#ifndef Canvas_h__
#define Canvas_h__

class Canvas 
{
public:
    Canvas();
    void redraw();
    static const size_t sizeX = 30, sizeY = 20;
    enum { Pete, Blank, Bord, Fruit } cells[sizeX - 2][sizeY - 2];
    char interpretCell(size_t);
    void rearrangePython();
    void rearrangeFruit();

};
#endif // Canvas_h__



