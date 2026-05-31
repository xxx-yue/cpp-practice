#include<iostream>
using namespace std;
//class A
//{
//public:
//	A(int a = 0)
//		:_a1(a)
//	{
//		cout << "A构造_a1" << endl;
//	}
//	A(const A& aa)
//		:_a1(aa._a1)
//	{
//		cout << "A拷贝构造" << endl;
//	}
//	A& operator=(const A& aa)
//	{
//		cout << "A赋值重载" << endl;
//		if (this != &aa)
//		{
//			_a1 = aa._a1;
//		}
//		return *this;
//	}
//	~A()
//	{
//		cout << "~A" << endl;
//	}
//private:
//	int _a1;
//};
//void f1(A aa)
//{
//
//}
//A f2()
//{
//	A aa;
//	return aa;
//}
//int main()
//{
//	/*A aa1;
//	f1(aa1);
//	cout << endl;*/
//	/*f1(1);*/
//	/*f1(A(2));*/
//	//f2();
//	//cout << endl;
//	A aa2 = f2();
//}

//int main()
//{
//	int* ptr1 = new int;
//	int* ptr2 = new int(10);
//	int* ptr3 = new int[10];
//	int* ptr4 = new int[10] {1, 2, 3, 4, 5};
//	delete ptr1;
//	delete ptr4;
//	delete ptr3;
//	delete ptr2;
//
//}
class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A构造_a1" << endl;
	}
	~A()
	{
		cout << "A析构_a1" << endl;
	}
private:int _a;
};
int main()
{
	//A* p1 = (A*)malloc(sizeof(A));
	//A* p2 = new A(1);
	//
	//delete p2;
	//free(p1);
	//
	//int* p3 = (int*)malloc(sizeof(int));
	//int* p4 = new int;
	//free(p3);
	//delete p4;
	A* p5 = (A*)malloc(sizeof(A) * 10);
	A* p6 = new A[10];
	//new是调用operator new,然后一依次为介体调用malloc,然后再构造
	//delete是先祈构,再调用operator delete ,然后以此为介体调用free
}