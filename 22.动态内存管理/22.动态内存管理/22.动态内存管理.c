#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include <limits.h>
#include <stdlib.h>
#include<math.h>
void* realloc(void* ptr, size_t size)
{
	;
}
//int main()
//{
//	int* ptr = (int*)malloc(40);
//	if (ptr != NULL)
//	{
//		int* tmp = realloc(ptr, 80);
//	}
//	return 1;
//}
//int main()
//{
//	int* ptr = (int*)malloc(10);
//	if (ptr != NULL)
//	{
//		ptr = (int*)realloc(ptr, 100);
//	}
//	int* p = NULL;
//	p = realloc(ptr, 1000);
//	if (p != NULL)
//	{
//		ptr = p;
//	}
//	free(ptr);
//	return 0;
//}

//void test()
//{
//	int* p = (int*)malloc(INT_MAX);
//	*p = 20;
//	free(p);
//}

//void test()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	for (i = 0; i <=10; i++)
//	{
//		*(p + i) = i;
//	}
//	free(p);
//	p = NULL;
//}
//int main()
//{
//	test();
//	return 0;
//}

//void test()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);
//}
//int main()
//{
//	test();
//	return 0;
//}

//void test()
//{
//	int* p = (int*)malloc(100);
//	p++;
//	
//}
//int main()
//{
//	test();
//	return 0;
//}
//
//void test()
//{
//	int* p = (int*)malloc(100);
//	free(p);
//
//}
//int main()
//{
//	test();
//	return 0;
//}

//void test()
//{
//	int* p = (int*)malloc(100);
//	if (NULL != p)
//	{
//		*p = 20;
//		free(p);
//		p = NULL;
//	}
//	
//}
//int main()
//{
//	test();
//	return 0;
//}

//void getmemory(char**p)
//{
//	*p = (char*)malloc(100);
//}
//void test(void)
//{
//	char* str = NULL;
//	getmemory(&str);
//	if (str != NULL)
//	{
//		strcpy(str, "hello world");
//		printf(str);
//		free(str);
//		str = NULL;
//	}
//}
//int main()
//{
//	test();
//	return 0;
//}

//char* getmemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//void test(void)
//{
//	char* str = NULL;
//	str = getmemory();
//	printf(str);
//}
//int main()
//{
//	test();
//		return 0;
//}

//void getmemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//void test(void)
//{
//	char* str = NULL;
//	getmemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//}
//int main()
//{
//	test();
//	return 0;
//}

//void test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//int main()
//{
//	test();
//	return 0;
//}

//ÈáÐÔÊý×é
//struct st
//{
//	int i;
//	int a[0];
//};

//struct st
//{
//	int i;
//	int a[];
//};

//typedef struct st
//{
//	int i;
//	int a[0];
//}ggb;
//int main()
//{
//	printf("%d", sizeof(ggb));
//	return 0;
//}
//
//int main()
//{
//	int i = 0;
//	ggb* p = (ggb*)malloc(sizeof(ggb) + 100 * sizeof(int));
//	p->i = 100;
//	for (i = 0; i < 100; i++)
//	{
//		p->a[i] = i;
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}


typedef struct st
{
	int i;
	int* p1;
}ggb;
int main()
{
	 ggb* p = ( ggb*)malloc(sizeof(ggb));
	p->i = 100;
	p->p1 = (int*)malloc(p->i * sizeof(int));
	for (int i = 0; i < 100; i++)
	{
		p->p1[i] = i;
	}
	free(p->p1 );
	p->p1  = NULL;
	free(p);
	p = NULL;
	return 0;
}