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
	void GameStart(int mode);
	// ��Ϸ����
	int gameRunning(Snake& s1, Map& m, int mode);
	//��Ϸ����
	void gameendView(Snake& s);
	// ������Ļ
	void ClearScreen();
	//���ļ���ȡ��߷�
	int ReadGrade();
	//������߷ֵ��ļ�
	void WriteGrade();
	// �趨����̨�����ʼ�趨
	bool SetSize(int width, int height);
	// ����ƶ�
	static void gotoxy(int x, int y);
private:
	int max_score = 0;
	// ����ĳ�Ա�����ж�����һ����������ʳ���ʱ��
	time_t lastFoodTime = 0;
};


#endif // !_CONTROLLER_H_

