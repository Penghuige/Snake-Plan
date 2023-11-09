#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "food.h"
#include "controller.h"
#include <random>

/**
* 食物的初始化函数
*/
Food::Food()
{
	Food::SetStandardFood();
}

/**
* 打印食物函数
*/
void Food::PrintFood()
{
	Controller::gotoxy(Food::food.getX(), Food::food.getY());
	if (mode == STANDARD_FOOD) std::cout << "★";
	else if (mode == HASTEN_FOOD) std::cout << "☆";
	else if (mode == POWER_FOOD) std::cout << "◎";
}

/**
* 食物的制造函数
*/
Food Food::SetStandardFood()
{
	unsigned int s = (unsigned int)time(0);
	std::default_random_engine e;
	std::uniform_int_distribution<int> u(0, std::max(2 * ROW, 2 * COL)); // 左闭右闭区间
	e.seed(s);
	int x = u(e) % (2 * COL - 2) + 2;
	int y = u(e) % (2 * ROW - 2) + 2;
	food = Point(x / 2 * 2, y / 2 * 2);
	mode = STANDARD_FOOD;
	return *this;
}

/**
* 加速食物的制造函数
*/
Food Food::SetHastenFood()
{
	srand((unsigned)time(NULL));
	int x = rand() % (2 * COL - 2) + 2;
	int y = rand() % (2 * ROW - 2) + 2;
	mode = HASTEN_FOOD;
	food = Point(x / 2 * 2, y / 2 * 2);
	return *this;
}

/**
* 无敌食物的制造函数
*/
Food Food::SetPowerFood()
{
	srand((unsigned)time(NULL));
	int x = rand() % (2 * COL - 2) + 2;
	int y = rand() % (2 * ROW - 2) + 2;
	mode = POWER_FOOD;
	food = Point(x / 2 * 2, y / 2 * 2);
	return *this;
}

/**
* 随机生成道具的制造函数
*/
Food Food::RandomFood()
{
	int x = rand() % (2 * COL - 2) + 2;
	int y = rand() % (2 * ROW - 2) + 2;
	food = Point(x / 2 * 2, y / 2 * 2);
	int mode = rand() % GENER_FREQU;
	if (mode == 0) return Food::SetHastenFood();
	else if (mode == 1) return Food::SetPowerFood();
}

void Food::MoveFood()
{
	food.MovePoint();
}


/**
* 获取食物位置函数
*/
Point Food::GetFood()
{
	return food;
}


/**
* 食物的析构函数
*/
Food::~Food()
{
}


