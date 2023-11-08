#pragma once
#ifndef _VARIABLES_H_
#define _VARIABLES_H_

/**
* �ɸ�
* ROW ��Ϸ������row������������Ϸ���Ĵ�С
* COL ��Ϸ������column������������Ϸ���Ĵ�С ��Ϊǽ��ռ�����ո�
* MAX_DIR_BUF ����򻺳��������������ߵ��ƶ�����
* WALL_NUM ǽ������
* MIN_DIST ǽ�岻�������� ��ֹ���ֱ�ɱ
*/
#define ROW 14
#define COL 36
#define MAX_DIR_BUF 10
#define WALL_NUM 30
#define MIN_DIST 10
#define FOOD_NUM 3

/*
* �ɸ�
* �ߵ������޸�
* �ߵĳ�����SNAKE_LEN
* �ߵ��ٶ���SLEEP_TIME/SNAKE_SPEED��SNAKE_SPEEDԽ���ߵ��ٶ�Խ��
* �ߵļ��ٶ���SLEEP_ACCELERATION, SLEEP_ACCELERATIONԽ���ߵļ��ٶ�Խ��
* �ߵĵ÷���SCORE_ACCERELATION, SCORE_ACCERELATIONԽ���߳�ʳ��ĵ÷�Խ��
* �ߵ��ٶ�������SPEED_RANGE_LIMIT��SPEED_RANGE_LIMITԽ���ߵ��ٶȱ仯��ֵԽ��
*/
#define SNAKE_LEN 5
#define SNAKE_SPEED 1000
#define SLEEP_TIME 100000
#define SNAKE_ACCELERATION 100
#define SCORE_ACCERELATION 10
#define SPEED_RANGE_LIMIT 1.5

/**
* ���ɸ�
* CLASSIC_MODE ����ģʽ
* ADVENTURE_MODE ð��ģʽ
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
* ���ɸ�
* KONG ��ǿգ�ʲôҲû�У�
* WALL ���ǽ
* OBJECT �������
* HEAD �����ͷ
* BODY �������
* UP �������W
* DOWN �������S
* LEFT �������A
* RIGHT �������D
* UP2 ���������
* DOWN2 ���������
* LEFT2 ���������
* RIGHT2 ���������
* SPACE ��ͣ
* ESC �˳�
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
* ��Ϸ��ʼ�趨
* MUSIC_SWITCH ��Ϸ��Ч���� 
* MUSIC_SWITCH_BGM ��Ϸ�������ֿ���
*/
#define MUSIC_SWITCH 1
#define MUSIC_SWITCH_BGM 1;

#endif // !_VARIABLES_H_