#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include <limits.h>
#include <stdlib.h>
#include<math.h>
//void main()
//{
//	printf("%s\n%d\n%s\n%s\n",__FILE__, __LINE__, __DATE__, __TIME__);
//}
//}


//#define name stuff
//#define name stuff
//#define square(x) x*x//8+1*8+1
//int main()
//{
//	printf("%d", square(8+1));
//}
//#define double(x) x+x//2*5+9+5+9  15+81
//int main()
//{
//	printf("%d", 2*double(5 + 9));
//}

//#define MAX(a,b) (a>b?a:b)
//int main()
//{
//	int a = 8;//9,3,10,3
//	int b = 2;
//	printf("%d\n", MAX(++a, ++b));
//	printf("%d\n", a);
//	printf("%d\n", b);
//	return 0;
//}

//#define MALLOC(num,type)\
//	(type*)malloc((num)*sizeof(type))
//
//int main()
//{
//	int * p1 = MALLOC(5,int);
//	return 0;
//}

//#define PRINT(n)printf("the value of "#n" is %d",n);
//int main()
//{
//	int a = 10;
//	/*printf("the value of"" a ""is %d", a);*/
//	PRINT(a);
//}

//#define GENERIC_MAX(type)\
//type type##_max(type x,type y)\
//{\
//	return(x > y ? x : y);\
//}
//GENERIC_MAX(int);
//GENERIC_MAX(float);
//int main()
//{
//	int m = int_max(2, 3);
//	printf("%d\n", m);
//	float fm = float_max(3.5f, 4.5f);
//	printf("%f\n", fm);
//	return 0;
//}

//#define name "what"
//int main()
//{
//	printf("%s",name);
//#undef name
//	printf("%s",name);
//}


//#define __DEBUG__
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//#ifdef __DEBUG__
//		printf("%d\n", arr[i]);
//#endif 
//	}
//	return 0;
//}

//#
// #if defDEBUG

