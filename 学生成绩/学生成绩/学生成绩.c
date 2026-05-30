#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include <limits.h>
#include <stdlib.h>
#include<math.h>
/*利用C语言编程实现对学生成绩的管理（包含但不限于下述功能）：
（1）每条记录包括：学号、姓名、专业和5门课程的成绩；
（2）能够实现录入、删除、修改功能；
（3）具备多种查询功能：如按姓名、课程、成绩等；
（4）具备统计、排序功能，如能统计某学生的总分和平均分、某课程的平均成绩、某成绩段的人数、按成绩排序输出等；
（5）在此基础上，进行文件操作保存学生信息和成绩；
（6）要有比较美观的界面、清楚的提示、清晰的输出。
*/
#define ： :
#define ！ !
#define ， ,
#define （） ()
void menu()
{

	printf("请选择你的操作：\n");
	printf("0.退出成绩关机系统 1.录入成绩\n");
	printf("2.修改成绩	   3.删除成绩\n");
	printf("4.查询学生成绩\n");
}
int main()
{
	printf("欢迎使用学生成绩管理系统！\n");
	FILE* p = fopen("学生信息", "w");
	if (p == NULL)
	{
		perror("fopen:");
		return 1;

	}
	int input = 0;
	int num, score1, score2, score3, score4, score5;
	int balabala = 0;
	char name[20] = { 0 };
	char tech[20] = { 0 };
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case(0):printf("退出成绩管理系统！\n");
			return 0;
		case(1):
		{
			printf("请输入该学生学号:\n");
			scanf("%d", &num);
			printf("请输入该学生姓名:\n");
			scanf("%s", &name);
			printf("请输入该学生专业:\n");
			scanf("%s", &tech);
			printf("请分别输入该学生的五门课程分数:\n");
			scanf("%d %d %d %d %d", &score1, &score2, &score3, &score4, &score5);
			printf("已录入该学生的全部信息!\n");
			break;
		}
		case(2):
		{
			printf("请输入你要修改的学生成绩的学号:\n");
			scanf("%d", &num);
			printf("该生姓名为%s，学号为%d，请选择你要修改的学科:\n", name, num, tech);
			scanf("%s", &tech);
			printf("请输入修改后的成绩:");
			scanf("%d", &score1);//
			break;
		}
		case(3):
		{
			printf("请输入你要删除的学生成绩的学号以及对应学科\n");
			scanf("%d %s", num, tech);
			printf("恭喜你，删除成功！");
			break;
		}
		case(4)：
		{
			printf("请输入你要查询的学生成绩的姓名，学号，以及对应学科");
			scanf("%s%d%s", name, num, tech);
			printf("该生对应学科成绩为%d", score1);
			break;
		}
		case(5):
			printf("如果需要继续操作系统请按1\n");
			printf("如果需要退出系统请按0\n");
			scanf("%d", balabala);
		}
	} while (balabala);
	return 0;
}