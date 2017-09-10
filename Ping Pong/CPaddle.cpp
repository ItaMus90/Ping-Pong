#include "CPaddle.h"

CPaddle::CPaddle()
{
	cordX = cordY = 0;
}

//The colon after the constucor mean it initlize befor the execute 
CPaddle::CPaddle(int posX, int posY) : CPaddle()
{
	originalX = posX;
	originalY = posY;
	cordX = posX;
	cordY = posY;
}

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