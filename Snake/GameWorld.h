#ifndef GameWorld_h__
#define GameWorld_h__

class GameWorld
{
public:
	GameWorld();
	~GameWorld();
	GameWorld & operator<< (int);             // keyboard stream reading
	bool operator() ();                       // Game step, returns false to exit program
private:
	bool State = true;                        // Python is alive 

};

class Border
{


};


class Python
{


};



#endif // GameWorld_h__
