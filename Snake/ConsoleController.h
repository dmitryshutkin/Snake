#ifndef ConsoleController_h__
#define ConsoleController_h__

#include "AbstractController.h"



class ConsoleController : public AbstractController
{
public:
	virtual bool KeyHit() const;
	virtual int GetCommand() const;
};




#endif // ConsoleController_h__
