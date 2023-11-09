#pragma once
#ifndef _SNAKE_H_
#define _SNAKE_H_

#include "virables.h"
#include "point.h"
#include "food.h"
#include "map.h"
#include <deque>

//��ͷ1,2
class Snake: public Point
{
public:
	enum Direction { UP, DOWN, LEFT, RIGHT }; //ö�ٷ���
	Snake(); //���캯��
	void move(); //�ƶ�
	bool isDead(Map& m); //�ж��Ƿ�����
	bool changeDirection(); //�ı䷽��
	void EatFood(Food& f); //��ʳ��
	void PrintSnake(); //��ӡ��
	void PrintScore(); //��ӡ����
	Point getHead() { return head; } //��ȡ��ͷ
	int getScore() { return score; } //��ȡ����
	~Snake(); //��������
private:
	std::deque<Point> snake; //�������
	Direction direction; //��ͷ����
	Point head; //��ͷ
	int speed;
	int score;
	bool invincible = false; //���Ƿ��޵�
	int invincibleTime = 0; //�޵�ʱ��
};


#endif // !_SNAKE_H_

