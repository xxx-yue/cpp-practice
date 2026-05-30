#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<stdbool.h>
#include<time.h>

#define POS_X 50
#define POS_Y 5
#define BODY L'●'
#define WALL L'□'
#define FOOD L'●'
//类型的声明
//蛇的方向
enum DIRECTION
{
	up = 1,
	down,
	left,
	right,
};
//蛇的状态
//正常 撞墙 撞到自己 正常退出
enum GAME_STATUS
{
	ok,//正常
	kill_by_wall,//撞墙
	kill_by_self,//撞到自己
	end_normal,//正常退出
};
//蛇身的节点类型
typedef struct snakeNode
{
	//坐标
	int x;
	int y;
	//指向下一个节点的指针
	struct snakeNode* next;
}SnakeNode,* pSnakeNode;
//贪吃蛇
typedef struct Snake
{
	pSnakeNode _pSnake;//指向蛇头的指针
	pSnakeNode  _pFood;//指向食物节点的指针
	enum DIRECTION _dir;//蛇的方向
	enum GAME_STATUS _status;//游戏状态
	int _food_weight;//一个食物分数
	int _score;		//总成绩
	int _sleep_time;	//休息时间，时间越短，速度越快，时间越长，速度越慢
}Snake,*pSnake;



//函数的声明
// 定位光标位置
void SetPos(short x, short y);
//游戏的初始化
void GameStart(pSnake ps);
//欢饮界面的打印
void WelcomeToGame();
//地图绘制
void CreatMap();
//初始化蛇
void InitSnake(pSnake ps);
//创建食物
void CreatFood(pSnake ps);
//游戏运行的逻辑
void GameRun(pSnake ps);
//蛇的移动 走一步
void SnakeMove(pSnake ps);
//判断下一个坐标是否是食物
int NextIsFood(pSnakeNode pn, pSnake ps);
//下一个位置是食物，就吃掉食物
void EatFood(pSnakeNode pn, pSnake ps);
//下一个位置不是食物
void NoFood(pNextNode, ps);
//检测蛇是否撞墙
void KillByWall(pSnake ps);
//检测蛇是否撞上自己
void KillBySelf(pSnake ps);
//游戏善后的工作
void GameEnd(pSnake ps);


