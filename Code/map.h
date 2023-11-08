#pragma once
#ifndef _MAP_H_
#define _MAP_H_

#include "virables.h"
#include "point.h"
#include "wall.h"
#include <vector>


class Map : public Point
{
public:
	/**
	* Ĭ�Ϲ��캯��
	* �������θ���ѹ��initmap
	* ��ͼ�����1��ʼ ��COL��ROW����
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
			// Ϊ���õ�ͼ���������ÿ������ｫ��ͼ���ұ߽������ƶ���һ��
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
	void PrintInitmap();//���Ƴ�ʼ��ͼ
	void RandomBuild();// �������ǽ��
	std::vector<Point> walls;//�����ϰ��ڵ�
private:
	//std::vector<Point> initmap;//�����ʼ��ͼ �Ѿ���walls��̭
	/*Map����Զ�����ֵ�ͼ��ֻ�轫��ʾ��ͼ�ĸ����㱣������Ӧ��map�У�����Snake����������Ӧ�ж�ײǽ��������
	std::vector<Point> map1;
	std::vector<Point> map2;
	*/
};

#endif // !_MAP_H_