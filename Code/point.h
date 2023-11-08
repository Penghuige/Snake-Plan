#pragma once
#ifndef _POINT_H_
#define _POINT_H_

#include "virables.h"

/**
* 游戏内的显示格式 x  y
* 蛇 食物 墙
*/
class Point
{
public:
	Point() {}
	Point(int x, int y) { this->x = x; this->y = y; }
	Point(double x, double y) { this->x = (int)x; this->y = (int)y; }
	int getX(void) { return x; }
	int getY(void) { return y; }
	void operator()(int x, int y) { this->x = x; this->y = y; }
	void operator()(Point p) { this->x = p.x; this->y = p.y; }
	void operator=(Point p) { this->x = p.x; this->y = p.y; }
	bool operator==(Point p) { return this->x == p.x && this->y == p.y; }
	bool operator!=(Point p) { return this->x != p.x || this->y != p.y; }
	~Point() {}
private:
	int x;
	int y;
	/*int type;*/
};

#endif // !_POINT_H_