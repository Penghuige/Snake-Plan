#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "food.h"
#include "controller.h"

/**
* ʳ��ĳ�ʼ������
*/
Food::Food()
{
	Food::setFood();
}

/**
* ��ӡʳ�ﺯ��
*/
void Food::PrintFood()
{
	Controller::gotoxy(Food::food.getX(), Food::food.getY());
	std::cout << "��";
}

/**
* ʳ������캯��
*/
void Food::setFood()
{
	srand((unsigned)time(NULL));
	int x = rand() % (2 * COL - 2) + 2;
	int y = rand() % (2 * ROW - 2) + 2;
	food = Point(x / 2 * 2, y / 2 * 2);
}

/**
* ��ȡʳ��λ�ú���
*/
Point Food::getFood()
{
	return food;
}


/**
* ʳ�����������
*/
Food::~Food()
{
}


