#pragma once
#ifndef _FOOD_H_
#define _FOOD_H_

#include "virables.h"
#include "point.h"

class Food:public Point{
public:
	Food();
	void PrintFood();
	void setFood();
	Point getFood();
	~Food();
	int mode = STANDARD_MODE;	//模式
	int num = STANDARD_FOOD;	//闯关模式专属
private:
	Point food;
};

#endif // !_FOOD_H_