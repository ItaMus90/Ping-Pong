#include <iostream>

using namespace std;

class CPaddle
{
public:
	CPaddle();
	CPaddle(int, int);
	inline void reset();
	void moveUp();
	void moveDown();
	inline int getCordX();
	inline int getCordY();
	friend ostream & operator<<(ostream& o, CPaddle paddle)
	{
		o << "Paddle [" << paddle.cordX << "," << paddle.cordY << "]" << endl;
		return o;
	}
private:
	int cordX, cordY;
	int originalX, originalY;
};
 