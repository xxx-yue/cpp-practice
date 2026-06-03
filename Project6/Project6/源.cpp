#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int m = 0;
//	scanf("%d %d", &a, &b);
//	/*if (a > b)
//		m = a;
//	else
//		m = b;*/
//	m = (a > b ? a : b);
//	printf("%d", m);
//}
//int main()
//{
//	int flag = 0;
//	scanf("%d", &flag);
//	/*if (flag)
//	{
//		printf("heeh\n");
//	}
//	else
//		printf("haha\n");*/
//	/*if (!flag)
//	{
//		printf("hehe\n");
//	}*/
//	if (flag == 0)
//	{
//		printf("hehe\n");
//	}
//	return 0;
//}
//int main()
//{
//	int month = 0;
//	printf("%s", "这个月是几月\n");
//	scanf("%d", &month);
//	if (month <= 5 && month >= 3)
//		printf("这个月是春天\n");
//	return 0;
//}
//int main()
//{
//	int month = 0;
//	scanf("%d",&month);
//	if (month == 12 || month == 1 || month == 2)
//		printf("这个月是冬天\n");
//	return 0;
//}
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	if (year % 4 == 0 && year % 100 != 0)
//		printf("今年是闰年\n");
//	else if (year % 400 == 0)
//		printf("今年是闰年\n");
//	return 0;
//}
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//		printf("今年是闰年\n");
//	return 0;
//}
//int main()
//{
//	int i = 0, a = 1, b= 2, c=3, d = 4;
//	i = a++ && ++b && d++;
//	printf("a=%d\n d=%d\n c=%d \n d=%d\n", a, b, c, d);
//	return 0;
//}
//int main()
//{
//	int i = 0, a = 1, b = 2, c = 3, d = 4;
//	i = a++ || ++b || d++;
//	printf("a=%d\n d=%d\n c=%d \n d=%d\n", a, b, c, d);
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	if (n % 3 == 2)
//		printf("余数为2\n");
//	if (n % 3 == 1)
//		printf("余数为1\n");
//	if (n % 3 == 0)
//		printf("余数为0\n");
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	switch (n % 3)
//	{
//	case 0:
//		printf("余数是0\n");
//		break;
//	case 1:
//		printf("余数是1\n");
//		break;
//	case 2:
//		printf("余数是2\n");
//		break;
//		return 0;
//	}
//}
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case1:
//		printf("今天星期一\n");
//		break;
//	case 2:
//		printf("今天星期二\n");
//		break;
//	case 3 :
//		printf("今天星期三\n");
//		break;
//	case 4:
//		printf("今天星期四\n");
//		break;
//	case 5:
//		printf("今天星期五\n");
//		break;
//	case 6:
//		printf("今天星期六\n");
//		break;
//	case 7:
//		printf("今天星期天\n");
//		break;
//	}
//	return 0;
//}
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("今天工作日\n");
//		break;
//	case 6:
//	case 7:
//		printf("今天休息日\n");
//		break;
//	default :
//		printf("输入错误哦亲~\n");
//	}
//	return 0;
//}
//int main()
//{	
//	int i = 1;
//
//	while (i <= 10)
//	{
//		printf("%d ",i);
//		i++;
//	}
//		return 0;
//}
//
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	while (i) {
//
//		printf("%d", i % 10);
//		i /= 10;
//	}
//}
//
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		printf("%d", i);
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//			sum += i;
//	}
//	printf("%d\n", sum);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 0; i <= 100; i+=3)
//	{
//		sum += i;
//	}
//	printf("%d\n", sum);
//	return 0;
//
//}
//int main()
//{
//	int i = 1;
//	do
//	{
//		printf("%d", i);
//		i++;
//	} while (i <= 0);
//
//	return 0;
//}
//int main()
//{
//	int sum = 0;
//	scanf("%d", &sum);
//	int cnt = 0;
//	do
//	{
//		sum /= 10;
//		cnt++;
//	} while (sum);
//		printf("%d\n", cnt);
//	return 0;
//}
//int main()
//{
//	int n = 1;
//	while (n <= 10)
//	{
//		if (n == 5)
//			break;
//		printf("%d", n);
//		n++;
//	}
//}
//int main()
//{
//	int n = 1;
//	while (n <= 10)
//	{
//		n++;
//		if (n == 5)
//			continue;
//		printf("%d", n);
//		
//	}
//	return 0;
//}
//int main()
//{
//	int n = 1;
//	while (n <= 10)
//	{
//		n++;
//		if (n == 5)
//			break;
//		printf("%d", n);
//
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; )
//	{
//		if (i == 5)
//			continue;
//		printf("%d", i);
//		i++;
//
//	}
//	return 0;
//}
//int main()
//{
//	for (;;)
//	{
//		printf("hehe\n");
//	}
//	return 0;
//}
int main()
{
	int i = 1;
	do
	{
		if (i == 5)
			continue;
		printf("%d", i);
		i++;
	} while (i <= 10);
	return 0;
}