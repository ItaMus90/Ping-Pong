#include "CBall.h"

int main()
{
	CBall ball(0, 0);
	cout << ball << endl;
	ball.randomDirection();
	cout << ball << endl;
	ball.move();
	cout << ball << endl;
	ball.randomDirection();
	ball.move();
	cout << ball << endl;
	ball.randomDirection();
	ball.move();
	cout << ball << endl;

	system("pause");
	return 0;
}