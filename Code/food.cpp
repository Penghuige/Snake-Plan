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
	Food::SetStandardFood();
}

/**
* ��ӡʳ�ﺯ��
*/
void Food::PrintFood()
{
	Controller::gotoxy(Food::food.getX(), Food::food.getY());
	if(mode == STANDARD_FOOD) std::cout << "��";
	else if(mode == HASTEN_FOOD) std::cout << "��";
	else if(mode == POWER_FOOD) std::cout << "��";
}

/**
* ʳ������캯��
*/
void Food::SetStandardFood()
{
	srand((unsigned)time(NULL));
	int x = rand() % (2 * COL - 2) + 2;
	int y = rand() % (2 * ROW - 2) + 2;
	food = Point(x / 2 * 2, y / 2 * 2);
	mode = STANDARD_FOOD;
}

/**
* ����ʳ������캯��
*/
void Food::SetHastenFood()
{
	srand((unsigned)time(NULL));
	int x = rand() % (2 * COL - 2) + 2;
	int y = rand() % (2 * ROW - 2) + 2;
	mode = HASTEN_FOOD;
	food = Point(x / 2 * 2, y / 2 * 2);
}

/**
* �޵�ʳ������캯��
*/
void Food::SetPowerFood()
{
	srand((unsigned)time(NULL));
	int x = rand() % (2 * COL - 2) + 2;
	int y = rand() % (2 * ROW - 2) + 2;
	mode = POWER_FOOD;
	food = Point(x / 2 * 2, y / 2 * 2);
}

/**
* ������ɵ��ߵ����캯��
*/
void Food::RandomFood()
{
	int x = rand() % (2 * COL - 2) + 2;
	int y = rand() % (2 * ROW - 2) + 2;
	food = Point(x / 2 * 2, y / 2 * 2);
	int mode = rand() % GENER_FREQU;
	if(mode == 0) Food::SetHastenFood();
	else if(mode == 1) Food::SetPowerFood();
}

/**
* ��ȡʳ��λ�ú���
*/
Point Food::GetFood()
{
	return food;
}


/**
* ʳ�����������
*/
Food::~Food()
{
}


