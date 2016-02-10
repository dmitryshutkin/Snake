#include "MainDefinitions.h"

#include "ConsoleView.h"

#include "GameWorld.h"

#include <iostream>



using namespace std;



void ConsoleView::ClearField()
{
	if (system("cls")) system("clear");
}



void ConsoleView::Redraw()
{
	if (system("cls")) system("clear");
	for (size_t j = 0; j < sizeY; ++j)
	{
		for (size_t i = 0; i < sizeX; ++i)
			cout << InterpretMap(*(*gameMap)(i, j)); 
		cout << endl;
	}
}



void ConsoleView::PrintResult(size_t s)
{
	cout << "\n""Your score: " << s << endl;
	cout << "\n""Esc to exit " ;
}



char ConsoleView::InterpretMap(AbstractGameObject * cell)
{
	if (cell == nullptr)
		return ' ';
	else if (typeid(*cell) == typeid(Border))
		return BORDER_SYMB;
	else if (typeid(*cell) == typeid(Python))
		return PYTHON_SYMB;
	else if (typeid(*cell) == typeid(Fruits))
		return FRUIT_SYMB;
	else if (typeid(*cell) == typeid(Poisons))
		return POISON_SYMB;
	else if (typeid(*cell) == typeid(Turns))
		return TURN_SYMB;
	else if (typeid(*cell) == typeid(SuperFruits))
		return SUPER_FRUIT_SYMB;


	return '!';
}


