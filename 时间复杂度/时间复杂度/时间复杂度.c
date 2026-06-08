#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include <limits.h>
#include <stdlib.h>
#include<math.h>
 
//void func2(int n)
//{
//	int count = 0;
//	for (int k = 0; k < 2 * n; ++k)
//	{
//		++count;
//	}
//	int m = 10;
//	while(m--)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}

//void func(int n, int  m)
//{
//	int count = 0;
//	for (int k = 0; k > m; ++k)
//	{
//		++count;
//	}
//	for (int k = 0; k < n; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}

void fun(int n)
{
	int count = 0;
	for (int k = 0; k < 100; ++k)
	{
		++count;
	}
	printf("%d\n", count);//O(1)
}

//实例五时间复杂度为O(N²)
//实例六时间复杂度为O(lg2)
//实例七时间复杂度为O(N)
//2 n
