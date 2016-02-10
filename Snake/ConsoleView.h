#ifndef ConsoleView_h__
#define ConsoleView_h__

#include "AbstractView.h"

#include "AbstractGameObject.h"



class ConsoleView : public AbstractView
{
public:
	virtual void DrawSprite(const Sprite &, size_t, size_t) { };
	virtual void DeleteSprite(size_t, size_t) { };
	virtual void ClearField();
	virtual void Redraw();
	virtual void PrintResult(size_t);
private:
	char InterpretMap(AbstractGameObject *);

};




#endif // ConsoleView_h__
