#define _CRT_SECURE_NO_WARNINGS //取消scanf返回值的警告
#include <iostream>
#include <stdbool.h>
#include <windows.h>
#include <conio.h> /*键盘输入获取*/
#include "snake.h"
#include "map.h"
#include "controller.h"

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

//从文件读取最高分
int Controller::ReadGrade()
{
	int ret;
	FILE* pf = fopen("Score.txt", "r"); //以只读的方式打开文件
	if (pf == NULL) //打开文件失败
	{
		int a = 0;
		std::cout << "读取最高得分记录失败\n";
		pf = fopen("Score.txt", "w"); //以只写的方式打开文件
		fwrite(&a, sizeof(int), 1, pf); //将max写入文件（此时max为0），即将最高得分初始化为0
	}
	fseek(pf, 0, SEEK_SET); //使文件指针pf指向文件开头
	fread(&ret, sizeof(int), 1, pf); //读取文件当中的最高得分到max当中
	fclose(pf); //关闭文件
	pf = NULL; //文件指针及时置空

	return ret;
}

//更新最高分到文件
void Controller::WriteGrade()
{
	FILE* pf = fopen("Score.txt", "w"); //以只写的方式打开文件
	if (pf == NULL) //打开文件失败
	{
		std::cout << "保存最高得分记录失败\n";
		exit(0);
	}
	fwrite(&max_score, sizeof(int), 1, pf); //将本局游戏得分写入文件当中
	fclose(pf); //关闭文件
	pf = NULL; //文件指针及时置空
}

/**
* 光标移动函数
* 将光标移动到x,y的位置
*/
void Controller::gotoxy(int x, int y)
{
	COORD pos; //定义光标位置的结构体变量
	pos.X = x; //横坐标
	pos.Y = y; //纵坐标
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
	SetConsoleCursorPosition(handle, pos); //设置光标位置
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
}

// 接受输入函数
void Controller::updateDir()
{

}

//2.当空格键时，生成暂停界面, 这里也是框架
void Controller::PauseView()
{
	int PauseValue;
	int PauseView_flag = 1;
	system("cls");
	printf("\n\n");
	printf("\t1.继续游戏\n");
	printf("\t2.设置\n");
	printf("\t3.返回选择模式界面\n");
	for (int i = 0; i < 4; i++)
	{
		printf("\t请选择你的操作：");
		fflush(stdin);
		scanf_s("%d", &PauseValue);
		switch (PauseValue)
		{
		case 1:
			return; //返回到界面（这里直接添加函数）
			break;
		case 2:
			gameFit();
			PauseView_flag = 0;
			break;
		case 3:
			gamemodeView();
			PauseView_flag = 0;
			break;
		default:
			printf("\n选项错误！请重新选择!!!\n\n");
			system("pause");
			continue;
		}
		if (PauseView_flag == 0)
		{
			break;
		}
	}
}

/**
* 打印出游戏界面的主菜单，通过_getch()函数接收输入的指令，通过
* while函数和修改cur的值再加上if判断来实现-->和<--的跳转显示
* 添加gameMenu_flag来作为标识符，当选择进入后关闭该界面。
*/
void Controller::gameMenu()
{
	int cur = 0;
	while (1)
	{
		int gameMenu_flag = 1;
		system("cls");
		gotoxy(COL - 4, ROW / 2);
		printf("主菜单\n");
		gotoxy(COL - 4, ROW / 2 + 2);
		printf("%s开始游戏", cur == 0 ? "==>" : "");
		gotoxy(COL - 4, ROW / 2 + 4);
		printf("%s设置", cur == 1 ? "==>" : "");
		gotoxy(COL - 4, ROW / 2 + 6);
		printf("%s游戏说明", cur == 2 ? "==>" : "");
		gotoxy(COL - 4, ROW / 2 + 8);
		printf("%s退出游戏", cur == 3 ? "==>" : "");
		//gotoxy(COL - 4, ROW / 2 + 10);
		//printf("%s制作组", cur == 4 ? "==>" : "");

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
			case 0:		// 开始游戏
				gamemodeView();
				gameMenu_flag = 0;
				break;
			case 1:		// 设置
				gameFit();

				break;
			case 2:		// 游戏说明
				gameText();

				break;
			case 3:		// 退出游戏
				gameMenu_flag = 0;
				break;
			case 4:		// 制作组
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
		if (gameMenu_flag == 0)
		{
			break;
		}
	}
}


