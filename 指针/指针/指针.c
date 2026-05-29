	#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
//int main()
//{
//	printf("%d\n", strlen("ats\n012\1\\"));
//	printf("%d\n", strlen("ats\012\1\\\n"));
//	return 0;
//}
//内存单元的编码 ==地址 ==指针 1byte = 8bite
//int main()
//{
//	int a = 10;
//	printf("%p", &a);//%p是专门用来打印地址的
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	printf("%p", p);
//	return 0;
//
//}
//int main()
//{
//	char ch[] = "sk";
//	char* pc = &ch;
//}
//int main()
//{
//	int a = 100;
//	int* pa = &a;
//	*pa = 0;
//	printf("%d\n", *pa);
//	printf("%d\n", a);
//	return 0;
//}
//int main()
//{
//	int n = 0x11223344;
//	int m = 0x22334455;
//	int* pi = &n;
//	char* pc = &m;
//	*pc = 0;
//	*pi = 0;
//	return 0;
//}
//int main()
//{
//	int n = 10;
//	char* pc = &n;
//	int* pi = &n;
//	printf("%p\n", &n);
//	printf("%p\n", pc);
//	printf("%p\n", pc+1);
//	printf("%p\n", pi);
//	printf("%p\n", pi+1);
//}
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	char* pc = &a;
//	printf("%p\n", &a);
//	printf("%p\n", pa);
//	printf("%p\n", pc);
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	void* pc = &a;
//	void* pa = &a;
//	pa = 10;
//	pc = 0;
//
//	printf("%p\n", &a);
//	printf("%p\n", pa);
//	printf("%p\n", pc);
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = &arr[0];
//	int i = 0 ;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 9; 0<=i&&i < sz; i--)
//	{
//		printf("%d\n", (*p + i));
//	}
//	return 0;
//}
//int my_strlen(char* s)
//{
//	char* p = s;
//	while (*p != '\0')
//	{
//		p++;
//	}
//		return p - s;
//	
//}
//int main()
//{
//	char a[100];
//	scanf("%s", a);
//	printf("%d\n",my_strlen(a));
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = &arr[0];
//	int sz = sizeof(arr) / sizeof arr[0];
//	while (p <arr + sz)
//	{
//		printf("%d\n", *p);
//		p++;
//	}
//	return 0;
//}
//int main()
//{
//	 int m = 20;
//	const int* pc = m;
//	m = 20;
//	printf("%d", m);
//	return 0;
//}
//void test2()
//{
//	int n = 10;
//	int m = 20;
//	const int* p = &m;
//	*p = 20;
//	p = &m;
//}//const放在*左边，锁住的是元素，即指针指向的内容
//void test3()
//{
//	int n = 10;
//	int m = 20;
//	int* const p = &n;
//	*p = 20;
//	p = &m；
//}//const放在*右边，锁住的是地址，即指针不可以再改变地址了
//void test4()
//{
//	int n = 10;
//	int m = 20;
//	const int* const p = &n;
//	*p = 20;
//	p = &m;
//}//上述说的两个条件可以同时成立

