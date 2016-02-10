#ifndef AbstractController_h__
#define AbstractController_h__



class AbstractController
{
public:
	virtual bool KeyHit() const = 0;
	virtual int GetCommand() const = 0;
};





#endif // AbstractController_h__
