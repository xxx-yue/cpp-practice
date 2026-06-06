#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include <limits.h>
#include <stdlib.h>
#include<math.h>
#include <stdbool.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

//交换两个数据
void Swap(HPDataType* P1, HPDataType* P2);
//向上调整
void AdjustUp(HPDataType* a, int child);
//向下调整
void AdjustDown(HPDataType* a, int n, int parent);
//初始化堆
void HPInit(HP* php);
//销毁堆
void HPDestroy(HP* php);
//向堆内插入数据
void HPPush(HP* php, HPDataType x);
//去除堆数据
void HPPop(HP* php);
//取堆顶数据
HPDataType HPTop(HP* php);
//堆的判空
bool HPEmpty(HP* php);
//堆排序
void HeapSort(int* a, int n);