//int main()
//{
//	int* p;//这里没有初始化，导致指向的地址取20，这个地址是随机的，很容易造成越界访问
//	*p = 20;
//	return 0;
//}
//越界访问如下代码所示
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = &arr[0];
//	int  i = 0;
//	for (i = 0; i <= 11; i++)
//	{
//		* (p++) = i;//这里是由下标为0的元素开始依次到10全部赋值为i，i++，但是一共进行了11次，而arr数组只有10个元素，所以在最后一个的时候越界访问了，将某不知名地址赋值i（11）了
//	}
//	return 0;
//}
//int* test()
//{
//	int n = 100;
//	return n;
//}
//int main()
//{
//	int* p = test();
//	printf("%p\n", *p);//这里是在test函数上创造了一个关于n的临时地址然后将地址蕴含的数值赋值给*p，但是函数运行完后就销毁了，所以*p指向的地址为空
//	return 0;
//}
//指针初始化
//如果我们知道指针要指向哪里的话就直接给它地址让其指向即可，若不知，空有一个指针，则可令其赋值NULL 是0的意思，这个地址无法使用，是让指针被架空无法作用
//
// 	int*p = NULL；
//指针不在使用的时候需要及时将指针赋值NULL避免越界
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int  i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p++) = i;
//	}//此时p已经越界，再使用会出问题，这里将p赋值为NULL
//	p = NULL;
//	p = &arr[0];//重新将p赋值arr首元素地址
//	if (p != NULL)
//	{
//		;
//	}
//	return 0;
//}
//关于assert断言的使用
//assert.h头文件定义了assert（），如果程序运行的时候不符合指定条件就报错终止运行，不报错则正常运行
//#define DEBUG
//assert(p != NULL);
//strlen 统计的是字符串\0前面的字符个数最后返回长度
//int my_strlen(const char* str)
//{
//	int count = 0;
//	assert(str!=NULL);
//	while (*str!='\0')
//	{
//		str++;
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int len = my_strlen("abcdef");
//	printf("%d\n", len);
//	return 0;
//}
//int exchange(int*x,int* y)
//{
//	int* p = x;
//	int* l = y;
//	int k = 0;
//	 k = *p;
//	*p = *l;
//	*l = k;
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	exchange(&a,& b);
//	printf("%d %d", a, b);
//	return 0;
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%d\n", sizeof(arr));
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%p\n", arr);
//	printf("%p\n", &arr);
//	printf("%p\n", &arr[0]);
//	printf("\n");
//
//	printf("%p\n", arr);
//	printf("%p\n", arr+1);
//	printf("%p\n", &arr);
//	printf("%p\n", &arr+1);
//	printf("%p\n",&arr[0]);
//	printf("%p\n",&arr[0]+1);
//
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr;
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", p + i);
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", *(p + i));
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr;
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", p[i]);  
//	}
//	return 0;
//}
//void test(int arr[])
//{
//	int sz2 = sizeof(arr) / sizeof arr[0];
//	printf("该函数长度为%d\n", sz2);
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int sz1 = sizeof(arr) / sizeof(arr[0]);
//	test(arr);
//	printf("%d", sz1);
//	return 0;
//}
//void test(int* arr)
//{
//	printf("%d\n",sizeof(arr));
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10};
//	int sz1 = sizeof(arr) / sizeof(arr[0]);
//	test(arr);
//	printf("%d", sz1);
//	return 0;
//}
//冒泡排序
//void bubble_sort(int arr[],int sz)//从小到大排序
//{
//	int i = 0;
//	for (i = ; i < sz - 1; i++)// 1 5 7 6 8
//	{
//		int j = 0;
//		for (j = 1; j <sz; j++)//2
//		{
//
//			if (arr[j-1] > arr[j])
//			{
//				int a = arr[j];
//				arr[j] = arr[j-1];
//				arr[j-1] = a;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[10] = {5,4,6,3,1,10,2,9,7,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//void bubble_sort(int arr[], int sz)//从小到大排序
//{
//	int i = 0;
//	
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;
//		int j = 0;
//		
//		for (j = 1; j < sz-i; j++)
//		{
//		
//			if (arr[j - 1] > arr[j])
//			{
//				flag = 0;
//				int a = arr[j];
//				arr[j] = arr[j - 1];
//				arr[j - 1] = a;
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}
//int main()
//{
//	int arr[10] = { 5,4,6,3,1,10,2,9,7,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	int** ppa = &pa;
//	return 0;
//}
//int main()
//{
//	int arr1[5] = { 1,2,3,4,5 };
//	int arr2[5] = { 1,2,3,4,6 };
//	int arr3[5] = { 1,2,3,4,7 };
//	int* arr[3] = { arr1,arr2,arr3 };
//	int i, j;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	char p = 'w';
//	char* pa = &p;
//	*pa = 'w';
//	return 0;
//}
//int main()
//{
//	const char* pstr = "hello bit.";
//	printf("%s\n", pstr);
//	return 0;
//}

