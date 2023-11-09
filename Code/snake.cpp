#include <iostream>
#include "food.h"
#include "map.h"
#include "snake.h"
#include "controller.h"
#include <conio.h>
#include <Windows.h>

/**
* �ߵĳ�ʼ�����캯��
* ��ʼ���ߵ�λ�ã��ٶȣ�����
* Ĭ�ϳ���ΪSNAKE_LEN��������virables.h���޸�
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
* �ߵĸı䷽����
* ͨ���ж�
*/
bool Snake::changeDirection()
{
	char ch;
	if (_kbhit())//kbhit��������ֵΪ��������ע��
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
				if (direction != Direction::DOWN)//��������뵱ǰ�˶������෴����Ч
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
* �ߵ��ƶ�����
* ͨ����������е�����Ͳ���ʵ���ߵ��ƶ�
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
* ��ӡ�ߺ���
* ͨ����������еı���ʵ��
*/
void Snake::PrintSnake()
{
	// ��ͷ�����ƶ�
	snake.push_front(head);
	// ɾ��β��
	if (!snake.empty())
	{
		auto p = snake.end();
		p--;
		Controller::gotoxy(p->getX(), p->getY());
		// һ������ռ�����ո�
		std::cout << "  ";
		snake.pop_back();
	}
	Sleep(SLEEP_TIME / speed);
	for (auto& it : Snake::snake)
	{
		Controller::gotoxy(it.getX(), it.getY());
		std::cout << "��";
	}
}

/**
* �ߵ������жϺ���
* ͨ���ж���ͷ�Ƿ��������غ�ʵ��
* �Լ��ж���ͷ�Ƿ���ǽ�غ�ʵ��
*/
bool Snake::isDead(Map& m)
{
	/*
	����ǽ��仯
	*/
	if (invincible)
	{
		// ˵�������޵�ʱ�䣬��Ҫ����ǽ��
		if (head.getX() == 0)
		{
			// ˵����ͷ����ǽ
			head = Point(2 * COL - 2, head.getY());
			return false;
		}
		else if (head.getX() == 2 * COL)
		{
			// ˵����ͷ����ǽ
			head = Point(2, head.getY());
			return false;
		}
		else if (head.getY() == 0)
		{
			//˵����ͷ����ǽ
			head = Point(head.getX(), 2 * ROW - 1);
			return false;
		}
		else if (head.getY() == 2 * ROW)
		{
			// ˵����ͷ����ǽ
			head = Point(head.getX(), 1);
			return false;
		}
		// ����ǽ ֱ�ӳԵ�����
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
* �ߵĳ�ʳ�ﺯ��
* ���Ե�ʳ��ʱ�������ȼ�һ
* speed���� ��ѡ
*/
void Snake::EatFood(Food& f)
{
	score += SCORE_ACCERELATION;
	/*����Ե���ʳ���Ǽ���ʳ�� ����ٶȼӳ�*/
	if (f.mode == HASTEN_FOOD)
	{
		/*����仯���ܻ�����ԭ�ٶ�1.5��ǰѸ���������������������������Ż�*/
		if (speed < SPEED_RANGE_LIMIT * SNAKE_SPEED) speed += SNAKE_ACCELERATION;
		else speed += SNAKE_ACCELERATION / 10;
	}
	else if (f.mode == POWER_FOOD)
	{
		/*�޵�ʳ��Ե�����POWER_TIME���޵�*/
		invincible = true;
		invincibleTime = POWER_TIME;
	}

	Controller::gotoxy(f.getX(), f.getY());
	// һ������ռ�����ո�
	std::cout << "  ";
	snake.push_back(f);
	// if(f.mode == STANDARD_FOOD) f.SetStandardFood();
}

/**
* �ߵ���������
*/
Snake::~Snake()
{
}

void Snake::PrintScore()
{
	Controller::gotoxy(2, 2 * ROW + 1);
	std::cout << "��ǰ�÷֣�" << score;
}
