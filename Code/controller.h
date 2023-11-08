#pragma once
#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "snake.h"
#include "food.h"

class Controller
{
public:
	//��Ϸ��;��ͣ����
	void PauseView();
	//�޸ķ�����
	void updateDir();
	// ���˵�
	void gameMenu();
	// ��Ϸģʽѡ��
	void gamemodeView();
	// ���ý���
	void gameFit();
	// ��Ϸ˵��
	void gameText();
	// ������
	void gameProductionTeamText();
	// ��Ϸ����
	void gameStart();
	// ��Ϸ����
	int gameRunning(Snake& s1, Food& food);
	//��Ϸ����
	void gameendView(Snake& s);
	// ������Ļ
	void ClearScreen();
	//���ļ���ȡ��߷�
	int ReadGrade();
	//������߷ֵ��ļ�
	void WriteGrade();
	// ����ƶ�
	static void gotoxy(int x, int y);
private:
	int max_score = 0;
};


#endif // !_CONTROLLER_H_