//int main()
//{
//	char str1[] = "hello world.";
//	char str2[] = "hello world.";
//	const char* str3 = "hello world.";
//	const char* str4 = "hello world.";
//	if (str1 == str2)
//		printf("str1和str2相同\n");
//	else
//		printf("str1和str2不同\n");
//	if (str3 == str4)
//		printf("str3和str4相同");
//	else
//		printf("str3和str4不同");
//	return 0;
//}
//int* p[10];
//int (*p)[10];
//void test(int(* p)[5], int r, int c)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < r; i++)
//	{
//		for (j = 0; j < c; j++)
//			printf("%d ", *(*(p + i) + j));//*(p+i)是直接跳过一行一维数组 后面的+j则是在一维数组中跳过j个元素
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[][5] = { 1,2,3,4,5,2,3,4,5,6,3,4,5,6,7 };
//	test(arr,3,5);
//	return 0;
//}
//void test(int(*p)[5], int r, int c)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < r; i++)
//	{
//		for (j = 0; j < c; j++)
//			printf("%d ", *(*(p + i) + j));//*(p+i)是直接跳过一行一维数组 后面的+j则是在一维数组中跳过j个元素
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[][5] = { { 1,2,3,4,5 } ,{ 2, 3, 4, 5, 6 }, {3, 4, 5, 6, 7 } };
//	test(arr, 3, 5);
//	return 0;
//}
//void test()
//{
//	printf("hehe\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//void (*pf1)() = &test;
//void (*pf2)() = test;
//int(*pf3)(int x, int y) = Add;
//int(*pf4)(int x, int y) = &Add;
//int main()
//{
//	pf1();
//	printf("%d\n", pf3(8, 5));
//	printf("%d\n", (*pf3)(3, 5));
//}
//((void(*)())0)()
//void(*signal(int, void(*)(int)))(int);
//typedef unsigned int uint；
//+

