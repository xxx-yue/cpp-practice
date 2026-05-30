#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
#include<locale.h>
//int main()
//{
//	//设置控制台的相关属性
//	system("mode con cols=130 lines=30");
//	system("title 贪吃蛇");
//	//getchar();
//	system("pause");
//	return 0;
//}
//int main()
//{
//	COORD pos = { 0,0 };
//	COORD pos2 = { 10,20 };
//	return 0;
//}
//int main()
//{
//	//获得标准输出设备的句柄
//	HANDLE houtput = NULL;
//	houtput = GetStdHandle(STD_OUTPUT_HANDLE);
//	//定义一个光标信息的结构体
//	CONSOLE_CURSOR_INFO cursor_info = { 0 };
//	//获取和houtput句柄相关的控制台上的光标信息，存放在cursor_info中
//	GetConsoleCursorInfo(houtput, &cursor_info);
//	//修改光标的占比
//	cursor_info.dwSize = 50;
//	cursor_info.bVisible= false;
//	//设置和houtput句柄相关的控制台上的光标信息
//	SetConsoleCursorInfo(houtput, &cursor_info);
//	system("pause");
//	return 0;
//}
//
// void setpos(short x, short y)
//{
//	HANDLE houtput = NULL;
//	houtput = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD pos = { x,y };
//	SetConsoleCursorPosition(houtput, pos);
//
//}
//int main()
//{
//	////获得标准输出设备的句柄
//	//HANDLE houtput = NULL;
//	//houtput = GetStdHandle(STD_OUTPUT_HANDLE);
//	////定位光标的位置
//	//COORD pos = { 10,20 };
//	//printf("呵呵");
//	//SetConsoleCursorPosition(houtput, pos);
//	//COORD pos1 = { 10,10 };
//	//printf("呵呵");
//	//SetConsoleCursorPosition(houtput, pos1);
//
//	//getchar();
//	setpos(10, 20);
//	printf("hehe\n");
//	setpos(10, 40);
//	printf("hehe\n");
//	setpos(10, 1);
//	getchar();
//	return 0;
//}

//结果是1表示按过
//结果是0表示没按过

//int main()
//{   
//	short ret = GetAsyncKeyState(0x35);
//	while (1)
//	{
//		if (ret & 1 == 1)
//		{
//			printf("5被按过\n");
//		}
//		else
//		{
//			printf("没有被按过\n");
//		}
//	}
//	return 0;
//}
//int main()
//{
//	while (1)
//	{
//		if (KEY_PRESS(0x30))
//		{
//			printf("0\n");
//		}
//		else if (KEY_PRESS(0x31))
//		{
//			printf("1\n");
//		}
//		else if (KEY_PRESS(0x32))
//		{
//			printf("2\n");
//		}
//		else if (KEY_PRESS(0x33))
//		{
//			printf("3\n");
//		}
//		else if (KEY_PRESS(0x34))
//		{
//			printf("4\n");
//		}
//		else if (KEY_PRESS(0x35))
//		{
//			printf("5\n");
//		}
//		else if (KEY_PRESS(0x36))
//		{
//			printf("6\n");
//		}
//		else if (KEY_PRESS(0x37))
//		{
//			printf("7\n");
//		}
//		else if (KEY_PRESS(0x38))
//		{
//			printf("8\n");
//		}
//		else if (KEY_PRESS(0x39))
//		{
//			printf("9\n");
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char* ret = setlocale(LC_ALL, NULL);
//	printf("%s\n",ret);
//	ret = setlocale(LC_ALL, "");
//	printf("%s\n", ret);
//	return 0;
//}
//int main() {
//	setlocale(LC_ALL, "");
//	wchar_t ch1 = L'●';
//	wchar_t ch2 = L'⽐';
//	wchar_t ch3 = L'特';
//	wchar_t ch4 = L'★';
//	printf("%c%c\n", 'a', 'b');
//	wprintf(L"%lc\n", ch1);
//	wprintf(L"%lc\n", ch2);
//	wprintf(L"%lc\n", ch3);
//	wprintf(L"%lc\n", ch4);
//	return 0;
//}
//int main()
//{
//	setlocale(LC_ALL, "");
//	char a = 'a';
//	char b = 'b';
//	printf("%c%c\n", a, b);
//	wchar_t wc1 = L'比';
//	wchar_t wc2 = L'特';
//	wprintf(L"%lc\n", wc1);
//	wprintf(L"%lc\n", wc2);
//	wprintf(L"%lc\n", L'黄');
//	return 0;
//}
//int main()
//{
//	system("mode con cols=150 lines=40");
//	printf("%d",1);
//	return 0;
//}