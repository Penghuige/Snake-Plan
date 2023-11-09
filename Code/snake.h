#pragma once
#ifndef _SNAKE_H_
#define _SNAKE_H_

#include "virables.h"
#include "point.h"
#include "food.h"
#include "map.h"
#include <deque>

//蛇头1,2
class Snake: public Point
{
public:
	enum Direction { UP, DOWN, LEFT, RIGHT }; //枚举方向
	Snake(); //构造函数
	void move(); //移动
	bool isDead(Map& m); //判断是否死亡
	bool changeDirection(); //改变方向
	void EatFood(Food& f); //吃食物
	void PrintSnake(); //打印蛇
	void PrintScore(); //打印分数
	Point getHead() { return head; } //获取蛇头
	int getScore() { return score; } //获取分数
	~Snake(); //析构函数
private:
	std::deque<Point> snake; //蛇身队列
	Direction direction; //蛇头方向
	Point head; //蛇头
	int speed;
	int score;
	bool invincible = false; //蛇是否无敌
	int invincibleTime = 0; //无敌时间
};


#endif // !_SNAKE_H_

