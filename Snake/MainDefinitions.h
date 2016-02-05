#ifndef MainDefinitions_h__
#define MainDefinitions_h__


#define DEBUG
//#define INNER_BARRIER

enum Size { sizeX = 30, sizeY = 20 };

enum CellType { BLANK, BORDER, PYTHON, FRUIT, POISON, TURN };

enum VKey { UP = 72, LEFT = 75, RIGHT = 77, DOWN = 80, F12 = 134, ESC = 27, ENTER = 13 };

enum Symb { BORDER_SYMB = '#', PYTHON_SYMB = '@', FRUIT_SYMB = 'F', POISON_SYMB = 'p', TURN_SYMB = '*' };

const size_t SLEEP_TIME = 100;

const size_t NumOfPoisons = 3;

const size_t NumOfFruits = 5;

const size_t NumOfTurns = 5;

const size_t FruitBorder = 3;

const size_t PoisonBorder = 3;

const size_t TurnBorder = 3;



#endif // MainDefinitions_h__



