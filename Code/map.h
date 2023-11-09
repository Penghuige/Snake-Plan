#pragma once
#ifndef _MAP_H_
#define _MAP_H_

#include "virables.h"
#include "point.h"
#include <vector>
#include <string>

class Map : public Point
{
public:
	/**
	* 默认构造函数
	* 将正方形各点压入initmap
	* 地图坐标从1开始 到COL和ROW结束
	*/
	Map(){
		for (int i = 0; i <= 2 * COL; i += 2)
		{
			/*initmap.emplace_back(Point(i, 0));*/
			walls.emplace_back(Point(i, 0));
		}
		for (int i = 1; i < 2 * ROW; i++)
		{
			/*initmap.emplace_back(Point(0, i));*/
			walls.emplace_back(Point(0, i));
			// 为了让地图看起来更好看，这里将地图的右边界向右移动了一格
			/*initmap.emplace_back(Point(2 * COL, i));*/
			walls.emplace_back(Point(2 * COL, i));
		}
		for (int i = 0; i <= 2 * COL; i += 2)
		{
			/*initmap.emplace_back(Point(i, 2 * ROW));*/
			walls.emplace_back(Point(i, 2 * ROW));
		}
	}
	bool AddWall(int x, int y);
	void PrintInitmap();//绘制初始地图
	void RandomBuild();// 随机生成墙体
	void GenerateMap(int width, int height, int pointCount, const std::string& filename);
	bool LoadMap(int x);//加载第x个地图
	std::vector<Point> walls;//新增障碍节点
private:
	std::vector<std::vector<Point> > maps;
	//std::vector<Point> initmap;//保存初始地图 已经被walls淘汰
};

#endif // !_MAP_H_