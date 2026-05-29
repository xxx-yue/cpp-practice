#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include <limits.h>
#include <stdlib.h>
#include<math.h>
#include"Queue.h"
//初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}
//销毁队列
void QueueDestroy(Queue* pq)
{
	assert(pq);
	while (pq->head)
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
	pq->tail = pq->head = NULL;
	pq->size = 0;
}
//队尾插入
void QueuePush(Queue* pq,QDataType x )
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("perror fail");
		return;
	}
	newnode->x = x;
	newnode->next = NULL;
	if (!pq->head)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	pq->size++;
}
//队头删除
void QueuePop(Queue* pq)
{
	assert(pq);  
	assert(pq->size!=0);
	QNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (!next)
	{
		pq->tail = NULL;
	}
	pq->size--;
}
//取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->size != 0);
	return pq->head->x;
}
//取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->size != 0);
	return pq->tail->x;
}
//获取队列内数据个数
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}
//判断队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}