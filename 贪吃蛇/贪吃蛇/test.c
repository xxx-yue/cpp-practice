#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<locale.h>
#include <conio.h>
#include"snake.h"
//完成的是游戏的测试逻辑
void test()
{
	int ch = 0;
	do
	{
		system("cls");
		//创建贪吃蛇
		Snake snake = { 0 };
		//初始化游戏
		//1.打印欢迎界面
		//2.功能介绍
		//3.绘制地图
		//4.创建蛇
		//5.创建食物
		//6.设置食物的相关信息
		GameStart(&snake);
		////运行游戏
		GameRun(&snake);
		////结束游戏 - 善后工作
		GameEnd(&snake);
		SetPos(40, 16);
		printf("再来一局吗？(Y/N):");
		// 关键修改：循环捕获按键，只响应 y/n
		while (1) {
			// 清空残留按键缓冲区（避免方向键等无效字符干扰）
			while (_kbhit()) {
				_getch();
			}

			ch = tolower(_getch());  // 转小写，统一判断（y/n 即可，无需区分大小写）

			// 只有按 y 或 n，才跳出循环（其他按键继续等待）
			if (ch == 'y' || ch == 'n') {
				break;  // 退出按键等待循环
			}
			// 其他按键：不做任何操作，回到循环开头继续等待
		}
	} while (ch == 'Y' || ch == 'y');
	SetPos(40, 31);

}
int main()
{
	//设置适配本地环境
	setlocale(LC_ALL, "");
	srand((unsigned int)time(NULL));
	test();
	return 0;
}