//int Add(int x, int y)
//{
//	return x + y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//menu()
//{
//	printf("************0.exit****************\n");
//	printf("************1.Add ***************\n");
//	printf("************2.Sub *****************\n");
//	printf("************3.Mul ***************\n");
//	printf("************4.Div ***************\n");
//	printf("清输入数字以进行你所需要的操作\n");
//}
//
//int main()
//{
//	
//	int input = 0;
//	int x, y;
//	do
//	{
//		menu();
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			
//			printf("退出程序\n");
//			break;
//		case 1:
//			printf("请输入你需要操作的两个数\n");
//			scanf("%d %d", &x, &y);
//			int p = Add(x, y);
//			printf("%d\n", p);
//			break;
//		case 2:
//			printf("请输入你需要操作的两个数\n");
//			scanf("%d %d", &x, &y);
//			int o =Sub(x, y);
//			printf("%d\n", o);
//			break;
//		case 3:
//			printf("请输入你需要操作的两个数\n");
//			scanf("%d %d", &x, &y);
//			int i =Mul(x, y);
//			printf("%d\n", i);
//			break;
//		case 4:
//			printf("请输入你需要操作的两个数\n");
//			scanf("%d %d", &x, &y);
//			int u =Div(x, y);
//			printf("%d\n", u);
//			break;
//		default:
//			printf("输入错误，请重新输入\n");
//			break;
//		}
//	}
//	while (input != 0);
//	return 0;
//	
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//menu()
//{
//	printf("************0.exit****************\n");
//	printf("************1.Add ***************\n");
//	printf("************2.Sub *****************\n");
//	printf("************3.Mul ***************\n");
//	printf("************4.Div ***************\n");
//	printf("清输入数字以进行你所需要的操作\n");
//}
//
//int main()
//{
//
//	int input = 0;
//	int x, y;
//	int (*p[5])(int x, int y) = { 0,Add,Sub,Mul,Div };
//	do
//	{
//		menu();
//		scanf("%d", &input);
//		if (input <= 4 && input >= 1)
//		{
//			printf("请输入你想操作的两个数字\n");
//			scanf("%d %d", &x, &y);
//			int r = (*p[input])(x, y);
//			printf("操作结果 = %d\n", r);
//		}
//		else if (input == 0)
//			printf("退出计算\n");
//		else
//			printf("输入错误，请重新输入\n");
//	} while (input != 0);
//	return 0;
//
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//menu()
//{
//	printf("************0.exit****************\n");
//	printf("************1.Add ***************\n");
//	printf("************2.Sub *****************\n");
//	printf("************3.Mul ***************\n");
//	printf("************4.Div ***************\n");
//	printf("清输入数字以进行你所需要的操作\n");
//}
//int calc(int(*pf)(int,int))
//{
//	int k = 0;
//	int t, y;
//	printf("请输入你想操作的数字\n");
//	scanf("%d %d", &t, &y);
//	k = pf(t, y);
//	printf("%d\n", k);
//
//}
//
//int main()
//{
//
//	int input = 0;
//	int x, y;
//	int (*p[5])(int x, int y) = { 0,Add,Sub,Mul,Div };
//	do
//	{
//		menu();
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			printf("退出游戏");
//			break;
//		case 1:
//			calc(Add);
//			break;
//		case 2:
//			calc(Sub);
//			break;
//		case 3:
//			calc(Mul);
//			break;
//		case 4:
//			calc(Div);
//			break;
//		default:
//			printf("输入错误，请重新选择\n");
//		}
//	} while (input != 0);
//	return 0;
//
//}
//int fac(int a)
//{
//    int c = 0;
//    int d = 0;
//    if (a == 1 || a == 2)
//    {
//        return a;
//    }
//    int b = a;
//    if (a >= 3)
//    {
//        
//    }
//
//}
//
//int  main()
//{
//    int a = 0;
//    scanf("%d", &a);
//    int result = fac(a);
//    printf("%d", result);
//    return 0;
//}//这个方法不对
//int int_cmp(const void* p1, const void* p2)
//{
//	return (*(int* )p1 - *(int*)p2);//如果大于0 就把第一个元素放后面
//}
//int main()
//{
//	int arr[10] = { 1,3,5,7,9,2,4,6,8,0, };
//	int i = 0;
//	//void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
//	//           首元素地址   元素个数      单元素大小      指向自己写的函数的指针
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), int_cmp);
//		for (i = 0; i < sizeof(arr) / sizeof(arr[0]);i++)
//		{
//			printf("%d ", arr[i]);
//		}
//		printf("\n");
//		return 0;
//}
//struct stu
//{
//	char name[20];
//	int age;
//};
//int cmp_by_age(const void* age1, const void* age2)//比较一个人的年纪大小
//{
//	return((struct stu*)age1)->age  - ((struct stu*)age2)->age;//如果大于0就把第一个元素放后面
//}
//int cmp_by_name(const void* name1, const void* name2)//比较字符串首字符大小
//{
//	strcmp(((struct stu*)name1)->name, ((struct stu*)name2)->name);
//}
//void test2()//按照年龄排序大小
//{
//	struct stu s[] = { {"zhanhgsan",20},{"lisi",18},{"wangwu",28} };
//	int sz = (sizeof(s) / sizeof(s[0]));
//	qsort(s, sz, sizeof(s[0]), cmp_by_age);
//	printf("%s,%d\n", s[0].name, s[0].age);
//	printf("%s,%d\n", s[1].name, s[1].age);
//}
//void test3()//按照名字首字符大小排序
//{
//	struct stu s[] = { {"zhanhgsan",20},{"lisi",18},{"wangwu",28} };
//	int sz = (sizeof(s) / sizeof(s[0]));
//	qsort(s, sz, sizeof(s[0]), cmp_by_name);
//	printf("%s,%d\n", s[0].name, s[0].age);
//	printf("%s,%d\n", s[1].name, s[1].age);
//}
//int main()
//{
//	test2();
//	test3();
//	return 0;
//}
//qsort函数的模拟实现
//int cmp(const void* p1, const void* p2)//比较两个元素谁大谁小
//{
//	return (*(int*)p1 - *(int*)p2);
//}
//
//
//int swap(void* p1, void* p2, int size)//以字节为基本单位将要调换的元素全部调换
//{
//	int i = 0;
//	for (i = 0; i < size; i++)//这里的size是字节大小，方便求出一个元素的字节大小
//	{
//		char temp = *((char*)p1 + i);
//		*((char*)p1+i) = *((char*)p2+i );//这里对单一一个元素逐字节交换
//		*((char*)p2+i) = temp;
//	}
//}
//void bubble(void* base, int count, int size, int(*cmp)(void*, void*))
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < count - 1; i++)//这里的count是元素个数，用count做循环终止是为了可以把数组中的每一个元素都进行交换
//	{
//		for (j = 0; j < count - i - 1; j++)
//		{
//			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)//在主函数中会调用cmp比较两个元素谁大谁小，是否需要交换
//			{
//				swap((char*)base + j * size, (char*)base + (j + 1) * size, size);//如果需要交换，将两个元素逐字节进行交换(以swap为基础函数，进行逐字节交换)
//			}
//		}
//	}
//}




