#include "map.h"
#include "virables.h"
#include <iostream>
#include "controller.h"
#include <random>
#include <fstream>
#include <sstream>

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
	std::uniform_int_distribution<int> u(0, std::max(2 * ROW, 2 * COL)); // 左闭右闭区间
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

/**
* 生成地图与加载地图函数
*/
void Map::GenerateMap(int width, int height, int pointCount, const std::string& filename)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distribX(0, width - 1);
	std::uniform_int_distribution<int> distribY(0, height - 1);

	std::ofstream file(filename);
	if (!file.is_open()) {
		std::cout << "Failed to open file: " << filename << std::endl;
		return;
	}

	for (int i = 0; i < pointCount; ++i) {
		int x = distribX(gen);
		int y = distribY(gen);
		file << x << "," << y << std::endl;
	}

	file.close();
	std::cout << "Map generated successfully: " << filename << std::endl;
}


bool Map::LoadMap(int x)
{
	std::string filename = "./maps/map" + std::to_string(x) + ".txt"; // 根据地图编号生成文件名
	std::ifstream file(filename);
	if (!file.is_open()) {
		// 文件打开失败
		std::cout << "Open file " << filename << " failed." << std::endl;
		return false;
	}

	std::vector<Point> m;
	std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string coordinate;
		while (std::getline(ss, coordinate, ',')) {
			int x = std::stoi(coordinate);
			std::getline(ss, coordinate, ',');
			int y = std::stoi(coordinate);
			Point p(x, y);
			m.push_back(p);
		}
	}

	for (auto& p : m)
	{
		walls.emplace_back(p);
	}
	return true;
}

