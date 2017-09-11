#include "CPaddle.h"


int CPaddle::getCordX()
{
	return cordX;
}

int CPaddle::getCordY()
{
	return cordY;
}

void CPaddle::moveDown()
{
	cordY++;
}

void CPaddle::moveUp()
{
	cordY--;
}

void CPaddle::reset()
{
	cordX = originalX;
	cordY = originalY;
}