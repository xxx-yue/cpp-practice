#include"Stack.h"
//初始化
void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	//top指向栈顶数据的下一个位置
	pst->top = 0;
	//下面是top指向栈顶数据
	//pst->top = -1;
	pst->capacity = 0;
}

//删除栈
void STDestory(ST* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}

//入栈  
void STPush(ST* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;
}

//减栈
void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	pst->top--;
}

//取栈顶数据
STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	return pst->a[pst->top - 1];
}

//判断是否为空
bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
}

//获取数据个数
int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}
