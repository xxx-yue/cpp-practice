#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int main()
//{
//	int a = 5;
//	int b = 3;
//	int c = (a == b);
//	printf("%d\n", c);
//	return 0;
//}
//int main()
//{
//	int k = 5;
//	if (3 == k)
//		printf("hehe\n");
//	return 0;
//}
//int main()
//{
//	int a = 1;
//	int b = 8;
//	int c = 5;
//	if (a < b &&b< c)
//		printf("hehe\n");
//	else
//		printf("haha\n");
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d", &a);
//	/*if (a == 5)
//		b = 3;
//	else
//		b = -3;*/
//	b = (a == 5 ? 3 : -3);
//	printf("%d\n", b);
//	return 0;
//}
int main()
{
	int a = 0;
	int b = 0;
	int m = 0;
	scanf("%d %d", &a, &b);
	
	if (a > b)
		m = a;
	else
		m = b;
	printf("%d", m);
	return 0;
}