//int main()
//{
//	int arr[10] = { 1,3,5,7,9,2,4,6,8,0 };
//	int i = 0;
//	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), cmp);//调用bubble函数，传递首元素地址给它，还有元素个数，
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)			//单元素字节大小，以及用以比较的方式（用函数实现）
//	{															
//		printf("%d ", arr[i]);									//这里打印被排列好的元素，以验证效果
//	}
//	printf("\n");
//	return 0;
//}





//sizeof和strlen的对比
//int main()
//{
//	int a = 10;
//	printf("%d\n", sizeof(a));//4/8
//	printf("%d\n", sizeof a);//4/8
//	printf("%d\n", sizeof(int));//4/8
//	return 0;
//}


//
//int main()
//{
//	char arr1[3] = { 'a', 'b', 'c' };
//	char arr2[] = "abc";
//	printf("%d\n", strlen(arr1));//随机值
//	printf("%d\n", strlen(arr2));//3
//	printf("%d\n", sizeof(arr1));//3
//	printf("%d\n", sizeof(arr2));//4
//	return 0;
//}




//int main()
//{
//	int a[] = { 1,2,3,4 };
//	printf("%d\n", sizeof(a));//16
//	printf("%d\n", sizeof(a + 0));//4/8
//	printf("%d\n", sizeof(*a));//4
//	printf("%d\n", sizeof(a + 1));//4/8
//	printf("%d\n", sizeof(a[1]));//4
//	printf("%d\n", sizeof(&a));//4/8
//	printf("%d\n", sizeof(*&a));//16
//	printf("%d\n", sizeof(&a + 1));//4/8
//	printf("%d\n", sizeof(&a[0]));//4/8
//	printf("%d\n", sizeof(&a[0] + 1));//4/8
//	return 0;
//}




//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%d\n", sizeof(arr));//6
//	printf("%d\n", sizeof(arr + 0));//4
//	printf("%d\n", sizeof(*arr));//1
//	printf("%d\n", sizeof(arr[1]));//1
//	printf("%d\n", sizeof(&arr));//4/8
//	printf("%d\n", sizeof(&arr + 1));///4/8
//	printf("%d\n", sizeof(&arr[0] + 1));//4/8
//}




//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", sizeof(arr));//7
//	printf("%d\n", sizeof(arr + 0));//4/8
//	printf("%d\n", sizeof(*arr));//1
//	printf("%d\n", sizeof(arr[1]));//1
//	printf("%d\n", sizeof(&arr));//4/8
//	printf("%d\n", sizeof(&arr + 1));//4/8
//	printf("%d\n", sizeof(&arr[0] + 1));///4/8
//	return 0;
//}






