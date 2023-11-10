#define _CRT_SECURE_NO_WARNINGS //ȡ��scanf����ֵ�ľ���
#include <iostream>
#include <stdbool.h>
#include <windows.h>
#include <conio.h> /*���������ȡ*/
#include "snake.h"
#include "map.h"
#include "controller.h"

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

//���ļ���ȡ��߷�
int Controller::ReadGrade()
{
	int ret;
	FILE* pf = fopen("Score.txt", "r"); //��ֻ���ķ�ʽ���ļ�
	if (pf == NULL) //���ļ�ʧ��
	{
		int a = 0;
		std::cout << "��ȡ��ߵ÷ּ�¼ʧ��\n";
		pf = fopen("Score.txt", "w"); //��ֻд�ķ�ʽ���ļ�
		fwrite(&a, sizeof(int), 1, pf); //��maxд���ļ�����ʱmaxΪ0����������ߵ÷ֳ�ʼ��Ϊ0
	}
	fseek(pf, 0, SEEK_SET); //ʹ�ļ�ָ��pfָ���ļ���ͷ
	fread(&ret, sizeof(int), 1, pf); //��ȡ�ļ����е���ߵ÷ֵ�max����
	fclose(pf); //�ر��ļ�
	pf = NULL; //�ļ�ָ�뼰ʱ�ÿ�

	return ret;
}

//������߷ֵ��ļ�
void Controller::WriteGrade()
{
	FILE* pf = fopen("Score.txt", "w"); //��ֻд�ķ�ʽ���ļ�
	if (pf == NULL) //���ļ�ʧ��
	{
		std::cout << "������ߵ÷ּ�¼ʧ��\n";
		exit(0);
	}
	fwrite(&max_score, sizeof(int), 1, pf); //��������Ϸ�÷�д���ļ�����
	fclose(pf); //�ر��ļ�
	pf = NULL; //�ļ�ָ�뼰ʱ�ÿ�
}

bool Controller::SetSize(int width, int height)
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ������
	SMALL_RECT wrt = { 0, 0, width - 1, height - 1 }; //���ÿ��
	bool ret = SetConsoleWindowInfo(hOutput, TRUE, &wrt); // ���ô���ߴ�
	SetConsoleTitleA("Snake Plan"); //����һ���±���
	if (!ret) return false;
	COORD coord = { width, height };
	ret = SetConsoleScreenBufferSize(hOutput, coord); // ���û���ߴ�
	return ret;
}

/**
* ����ƶ�����
* ������ƶ���x,y��λ��
*/
void Controller::gotoxy(int x, int y)
{
	COORD pos; //������λ�õĽṹ�����
	pos.X = x; //������
	pos.Y = y; //������
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ����̨���
	SetConsoleCursorPosition(handle, pos); //���ù��λ��
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
	CursorInfo.bVisible = false; //���ؿ���̨���
	SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬
}

// �������뺯��
void Controller::updateDir()
{

}

