#pragma once
#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "snake.h"
#include "food.h"

class Controller
{
public:
	// 游戏失败界面函数
	int LoseView();
	// 游戏胜利界面函数
	int VictoryView();
	//游戏中途暂停函数
	int PauseView();
	//修改方向函数
	void updateDir();
	// 主菜单
	int gameMenu();
	// 游戏模式选择
	int gamemodeView();
	// 设置界面
	void gameFit();
	// 游戏说明
	void gameText();
	// 制作组
	void gameProductionTeamText();
	// 游戏启动
	int GameStart(int mode);
	// 游戏运行
	int gameRunning(Snake& s1, Map& m, int mode);
	//游戏结束
	void gameendView(Snake& s);
	// 清理屏幕
	void ClearScreen();
	//从文件读取最高分
	int ReadGrade();
	//更新最高分到文件
	void WriteGrade();
	// 设定控制台界面初始设定
	bool SetSize(int width, int height);
	// 光标移动
	static void gotoxy(int x, int y);
private:
	int max_score = 0;
	// 在类的成员变量中定义上一次生成特性食物的时间
	time_t lastFoodTime = 0;
};


#endif // !_CONTROLLER_H_

