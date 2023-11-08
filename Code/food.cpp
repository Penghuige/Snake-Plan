#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "food.h"
#include "controller.h"

/**
* 食物的初始化函数
*/
Food::Food()
{
	Food::setFood();
}

/**
* 打印食物函数
*/
void Food::PrintFood()
{
	Controller::gotoxy(Food::food.getX(), Food::food.getY());
	std::cout << "★";
}

/**
* 食物的制造函数
*/
void Food::setFood()
{
	srand((unsigned)time(NULL));
	int x = rand() % (2 * COL - 2) + 2;
	int y = rand() % (2 * ROW - 2) + 2;
	food = Point(x / 2 * 2, y / 2 * 2);
}

/**
* 获取食物位置函数
*/
Point Food::getFood()
{
	return food;
}


/**
* 食物的析构函数
*/
Food::~Food()
{
}


