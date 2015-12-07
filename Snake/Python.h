#ifndef Python_h__
#define Python_h__


class Python
{
public:
	Python();
	void draw();
	void virtualMove();
	void up();
	void right();
	void down();
	void left();
	bool selfeating();
	size_t x = 15, y = 15;
private:
	int dx = 0, dy = 1;
};




#endif // Python_h__
