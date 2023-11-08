#pragma once
#ifndef _VARIABLES_H_
#define _VARIABLES_H_

/**
* 可改
* ROW 游戏区行数row，控制整个游戏区的大小
* COL 游戏区列数column，控制整个游戏区的大小 因为墙壁占两个空格
* MAX_DIR_BUF 最大方向缓冲区，用来控制蛇的移动方向
* WALL_NUM 墙体数量
* MIN_DIST 墙体不生成区域 防止开局被杀
*/
#define ROW 14
#define COL 36
#define MAX_DIR_BUF 10
#define WALL_NUM 30
#define MIN_DIST 10
#define FOOD_NUM 3

/*
* 可改
* 蛇的属性修改
* 蛇的长度是SNAKE_LEN
* 蛇的速度是SLEEP_TIME/SNAKE_SPEED，SNAKE_SPEED越大，蛇的速度越快
* 蛇的加速度是SLEEP_ACCELERATION, SLEEP_ACCELERATION越大，蛇的加速度越快
* 蛇的得分是SCORE_ACCERELATION, SCORE_ACCERELATION越大，蛇吃食物的得分越高
* 蛇的速度上限是SPEED_RANGE_LIMIT，SPEED_RANGE_LIMIT越大，蛇的速度变化阈值越大
*/
#define SNAKE_LEN 5
#define SNAKE_SPEED 1000
#define SLEEP_TIME 100000
#define SNAKE_ACCELERATION 100
#define SCORE_ACCERELATION 10
#define SPEED_RANGE_LIMIT 1.5

/**
* 不可改
* CLASSIC_MODE 经典模式
* ADVENTURE_MODE 冒险模式
*/

#define CLASSIC_MODE 1
#define ADVENTURE_MODE 2
#define LEVEL_MODE 3
#define DUO_MODE 4

#define STANDARD_MODE 0
#define STANDARD_FOOD 0
#define SNACK_LOSE 0
#define GAME_RUNNING 1
#define LEVEL_VICTORY 2

/**
* 不可改
* KONG 标记空（什么也没有）
* WALL 标记墙
* OBJECT 标记物体
* HEAD 标记蛇头
* BODY 标记蛇身
* UP 方向键：W
* DOWN 方向键：S
* LEFT 方向键：A
* RIGHT 方向键：D
* UP2 方向键：上
* DOWN2 方向键：下
* LEFT2 方向键：左
* RIGHT2 方向键：右
* SPACE 暂停
* ESC 退出
*/
#define KONG 0
#define WALL 1
#define OBJECT 2
#define HEAD 3
#define BODY 4

//#define UP 119
//#define DOWN 115
//#define LEFT 97
//#define RIGHT 100

#define UP2 72
#define DOWN2 80
#define LEFT2 75
#define RIGHT2 77

#define SPACE 32
#define ESC 27

/**
* 游戏初始设定
* MUSIC_SWITCH 游戏音效开关 
* MUSIC_SWITCH_BGM 游戏背景音乐开关
*/
#define MUSIC_SWITCH 1
#define MUSIC_SWITCH_BGM 1;

#endif // !_VARIABLES_H_