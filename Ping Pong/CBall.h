#include <iostream>

using namespace std;

enum eDir
{
	STOP = 0,
	LEFT = 1,
	UPLEFT = 2,
	DOWNLEFT = 3,
	RIGHT = 4,
	UPRIGHT = 5,
	DOWNRIGHT = 6
};

class CBall
{
public:
	CBall(int, int);
	void reset();
	void changeDirection(eDir);
	void randomDirection();
	void move();
	inline int getCordX();
	inline int getCordY();
	inline eDir getDirection();

	friend ostream & operator<<(ostream& o, CBall ball)
	{
		o << "Ball [" << ball.cordX << "," << ball.cordY << "][" << ball.direction << "]" << endl;
		return o;
	}
private:
	int cordX, cordY;
	int originalX, originalY;
	eDir direction;
};
