#include "CGameManager.h"

CGameManager::CGameManager(int h, int w)
{
	srand(time(NULL));
	quit = false;
	up1 = 'w';
	up2 = 'i';
	down1 = 's';
	down2 = 'k';
	score1 = score2 = 0;
	width = w;
	height = h;
	ball = new CBall(w / 4, h / 4);
	player1 = new CPaddle(1, h / 3 - 3);
	player2 = new CPaddle(w - 2, h / 3 - 3);
}

CGameManager::~CGameManager()
{
	delete ball, player1, player2;
}

void CGameManager::scoreUp(CPaddle* player)
{
	if (player == player1)
	{
		score1++;
	}
	else if (player == player2)
	{
		score2++;
	}

	ball->reset();
	player1->reset();
	player2->reset();
}

void CGameManager::draw()
{
	system("cls");

	for (int i = 0; i < width + 2; i++)
	{
		cout << "\xB2";
	}
	cout << endl;

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			int ballX = ball->getCordX();
			int ballY = ball->getCordY();

			int player1X = player1->getCordX();
			int player2X = player2->getCordX();
			int player1Y = player1->getCordY();
			int player2Y = player2->getCordY();

			if (j == 0)
			{
				cout << "\xB2";
			}

			if (ballX == j && ballY == i)
			{
				cout << "O";//ball
			}
			else if (player1X == j && player1Y == i)
			{
				cout << "\xDB";//player 1
			}
			else if (player2X == j && player2Y == i)
			{
				cout << "\xDB";//player 2
			}
			else if (player1X == j && player1Y + 1 == i)
			{
				cout << "\xDB";//player 1
			}
			else if (player1X == j && player1Y + 2 == i)
			{
				cout << "\xDB";//player 1
			}
			else if (player1X == j && player1Y + 2 == i)
			{
				cout << "\xDB";//player 1
			}
			else if (player2X == j && player2Y + 1 == i)
			{
				cout << "\xDB";//player 1
			}
			else if (player2X == j && player2Y + 2 == i)
			{
				cout << "\xDB";//player 1
			}
			else if (player2X == j && player2Y + 2 == i)
			{
				cout << "\xDB";//player 1
			}
			else
			{
				cout << " ";
			}

			if (j == width - 1)
			{
				cout << "\xB2";
			}
		}
		cout << endl;
	}	

	for (int i = 0; i < width + 2; i++)
	{
		cout << "\xB2";
	}

	cout << endl;
	cout << "Score 1: " << score1 << endl;
	cout << "Score 2: " << score2 << endl;
	cout << endl;
}

void CGameManager::input()
{
	ball->move();

	int ballX = ball->getCordX();
	int ballY = ball->getCordY();

	int player1X = player1->getCordX();
	int player2X = player2->getCordX();
	int player1Y = player1->getCordY();
	int player2Y = player2->getCordY();

	if (_kbhit)
	{
		char current = _getch();
		if (current == up1)
		{
			if (player1Y > 0)
			{
				player1->moveUp();
			}
		}
		if (current == up2)
		{
			if (player2Y > 0)
			{
				player2->moveUp();
			}
		}
		if (current == down1)
		{
			if (player1Y + 4 < height)
			{
				player1->moveDown();
			}
		}
		if (current == down2)
		{
			if (player2Y + 4 < height)
			{
				player2->moveDown();
			}
		}

		if (ball->getDirection() == STOP)
		{
			ball->randomDirection();
		}

		if (current == 'q')
		{
			quit = true;	 
		}
	}
}

void CGameManager::logic()
{
	int ballX = ball->getCordX();
	int ballY = ball->getCordY();

	int player1X = player1->getCordX();
	int player2X = player2->getCordX();
	int player1Y = player1->getCordY();
	int player2Y = player2->getCordY();

	//Left paddle
	for (int i = 0; i < 4; i++)
	{
		if (ballX == player1X + 1)
		{
			if (ballY == player1Y + 1)
			{
				ball->changeDirection((eDir)((rand() % 3) + 4));
			}
		}
	}

	//Right paddle
	for (int i = 0; i < 4; i++)
	{
		if (ballX == player2X - 1)
		{
			if (ballY == player2Y + 1)
			{
				ball->changeDirection((eDir)((rand() % 3) + 1));
			}
		}
	}

	//Bottom wall
	if (ballY == height - 1)
	{
		ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
	}

	//Top wall
	if (ballY == 0)
	{
		ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT: DOWNLEFT);
	}

	//Right wall
	if (ballX == width - 1)
	{
		scoreUp(player1);
	}

	//Left wall
	if (ballX == 0)
	{
		scoreUp(player2);
	}
}

void CGameManager::run()
{
	while (!quit)
	{
		draw();
		input();
		logic();
	}
}

