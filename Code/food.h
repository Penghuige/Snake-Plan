#pragma once
#ifndef _FOOD_H_
#define _FOOD_H_

#include "virables.h"
#include "point.h"
#include <vector>

class Food: public Point{
public:
	Food();
	void PrintFood();
	Food SetStandardFood();
	std::vector<Food> SetStandardFood(int a);
	Point GetFood();
	Food SetPowerFood();
	Food SetHastenFood();
	Food RandomFood();
	void MoveFood();
	~Food();
	int mode = STANDARD_MODE;	//ģʽ
	int num = STANDARD_FOOD;	//����ģʽר��
private:
	Point food;
};

#endif // !_FOOD_H_