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
	int mode = STANDARD_MODE;	//ģʽ
	int num = STANDARD_FOOD;	//����ģʽר��
private:
	Point food;
};

#endif // !_FOOD_H_