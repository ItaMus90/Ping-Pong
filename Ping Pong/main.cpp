#include "CBall.h"
#include "CPaddle.h"


int main()
{
	CBall ball(0, 0);
	CPaddle paddle(0, 0);
	CPaddle paddle2(10, 0);

	cout << paddle << endl;
	cout << paddle2 << endl;

	paddle.moveUp();
	paddle2.moveDown();

	cout << paddle << endl;
	cout << paddle2 << endl;

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