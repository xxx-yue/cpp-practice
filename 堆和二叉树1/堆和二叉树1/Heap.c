#include"Heap.h"
//交换两个数据
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

//初始化堆
void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}
//销毁堆
void HPDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}
//向上调整 (小堆)
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			//如果孩子比父母小就交换
			//把小的往上挪
			Swap(&a[child], &a[parent]);
			//三角形上移,原先的父母(三角形顶点)成为新三角形的一边角
			child = parent;
			parent = (parent - 1) / 2;
		}
		else break;
	}
}
//向下调整 (小堆)
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child + 1] < a[child] && child + 1 < n)
			child++;
		//如果孩子比父母小就交换
		//把小的往上挪
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			//挪动的三角形边角成为新三角形顶角
			parent = child;
			child = child * 2 + 1;
		}
		else break;
	}
}

//向堆内插入数据
void HPPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->capacity == php->size)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* temp = (HPDataType*)realloc(php->a, newcapacity * sizeof(HPDataType));
		if (temp == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->a = temp;
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	php->size++;
	AdjustUp(php->a, php->size - 1);
}
//去除堆数据
void HPPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}
//取堆顶数据
HPDataType HPTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}
//堆的判空
bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}
//堆的排序
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end)
	{
		Swap(&a[end], &a[0]);
		AdjustDown(a, end, 0);
		end--;
	}
}