// 游戏模式选择
void Controller::gamemodeView(void)
{
	int cur = 0;

	while (1)
	{
		int gamemodeView_flag = 1;  //借力跳出循环
		system("cls");
		gotoxy(COL - 4, ROW / 2);
		printf("游戏模式\n");
		gotoxy(COL - 4, ROW / 2 + 2);
		printf("%s经典模式\n", cur == 0 ? "==>" : "");
		gotoxy(COL - 4, ROW / 2 + 4);
		printf("%s冒险模式\n", cur == 1 ? "==>" : "");
		gotoxy(COL - 4, ROW / 2 + 6);
		printf("%s闯关模式\n", cur == 2 ? "==>" : "");
		gotoxy(COL - 4, ROW / 2 + 8);
		printf("%s双人模式\n", cur == 3 ? "==>" : "");

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
			if (++cur > 3)
			{
				cur = 3;
			}
			break;
		case '\r':
			switch (cur)
			{
			case 0:		// 经典模式
				system("cls");
				GameStart(CLASSIC_MODE);
				//gamemodeView_flag = 0;
				break;
			case 1:		// 冒险模式
				system("cls");
				GameStart(ADVENTURE_MODE);
				//gamemodeView_flag = 0;
				break;
			case 2:		// 闯关模式 -- 特定地图 限定食物 未完成
				system("cls");
				GameStart(LEVEL_MODE);
				break;
			case 3:
				system("cls");
				GameStart(DUO_MODE);
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

// 游戏说明
void Controller::gameText(void)
{
	system("cls");
	printf("*蛇蛇大作战分为经典模式和对战模式。\n");
	printf("  \n");
	printf("*经典模式用W、A、S、D来控制蛇的移动，吃到食物后蛇的长度增加，撞到自身或墙体则游戏结束。\n");
	printf("  \n");
	printf("*对战模式两位玩家分别用W、A、S、D/I、J、K、L控制蛇的移动，吃到道具触发相应技能，吃到食物蛇的长度增加，蛇进入虫洞后随机传送到地图某个位置，撞到墙体或障碍后游戏结束。\n");
	printf("  \n");
	printf("*菜单和游戏设置界面用W、S切换选项，A、D调节声音大小，按ENTER表示确定，按空格键返回上一界面\n");
	system("pause");
}

// 制作组
void Controller::gameProductionTeamText(void)
{
	system("cls");
	printf("在这里输出说明\n");
	system("pause");
}
/**
* 游戏启动函数
*/
void Controller::GameStart(int mode)
{
	Map m1;
	Food food;
	//初始化蛇
	Snake s1;
	if(mode == CLASSIC_MODE)
	{
		// 经典模式不需要其他操作
		food.mode = CLASSIC_MODE;
	}
	else if (mode == ADVENTURE_MODE)
	{
		// 随机生成墙体
		// 或是调用已生成墙体
		// 随机生成食物
		m1.RandomBuild();
		food.mode = HASTEN_FOOD;
	}
	else if( mode == LEVEL_MODE)
	{
		// 读取特定地图
		m1.LoadMap(1);
		// 加载食物
		int a = FOOD_NUM;
		while (a--)
		{
			food.SetStandardFood();
			m1.food_list.emplace_back(food);
		}
		food.mode = LEVEL_MODE;
	}
	else if (mode == DUO_MODE)
	{
		// 读取地图
		// 读取食物
		// 读取墙体
		// 读取蛇
	}
	int run_flag = GAME_RUNNING;
	// 防止食物和墙重合
	while (find(m1.walls.begin(), m1.walls.end(), food.GetFood()) != m1.walls.end()) food.MoveFood();
	// 打印地图 将食物加入地图
	if (mode != LEVEL_MODE) m1.food_list.emplace_back(food);
	m1.PrintInitmap();
	while (run_flag == GAME_RUNNING)
	{
		run_flag = (gameRunning(s1, m1, mode));
	}
	if (run_flag == LEVEL_VICTORY)
	{
		// 跳转游戏胜利画面
		PauseView();
	}
	// 清空屏幕
	ClearScreen();
}
int Controller::gameRunning(Snake& s1, Map& m, int mode)
{
	// 打印蛇
	s1.changeDirection();
	s1.move();
	//auto it = find(m.food_list.begin(), m.food_list.end(), s1.getHead());
	if (s1.isDead(m)) return SNACK_LOSE;
	for (auto it = m.food_list.begin(); it != m.food_list.end(); it++)
	{
		if (it->GetFood() == s1.getHead())
		{
			s1.EatFood(*it);
			if (mode == LEVEL_MODE)
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
	// 打印食物
	for (auto& it : m.food_list)
	{
		it.PrintFood();
	}
	// 打印分数
	s1.PrintScore();
	// 随机生成道具
	// m.food_list.emplace_back(food.RandomFood());

	return GAME_RUNNING;
}

//游戏结束界面
/*
与其他界面同理
*/
void Controller::gameendView(Snake& s)
{
	int cur = 0;
	int gamemode = 1;
	while (1)
	{
		int gamemodeView_flag = 1;  //借力跳出循环
		WriteGrade();
		system("cls");
		printf("\t-----------游戏结束----------\n");
		if (gamemode == 1)//单人模式
		{
			std::cout << "你的得分为" << s.getScore();
			std::cout << "历史最高得分为" << MAX(s.getScore(), max_score);
		}
		printf("%s\t再来一局%s\n", cur == 0 ? "   -->" : "", cur == 0 ? "  <--" : "");
		printf("%s\t返回菜单%s\n", cur == 1 ? "   -->" : "", cur == 1 ? "  <--" : "");
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
			case 1:		// 返回菜单
				gameMenu();
				gamemodeView_flag = 0;
				break;
			case 0:		// 再来一局
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
* 设置界面
* 界面与其他同理
* 音量开关的调节---通过修改if的判定来使音乐播放与否
*/
void Controller::gameFit(void)
{
	int cur = 0;
	int choose_BGM = 1;
	int choose = 1;

	// 从游戏状态里获取
	int curMusic = 5;
	int curEffect = 7;
	int maxMusic = 10;

	while (1)
	{
		system("cls");
		printf("\t  设置\n");
		printf("%s\t背景音乐%s\n\t|", cur == 0 ? "   -->" : "", cur == 0 ? "  <--" : "");
		if (choose_BGM == 0) {
			printf("关");
			//musicSwitch_BGM = 0;
		}
		else if (choose_BGM == 1) {
			printf("开");
			//musicSwitch_BGM = 1;
		}
		printf("|\n%s\t游戏音效%s\n\t|", cur == 1 ? "   -->" : "", cur == 1 ? "  <--" : "");
		if (choose == 0) {
			printf("关");
			//musicSwitch = 0;
		}
		else if (choose == 1) {
			printf("开");
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
			case 0:		// 音乐
				if (choose_BGM == 0) {
					choose_BGM++;
				}
				else {
					choose_BGM--;
				}
				break;
			case 1:		// 音效
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
