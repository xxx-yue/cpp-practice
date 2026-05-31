//#include<stdio.h>
//int main()
//{
//	printf("hehe\n");
//	printf("haha\n");
//	return 0;
//}
//void main()
//{
//	printf("hello world\n");
//}
//int main()
//{
//	printf("hello C\n");
//	printf("我喜欢C语言\n");
//		return 0;
//}
//int main()
//{
//	printf("%d\n", 55559);
//	printf("%c\n", 'x');
//	printf("%f\n", 3.14);
//	return 0;
//}
//int main()
//{
//	printf("%c\n", 'a');
//	printf("%d\n", 'a');
//	printf("%c\n", 'a' - 32);
//	printf("%d\n",'0');
//	printf("%c\n", '0');
//	return 0;
//}
//int main()
////{
////	int i = 0;
//	for (i = 32; i <= 127; i++)
//	{
//		printf("%c", i);
//	}
//	return 0;
//}
//int main()
//{
//	printf("hehe\n");
//	return 0;
//}
//int main()
//{
//	"abcdef";
//	return 0;
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = { 'a','b','c','d','e','f',};
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//	return 0;
//
//}
//int main()
//{
//	printf("abc\ndef\n");
//	printf("are you ok??)\n");
//	// 格式字符串中直接加入\n，确保输出后换行
//	printf("%c\n", '\'');  // 输出单引号后立即换行
//	printf("%s\n", "abc");
//	printf("%s\n", "a");
//	printf("%s\n", "\"");
//	return 0;
//}
//int main()
//{
//	printf("c:\\test\\test.c");
//int main()
//{
//	printf("\a");
//	return 0;
//}
//
//int main()
//{
//	printf("abcd\tef\n");
//	printf("xxxxxxxxxxxxxxxxxx");
//	return 0;
//}
//int main()
//{
//	printf("%c\n",'\130')
//}
#include<stdio.h>
#include<string.h>
//int main()
//{
//	
//}
//int main()
//{
//	int len = strlen("c:\\test\\129\\test.c");
//	printf("%d\n", len);
//	printf("%c\n",'\130');
//	printf("%c\n", '\x30');
//	return 0;
//}
//int main()
//{
//	:
//	return 0
//}
//
//
//注释的第一种方法 按“/”然后按“*”即/*
/**/
//short [int ]短整型
//int 整型
//long [int] 长整型
//long long int  更长的整型
//浮点型有 float double long double
//布尔类型变量取值 true或者false
//
//int main()
//{
//	printf("%zd\n", sizeof(bool));
//	printf("%zd\n", sizeof(char));
//	printf("%zd\n", sizeof(short));
//	printf("%zd\n", sizeof(int));
//	printf("%zd\n", sizeof(long));
//	printf("%zd\n", sizeof(long long));
//	printf("%zd\n", sizeof(float));
//	printf("%zd\n", sizeof(double));
//	printf("%zd\n", sizeof(long double));
//}
//int main()
//{
//	short s = 10;
//	int num = 100;
//	printf("%zd\n", sizeof(s = num + 2));
//	printf("%d\n", s);
//	return 0;
//}
//int main()
//{
//	signed int num;
//	unsigned int age:
//	signed char ch1 = 'x'
//		unsigned char ch2;
//	return 0;
//
//}
//int main()
//{
//	int num = 10;
//	num = -10;
//	//对于int类型的数据打印应该使用%d
//	printf("%d\n", num);
//	
//	unsigned int num2 = 100;
//	num2 = -100;
//	//对于unsigned int 类的数据打印应该用%u
//	printf("%u\n", num2);
//	return 0;
//
//}
//
//int num2 = 100;
//void test()
//{
//	printf("test():%d\n", num2);
//}
//int main()
//{
//	
//	{
//		int num2 = 10;//局部变量
//		printf("%d\n", num2);
//		}
//	printf("%d\n", num2);
//	test();
//	return 0;
//}
//
//
//
//printf("%d\n", c);printf("%d\n", c);
//{
	//{
	//	printf("%d\n", 6 / 4);
	//	printf("%f\n", 6.0 / 4);
	//	printf("%f\n", 6 / 4.0);
	//	//  “/”除号的两端如果都是整数，执行的是整数除法
	//	// “/”除号两端如果出现了浮点数（即小数），才执行的是浮点数除法
	//	return 0;
	//
	//}
	/*int a = 10;
	a = a + 5;
	a += 5;
	printf("%d\n", a);
	return 0;
}*/
//
//int main()
//{
//	int a = 10;
//	int b = a++;
//	printf("%d\n", a);
//	printf("%d\n", b);
//	return 0;
//}\
//int main ()
//
int main()
{
	int a = +10;
	printf("%d\n", a);
	printf("%d\n", -a);
	return 0;
}