#include <iostream>
#include <time.h>
#include <conio.h>
#include "CBall.h"
#include "CPaddle.h"

using namespace std;

class CGameManager
{
private:
	int width, height;
	int score1, score2;
	char up1, down1, up2, down2;
	bool quit;
	CBall* ball;
	CPaddle * player1;
	CPaddle * player2;
public:
	CGameManager(int, int);
	~CGameManager();
	void scoreUp(CPaddle * player);
	void draw();
	void input();
	void logic();
	void run();	
};


