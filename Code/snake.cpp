#include <iostream>
#include "food.h"
#include "map.h"
#include "snake.h"
#include "controller.h"
#include <conio.h>
#include <Windows.h>

/**
* 蛇的初始化构造函数
* 初始化蛇的位置，速度，方向
* 默认长度为SNAKE_LEN，可以在virables.h中修改
*/
Snake::Snake()
{
	head = Point(COL, ROW);
	snake.push_back(head);
	for (int i = 1; i <= SNAKE_LEN; i++)
	{
		Snake::snake.push_back(Point(COL, ROW - i));
	}
	direction = DOWN;
	speed = SNAKE_SPEED;
}

/**
* 蛇的改变方向函数
* 通过判断
*/
bool Snake::changeDirection()
{
	char ch;
	if (_kbhit())//kbhit函数返回值为两个，需注意
	{
		ch = _getch();
		switch (ch)
		{
		case 27://ESC
			return false;
		default:
			switch (ch)
			{
			case 'W':
			case 'w':
				if (direction != Direction::DOWN)//如果方向与当前运动方向相反，无效
					direction = Direction::UP;
				break;
			case 'S':
			case 's':
				if (direction != Direction::UP)
					direction = Direction::DOWN;
				break;
			case 'A':
			case 'a':
				if (direction != Direction::RIGHT)
					direction = Direction::LEFT;
				break;
			case 'D':
			case 'd':
				if (direction != Direction::LEFT)
					direction = Direction::RIGHT;
				break;
			default:
				break;
			}
			return true;
		}
	}
	return true;
}


/**
* 蛇的移动函数
* 通过对蛇身队列的输出和插入实现蛇的移动
*/
void Snake::move()
{
	switch (direction)
	{
	case LEFT:
		Snake::head = Point(Snake::head.getX() - 2, Snake::head.getY());
		break;
	case RIGHT:
		Snake::head = Point(Snake::head.getX() + 2, Snake::head.getY());
		break;
	case UP:
		Snake::head = Point(Snake::head.getX(), Snake::head.getY() - 1);
		break;
	case DOWN:
		Snake::head = Point(Snake::head.getX(), Snake::head.getY() + 1);
		break;
	default:
		break;
	}
}

/**
* 打印蛇函数
* 通过对蛇身队列的遍历实现
*/
void Snake::PrintSnake()
{
	// 往头方向移动
	snake.push_front(head);
	// 删除尾部
	if (!snake.empty())
	{
		auto p = snake.end();
		p--;
		Controller::gotoxy(p->getX(), p->getY());
		// 一个方块占两个空格
		std::cout << "  ";
		snake.pop_back();
	}
	Sleep(SLEEP_TIME / speed);
	for (auto& it : Snake::snake)
	{
		Controller::gotoxy(it.getX(), it.getY());
		std::cout << "■";
	}
}

/**
* 蛇的死亡判断函数
* 通过判断蛇头是否与蛇身重合实现
* 以及判断蛇头是否与墙重合实现
*/
bool Snake::isDead(Map& m)
{
	/*
	局内墙体变化
	*/
	if (invincible)
	{
		// 说明蛇是无敌时间，需要跳过墙体
		if (head.getX() == 0)
		{
			// 说明蛇头在左墙
			head = Point(2 * COL - 2, head.getY());
			return false;
		}
		else if (head.getX() == 2 * COL)
		{
			// 说明蛇头在右墙
			head = Point(2, head.getY());
			return false;
		}
		else if (head.getY() == 0)
		{
			//说明蛇头在上墙
			head = Point(head.getX(), 2 * ROW - 1);
			return false;
		}
		else if (head.getY() == 2 * ROW)
		{
			// 说明蛇头在下墙
			head = Point(head.getX(), 1);
			return false;
		}
		// 其他墙 直接吃掉即可
	}
	for (auto it = m.walls.begin(); it != m.walls.end(); it++)
	{
		if (head == *it)
		{
			if (invincible)
			{
				m.walls.erase(it);
				return false;
			}
			else return true;
		}
	}
	if (invincible) return false;
	for (auto it = snake.begin() + 1; it != snake.end(); it++)
	{
		if (head == *it)
			return true;
	}
	return false;
}

/**
* 蛇的吃食物函数
* 当吃到食物时，蛇身长度加一
* speed加速 可选
*/
void Snake::EatFood(Food& f)
{
	score += SCORE_ACCERELATION;
	/*如果吃到的食物是加速食物 获得速度加成*/
	if (f.mode == HASTEN_FOOD)
	{
		/*输入变化智能化，在原速度1.5倍前迅速增长，后续缓慢增长，还需优化*/
		if (speed < SPEED_RANGE_LIMIT * SNAKE_SPEED) speed += SNAKE_ACCELERATION;
		else speed += SNAKE_ACCELERATION / 10;
	}
	else if (f.mode == POWER_FOOD)
	{
		/*无敌食物，吃到后获得POWER_TIME秒无敌*/
		invincible = true;
		invincibleTime = POWER_TIME;
	}

	Controller::gotoxy(f.getX(), f.getY());
	// 一个方块占两个空格
	std::cout << "  ";
	snake.push_back(f);
	// if(f.mode == STANDARD_FOOD) f.SetStandardFood();
}

/**
* 蛇的析构函数
*/
Snake::~Snake()
{
}

void Snake::PrintScore()
{
	Controller::gotoxy(2, 2 * ROW + 1);
	std::cout << "当前得分：" << score;
}