//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%d\n", strlen(arr));//随机值
//	printf("%d\n", strlen(arr + 0));//随机值
//	//printf("%d\n", strlen(*arr));//a的ASCII码给他当地址检索了，很容易崩
//	//printf("%d\n", strlen(arr[1]));//b的ASCII码给它当地址检索，也很容易崩
//	printf("%d\n", strlen(&arr));//随机值
//	printf("%d\n", strlen(&arr + 1));//随机值-6
//	printf("%d\n", strlen(&arr[0] + 1));//随机值-1
//}






//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", strlen(arr));//6
//	printf("%d\n", strlen(arr + 0));//6
//	//printf("%d\n", strlen(*arr));//崩溃
//	//printf("%d\n", strlen(arr[1]));//崩溃
//	printf("%d\n", strlen(&arr));//6
//	printf("%d\n", strlen(&arr + 1));//未知，易崩溃
//	printf("%d\n", strlen(&arr[0] + 1));//5
//	return 0;
//}






//int main()
//{
//	char* p = "abcdef";
//	printf("%d\n", sizeof(p));//4/8
//	printf("%d\n", sizeof(p + 1));//4/8
//	printf("%d\n", sizeof(*p));//1
//	printf("%d\n", sizeof(p[0]));//1
//	printf("%d\n", sizeof(&p));//4/8
//	printf("%d\n", sizeof(&p + 1));//4/8
//	printf("%d\n", sizeof(&p[0] + 1));//4/8
//	return 0;
//}
// 





//int main()
//{
//	char* p = "abcdef";
//	printf("%d\n", strlen(p));//6
//	printf("%d\n", strlen(p + 1));//5
//	printf("%d\n", strlen(*p));//把a的ASCII码给了它让它检索，可能崩溃
//	printf("%d\n", strlen(p[0]));//把a的ascii码给它
//	printf("%d\n", strlen(&p));//未知
//	printf("%d\n", strlen(&p + 1));//未知
//	printf("%d\n", strlen(&p[0] + 1));//5
//	return 0;
//}
// 






//int main()
//{
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));//48
//	printf("%d\n", sizeof(a[0][0]));//4
//	printf("%d\n", sizeof(a[0]));//16 
//	printf("%d\n", sizeof(a[0] + 1));//4/8 a[0][1]的地址
//	printf("%d\n", sizeof(*(a[0] + 1)));//4 a[0][1]的大小
//	printf("%d\n", sizeof(a + 1));//4/8
//	printf("%d\n", sizeof(*(a + 1)));//16 第二行的大小
//	printf("%d\n", sizeof(&a[0] + 1));//4/8  a[1]的地址
//	printf("%d\n", sizeof(*(&a[0] + 1)));//16
//	printf("%d\n", sizeof(*a));//16
//	printf("%d\n", sizeof(a[3]));//16
//	return 0;
//}//
//这一题问题较大，可以深入讲一下




	//int main()
	//{
	//	int a[5] = { 1, 2, 3, 4, 5 };
	//	int* ptr = (int*)(&a + 1);
	//	printf("%d,%d", *(a + 1), *(ptr - 1));// 2,5
	//	return 0;
	//}



//struct Test//假设结构体大小是20字节
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p = (struct Test*)0x100000;
//int main()
//{
//	printf("%p\n", p + 0x1);//0x100014
//	printf("%p\n", (unsigned long)p + 0x1);//0x100001 这里的0x1是十六进制的1
//	printf("%p\n", (unsigned int*)p + 0x1);//0x100004
//	return 0;
//}

//
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };//这是逗号表达式，只取结果，由于前面的0，2.4都无实际意义和结果，所以每个逗号表达式的结果是后面的1，3，5，前面的0，2，4被初始化为0，所以实际数组是
//	int* p;//{1,3}.{3,0},{0,0};
//	p = a[0];
//	printf("%d", p[0]);//1
//	return 0;
//}




//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	return 0;
//}



//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));//10,5
//	return 0;
//}



//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//	printf("%s\n", **++cpp);
//	printf("%s\n", *-- * ++cpp + 3);
//	printf("%s\n", *cpp[-2] + 3);
//	printf("%s\n", cpp[-1][-1] + 1);
//	return 0;
//}



