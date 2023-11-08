#include "map.h"
#include "virables.h"
#include <iostream>
#include "controller.h"
#include <random>

bool Map::AddWall(int x, int y)
{
	/*防止无效数据*/
	if (x > 2 * COL || y > 2 * ROW || x < 0 || y < 0) return false;
	Point wall(x, y);
	walls.emplace_back(wall);
	return true;
}

void Map::PrintInitmap()
{
	for (auto& p : walls)
	{
		Controller::gotoxy(p.getX(), p.getY());
		std::cout << "■";
	}
}

/**
* 随机生成墙体函数 这里使用C++11 uniform_int_distribution 较均匀生成墙体
* 蛇头默认在(COL, ROW) 需要避开
*/
void Map::RandomBuild()
{
	int a = WALL_NUM;
	std::default_random_engine e;
	std::uniform_int_distribution<int> u(0, std::max(2*ROW, 2 * COL)); // 左闭右闭区间
	e.seed(time(0));
	while (a--)
	{
		int x = u(e) % (2 * COL - 2) + 2;
		int y = u(e) % (2 * ROW - 2) + 2;
		Point p(x / 2 * 2, y / 2 * 2);
		if (p.Nearby(COL, ROW)) continue;
		walls.emplace_back(p);
	}
}
