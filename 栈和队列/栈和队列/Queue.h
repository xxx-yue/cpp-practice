#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include <limits.h>
#include <stdlib.h>
#include<stdbool.h>
typedef int QDataType;
//队列本身
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType x;
}QNode;
//存放队列的头和尾的结构体
typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;
//初始化队列
void QueueInit(Queue* pq);
//销毁队列
void QueueDestroy(Queue* pq);
//队尾插入
void QueuePush(Queue* pq,QDataType x);
//队头删除
void QueuePop(Queue* pq);
//取队头数据
QDataType QueueFront(Queue* pq);
//取队尾数据
QDataType QueueBack(Queue* pq);
//获取队列内数据个数
int QueueSize(Queue* pq);
//判断队列是否为空
bool QueueEmpty(Queue* pq);