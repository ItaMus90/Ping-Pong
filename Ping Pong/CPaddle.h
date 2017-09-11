#include <iostream>

using namespace std;

class CPaddle
{
public:
	CPaddle() { cordX = cordY = 0; }
	CPaddle(int posX, int posY) : CPaddle()
	{
			originalX = posX;
			originalY = posY;
			cordX = posX;
			cordY = posY;
	}
	void reset();
	void moveUp();
	void moveDown();
	int getCordX();
	int getCordY();
	friend ostream & operator<<(ostream& o, CPaddle paddle)
	{
		o << "Paddle [" << paddle.cordX << "," << paddle.cordY << "]" << endl;
		return o;
	}
private:
	int cordX, cordY;
	int originalX, originalY;
};
 