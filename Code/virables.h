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
* FOOD_NUM 食物数量
* POWER_TIME 吃到无敌食物后的无敌时间
* GENER_FREQU 道具生成频率,越大生成越慢
*/
#define ROW 14
#define COL 36
#define MAX_DIR_BUF 10
#define WALL_NUM 10
#define MIN_DIST 10
#define FOOD_NUM 3
#define POWER_TIME 10
#define GENER_FREQU 10

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
#define HASTEN_FOOD 1
#define POWER_FOOD 2

#define SNACK_LOSE -100
#define GAME_RUNNING 1
#define GAME_BREAK 0
#define GAME_OVER 2
#define GAME_RESTART 3
#define LEVEL_VICTORY 100


/**
* 游戏初始设定
* MUSIC_SWITCH 游戏音效开关 
* MUSIC_SWITCH_BGM 游戏背景音乐开关
*/
#define MUSIC_SWITCH 1
#define MUSIC_SWITCH_BGM 1;

#endif // !_VARIABLES_H_