//2.���ո��ʱ��������ͣ����, ����Ҳ�ǿ��
int Controller::PauseView()
{
	int cur = 0;
	while (1)
	{
		int gameMenu_flag = 1;
		system("cls");
		gotoxy(COL - 4, ROW / 2 + 2);
		printf("%s������Ϸ", cur == 0 ? "==>" : "");
		gotoxy(COL - 4, ROW / 2 + 4);
		printf("%s����", cur == 1 ? "==>" : "");
		gotoxy(COL - 4, ROW / 2 + 6);
		printf("%s���ز˵�����", cur == 2 ? "==>" : "");
		gotoxy(COL - 4, ROW / 2 + 8);
		printf("%s�˳���Ϸ", cur == 3 ? "==>" : "");

		switch (_getch())
		{
		case 'w':
		case 'W':
			if (--cur < 0)
			{
				cur = 0;
			}
			break;
		case 's':
		case 'S':
			if (++cur > 3)
			{
				cur = 3;
			}
			break;
		case '\r':
			switch (cur)
			{
			case 0:		// ������Ϸ
				ClearScreen();
				return GAME_RUNNING;
				break;
			case 1:		// ����
				gameFit();
				break;
			case 2:		// ���ز˵�
				return GAME_BREAK;
				break;
			case 3:		// �˳���Ϸ
				return GAME_OVER;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		if (gameMenu_flag == 0)
		{
			break;
		}
	}
	return GAME_RUNNING;
}

/**
* ��Ϸʤ������
* �����Ƿ������Ϸ
*/
int Controller::VictoryView()
{
	ClearScreen();
	int cur = 0;
	while (1)
	{
		gotoxy(COL - 4, ROW / 2);
		std::cout << "YOU WIN";
		gotoxy(COL - 6, ROW / 2 + 2);
		std::cout << "�Ƿ������Ϸ";
		gotoxy(COL - 4, ROW / 2 + 4);
		std::cout << ((cur == 0) ? "==> Yes" : "Yes   ");
		gotoxy(COL - 4, ROW / 2 + 6);
		std::cout << ((cur == 1) ? "==> No" : "No     ");
		switch (_getch())
		{
		case 'w':
		case 'W':
			if (--cur < 0)
			{
				cur = 0;
			}
			break;
		case 's':
		case 'S':
			if (++cur > 1)
			{
				cur = 1;
			}
			break;
		case '\r':
			switch (cur)
			{
			case 0:		// ������Ϸ
				return GAME_RESTART;
				break;
			case 1:		// �˳���Ϸ
				return GAME_OVER;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}

	}
}

/**
* ��Ϸʧ�ܽ���
* �����Ƿ������Ϸ
*/
int Controller::LoseView()
{
	ClearScreen();
	int cur = 0;
	while (1)
	{
		gotoxy(COL - 4, ROW / 2);
		std::cout << "YOU LOSE";
		gotoxy(COL - 8, ROW / 2 + 2);
		std::cout << "�Ƿ������Ϸ";
		gotoxy(COL - 4, ROW / 2 + 4);
		std::cout << ((cur == 0) ? "==> Yes" : "Yes     ");
		gotoxy(COL - 4, ROW / 2 + 6);
		std::cout << ((cur == 1) ? "==> No" : "No      ");
		switch (_getch())
		{
		case 'w':
		case 'W':
			if (--cur < 0)
			{
				cur = 0;
			}
			break;
		case 's':
		case 'S':
			if (++cur > 1)
			{
				cur = 1;
			}
			break;
		case '\r':
			switch (cur)
			{
			case 0:		// ������Ϸ
				return GAME_RESTART;
				break;
			case 1:		// �˳���Ϸ
				return GAME_OVER;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}

	}
}

/**
* ��ӡ����Ϸ��������˵���ͨ��_getch()�������������ָ�ͨ��
* while�������޸�cur��ֵ�ټ���if�ж���ʵ��-->��<--����ת��ʾ
* ���gameMenu_flag����Ϊ��ʶ������ѡ������رոý��档
*/
int Controller::gameMenu()
{
	int cur = 0;
	while (1)
	{
		int gameMenu_flag = 1;
		system("cls");
		gotoxy(COL - 4, ROW / 2);
		printf("���˵�\n");
		gotoxy(COL - 4, ROW / 2 + 2);
		printf("%s��ʼ��Ϸ", cur == 0 ? "==>" : "");
		gotoxy(COL - 4, ROW / 2 + 4);
		printf("%s����", cur == 1 ? "==>" : "");
		gotoxy(COL - 4, ROW / 2 + 6);
		printf("%s��Ϸ˵��", cur == 2 ? "==>" : "");
		gotoxy(COL - 4, ROW / 2 + 8);
		printf("%s�˳���Ϸ", cur == 3 ? "==>" : "");
		//gotoxy(COL - 4, ROW / 2 + 10);
		//printf("%s������", cur == 4 ? "==>" : "");

		switch (_getch())
		{
		case 'w':
		case 'W':
			if (--cur < 0)
			{
				cur = 0;
			}
			break;
		case 's':
		case 'S':
			if (++cur > 3)
			{
				cur = 3;
			}
			break;
		case '\r':
			switch (cur)
			{
			case 0:		// ��ʼ��Ϸ
				gameMenu_flag = gamemodeView();
				if (gameMenu_flag == GAME_RESTART) gameMenu_flag = gamemodeView();
				break;
			case 1:		// ����
				gameFit();

				break;
			case 2:		// ��Ϸ˵��
				gameText();

				break;
			case 3:		// �˳���Ϸ
				gameMenu_flag = 0;
				break;
			case 4:		// ������
				gameProductionTeamText();

				break;
			default:
				gameMenu_flag = 0;
				break;
			}
			break;
		default:
			break;
		}
		if (!gameMenu_flag) return 0;
	}
}


// ��Ϸģʽѡ��
int Controller::gamemodeView(void)
{
	int cur = 0;

	while (1)
	{
		int gamemodeView_flag = 1;  //��������ѭ��
		system("cls");
		gotoxy(COL - 4, ROW / 2);
		printf("��Ϸģʽ\n");
		gotoxy(COL - 4, ROW / 2 + 2);
		printf("%s����ģʽ\n", cur == 0 ? "==>" : "");
		gotoxy(COL - 4, ROW / 2 + 4);
		printf("%sð��ģʽ\n", cur == 1 ? "==>" : "");
		gotoxy(COL - 4, ROW / 2 + 6);
		printf("%s����ģʽ\n", cur == 2 ? "==>" : "");
		gotoxy(COL - 4, ROW / 2 + 8);
		printf("%s˫��ģʽ\n", cur == 3 ? "==>" : "");

		switch (_getch())
		{
		case 'w':
		case 'W':
			if (--cur < 0)
			{
				cur = 0;
			}
			break;
		case 's':
		case 'S':
			if (++cur > 3)
			{
				cur = 3;
			}
			break;
		case '\r':
			switch (cur)
			{
			case 0:		// ����ģʽ
				system("cls");
				return GameStart(CLASSIC_MODE);
				//gamemodeView_flag = 0;
				break;
			case 1:		// ð��ģʽ
				system("cls");
				return GameStart(ADVENTURE_MODE);
				//gamemodeView_flag = 0;
				break;
			case 2:		// ����ģʽ -- �ض���ͼ �޶�ʳ��
				system("cls");
				return GameStart(LEVEL_MODE);
				break;
			case 3:
				system("cls");
				return GameStart(DUO_MODE);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

// ��Ϸ˵��
void Controller::gameText(void)
{
	system("cls");
	printf("*Snake Plan��Ϊ����ģʽ�Ͷ�սģʽ��\n");
	printf("  \n");
	printf("*����ģʽ��W��A��S��D�������ߵ��ƶ����Ե�ʳ����ߵĳ������ӣ�ײ�������ǽ������Ϸ������\n");
	printf("  \n");
	printf("*��սģʽ��λ��ҷֱ���W��A��S��D/I��J��K��L�����ߵ��ƶ����Ե����ߴ�����Ӧ���ܣ��Ե�ʳ���ߵĳ������ӣ��߽���涴��������͵���ͼĳ��λ�ã�ײ��ǽ����ϰ�����Ϸ������\n");
	printf("  \n");
	printf("*�˵�����Ϸ���ý�����W��S�л�ѡ�A��D����������С����ENTER��ʾȷ�������ո��������һ����\n");
	system("pause");
}

// ������
void Controller::gameProductionTeamText(void)
{
	system("cls");
	printf("���������˵��\n");
	system("pause");
}
/**
* ��Ϸ��������
*/
int Controller::GameStart(int mode)
{
	Map m1;
	Food food;
	//��ʼ����
	Snake s1;
	if (mode == CLASSIC_MODE)
	{
		// ����ģʽ����Ҫ��������
		food.mode = STANDARD_FOOD;
	}
	else if (mode == ADVENTURE_MODE)
	{
		// �������ǽ��
		// ���ǵ���������ǽ��
		// �������ʳ��
		m1.RandomBuild();
		food.mode = HASTEN_FOOD;
	}
	else if (mode == LEVEL_MODE)
	{
		// ��ȡ�ض���ͼ
		m1.LoadMap(1);
		// ����ʳ��
		std::vector<Food> foods = food.SetStandardFood(FOOD_NUM);
		for (auto& it : foods)
		{
			m1.food_list.emplace_back(it);
		}
	}
	else if (mode == DUO_MODE)
	{
		// ��ȡ��ͼ
		// ��ȡʳ��
		// ��ȡǽ��
		// ��ȡ��
	}
	int run_flag = GAME_RUNNING;
	// ��ֹʳ���ǽ�غ�
	while (find(m1.walls.begin(), m1.walls.end(), food.GetFood()) != m1.walls.end()) food.MoveFood();
	// ��ӡ��ͼ ��ʳ������ͼ
	if (mode != LEVEL_MODE) m1.food_list.emplace_back(food);
	m1.PrintInitmap();
	while (run_flag == GAME_RUNNING)
	{
		run_flag = (gameRunning(s1, m1, mode));
	}
	if (run_flag == LEVEL_VICTORY)
	{
		// ��ת��Ϸʤ������
		return VictoryView();
	}
	else if (run_flag == SNACK_LOSE || run_flag == GAME_OVER)
	{
		// ��ת��Ϸʧ�ܻ���
		return LoseView();
	}
	// �����Ļ
	ClearScreen();
}
int Controller::gameRunning(Snake& s1, Map& m, int mode)
{
	// ��ӡ��
	if (!s1.changeDirection())
	{
		// ��ͣ����
		if (PauseView() == GAME_RUNNING)
		{
			// ������Ϸ�����˳���Ϸ
			// ���»��Ƶ�ͼ
			m.PrintInitmap();
		}
		else if (PauseView() == GAME_BREAK)return GAME_BREAK;
		else if (PauseView() == GAME_OVER)return GAME_OVER;
	}
	s1.move();
	if (s1.isDead(m)) return SNACK_LOSE;
	for (auto it = m.food_list.begin(); it != m.food_list.end(); it++)
	{
		if (it->GetFood() == s1.getHead())
		{
			s1.EatFood(*it);
			if (mode == LEVEL_MODE || it->mode != STANDARD_FOOD)
			{
				m.food_list.erase(it);
				break;
			}
			Food NewFood;
			while (find(m.walls.begin(), m.walls.end(), NewFood.GetFood()) != m.walls.end()) NewFood.MoveFood();
			NewFood.mode = it->mode;
			m.food_list.erase(it);
			m.food_list.emplace_back(NewFood);
			break;
		}
	}
	if (mode == LEVEL_MODE && m.food_list.empty()) return LEVEL_VICTORY;
	s1.PrintSnake();
	// ��ӡʳ��
	for (auto& it : m.food_list)
	{
		it.PrintFood();
	}
	// ��ӡ����
	s1.PrintScore();
	// ����ʳ��ʱ��
	time_t currentTime = time(0);
	// ������ɵ���
	if (currentTime - lastFoodTime >= GENER_FREQU)
	{
		Food food;
		food.RandomFood();
		m.food_list.emplace_back(food);
		lastFoodTime = currentTime;
	}

	return GAME_RUNNING;
}

//��Ϸ��������
/*
����������ͬ��
*/
void Controller::gameendView(Snake& s)
{
	int cur = 0;
	int gamemode = 1;
	while (1)
	{
		int gamemodeView_flag = 1;  //��������ѭ��
		WriteGrade();
		system("cls");
		printf("\t-----------��Ϸ����----------\n");
		if (gamemode == 1)//����ģʽ
		{
			std::cout << "��ĵ÷�Ϊ" << s.getScore();
			std::cout << "��ʷ��ߵ÷�Ϊ" << MAX(s.getScore(), max_score);
		}
		printf("%s\t����һ��%s\n", cur == 0 ? "   -->" : "", cur == 0 ? "  <--" : "");
		printf("%s\t���ز˵�%s\n", cur == 1 ? "   -->" : "", cur == 1 ? "  <--" : "");
		switch (_getch())
		{
		case ' ':
			return;
		case 'w':
		case 'W':
			if (--cur < 0)
			{
				cur = 0;
			}
			break;
		case 's':
		case 'S':
			if (++cur > 1)
			{
				cur = 1;
			}
			break;
		case '\r':
			switch (cur)
			{
			case 1:		// ���ز˵�
				gameMenu();
				gamemodeView_flag = 0;
				break;
			case 0:		// ����һ��
				system("cls");
				gamemodeView_flag = 0;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		if (gamemodeView_flag == 0)
		{
			break;
		}
	}
}

void Controller::ClearScreen()
{
	for (int i = 0; i <= 2 * ROW; i++)
	{
		for (int j = 0; j <= 2 * COL + 2; j++)
		{
			gotoxy(j, i);
			printf(" ");
			Sleep(0);
		}
	}
}

/**
* ���ý���
* ����������ͬ��
* �������صĵ���---ͨ���޸�if���ж���ʹ���ֲ������
*/
void Controller::gameFit(void)
{
	int cur = 0;
	int choose_BGM = 1;
	int choose = 1;

	// ����Ϸ״̬���ȡ
	int curMusic = 5;
	int curEffect = 7;
	int maxMusic = 10;

	while (1)
	{
		system("cls");
		printf("\t  ����\n");
		printf("%s\t��������%s\n\t|", cur == 0 ? "   -->" : "", cur == 0 ? "  <--" : "");
		if (choose_BGM == 0) {
			printf("��");
			//musicSwitch_BGM = 0;
		}
		else if (choose_BGM == 1) {
			printf("��");
			//musicSwitch_BGM = 1;
		}
		printf("|\n%s\t��Ϸ��Ч%s\n\t|", cur == 1 ? "   -->" : "", cur == 1 ? "  <--" : "");
		if (choose == 0) {
			printf("��");
			//musicSwitch = 0;
		}
		else if (choose == 1) {
			printf("��");
			//musicSwitch = 1;
		}

		printf("|\n");

		switch (_getch())
		{
		case ' ':
			return;
		case 'w':
		case 'W':
			if (--cur < 0)
			{
				cur = 0;
			}
			break;
		case 's':
		case 'S':
			if (++cur > 1)
			{
				cur = 1;
			}
			break;
		case 'a':
		case 'A':
		case 'd':
		case 'D':
			switch (cur)
			{
			case 0:		// ����
				if (choose_BGM == 0) {
					choose_BGM++;
				}
				else {
					choose_BGM--;
				}
				break;
			case 1:		// ��Ч
				if (choose == 0) {
					choose++;
				}
				else {
					choose--;
				}
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}
