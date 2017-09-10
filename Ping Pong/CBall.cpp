#include "CBall.h"

using namespace std;

CBall::CBall(int posX, int posY)
{
	originalX = posX;
	originalY = posY;
	cordX = posX;
	cordY = posY;
	direction = STOP;
}

void CBall::reset()
{
	cordX = originalX;
	cordY  = originalY;
	direction = STOP;
}

void CBall::changeDirection(eDir curDir)
{
	direction = curDir;
}

void CBall::randomDirection()
{
	direction = (eDir)((rand() % 6) + 1);
}

void CBall::move()
{
	switch (direction)
	{
	case STOP:
		break;
	case LEFT:
		cordX--;
		break;
	case RIGHT:
		cordX++;
		break;
	case UPLEFT:
		cordX--;
		cordY--;
		break;
	case DOWNLEFT:
		cordX--;
		cordY++;
		break;
	case UPRIGHT:
		cordX++;
		cordY--;
		break;
	case DOWNRIGHT:
		cordX++;
		cordY++;
		break;
	default:
		break;
	}
}

int CBall::getCordX()
{
	return cordX;
}

int CBall::getCordY()
{
	return cordY;
}

eDir CBall::getDirection()
{
	return direction;
}





