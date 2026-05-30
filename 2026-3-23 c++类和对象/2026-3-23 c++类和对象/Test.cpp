#include<iostream>
using namespace std;
#include"Date.h"
//class Date
//{
//public:
//	Date()//无参构造函数
//	{
//		_year = 1;
//		_month = 1;
//		_day = 1;
//	}
//
//	//Date(int year = 1, int month = 1, int day = 1)//全缺省构造函数
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//	//以及编译器自带构造函数,这三种构造函数只能同时存在一个
//	Date(int year, int month, int day)//带参构造函数
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:int _year;
//	   int _month;
//	   int _day;
//
//};
//int main()
//{
//	Date d1;
//	Date d2(2026, 3, 23);
//	d1.print();
//	d2.print();
//	Date d3;
//	d3.print();
//}
//typedef int STDataType;
//class Stack
//{
//public:
//	Stack(int n = 4)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * n);
//		if (_a == nullptr)
//		{
//			perror("malloc failed");
//			return;
//		}
//		_capacity = n;
//		_top = 0;
//	}
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};
//
//class MyQueue
//{
//public:
//
//private:
//	Stack pushst;
//	Stack popst;
//};
//int main()
//{
//	MyQueue mq;
//	return 0;
//}
//typedef int STDataType;
//class Stack
//{
//public:
//	Stack(int n = 4)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * n);
//		if (_a == nullptr)
//		{
//			perror("malloc failed");
//			return;
//		}
//		_capacity = n;
//		_top = 0;
//	}
//	~Stack()
//	{
//		cout << "~Stack" << endl;
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};
//class MyQueue
//{
//public:
//
//private:
//	Stack pushst;
//	Stack popst;
//};
//int main()
//{
//	Stack st;
//	MyQueue mq;
//
//}
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	//Date d2(&d1);
//	Date(Date* d)
//	{
//		_year = d->_year;
//		_month = d->_month;
//		_day = d->_day;
//	}
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Func1(Date d)
//{
//	cout << &d << endl;
//	d.print( );
//}
//Date& Func2()
//{
//	Date tmp(2033, 3, 33);
//	tmp.print();
//	return tmp;
//}
//int main()
//{
//	Date d1(2029,6,9);
//	Func1(d1);
//	cout << &d1 << endl;
//	Date d2(&d1);
//	d1.print();
//	d2.print();
//	Date d4 = d1;
//	d4.print();
//	Date d5 = Func2();
//	d5.print();
//}
//class Stack
//{
//public:
//	Stack(int n = 4)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * n);
//		if (_a == nullptr)
//		{
//			perror("malloc failed申请空间失败");
//			return ;
//		}
//		_capacity = n;
//		_top = 0;
//	}
//	Stack(const Stack& st)
//	{
//		cout << "Stack(const Stack & st)" << endl;
//		_a = (STDataType*)malloc(sizeof(STDataType) * st._capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc 申请空间失败");
//				return ;
//		}
//		memcpy(_a, st._a, sizeof(STDataType) * st._capacity);
//		_top = st._top;
//		_capacity = st._capacity;
//	}
//	void Push(STDataType x)
//		{
//			if (_top == _capacity)
//			{
//				int newcapacity = _capacity * 2;
//				STDataType* tmp = (STDataType*)realloc(_a, newcapacity *
//					sizeof(STDataType));
//				if (tmp == NULL)
//				{
//					perror("realloc fail");
//					return;
//				}
//				_a = tmp;
//				_capacity = newcapacity;
//			}
//			_a[_top++] = x;
//		
//		}
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};
//
//void func1(const Stack& st)
//{
//
//}
//
//class myqueue
//{
//public:
//private:
//	Stack popst;
//	Stack pushst;
//};
//int main()
//{
//	Stack s1;
//	s1.Push(1);
//	s1.Push(2);
//	func1(s1);
//	myqueue s2;
//	Stack st2(s1);
//	Stack st3 = s1;
//	myqueue q1;
//	myqueue q2(q1);
//	myqueue q3 = q1;
//	myqueue qq;
//	return 0;
//}
/////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


//class A
//{
//public:
//	void func()
//	{
//		cout << "A::func( )" << endl;
//	}
//};
//typedef void (A::* PF)();
//int main()
//{
//	void (A:: * pf)() = nullptr;
//	PF pf = nullptr;
//	pf = &A::func;
//	A aa;
//	(aa.*pf)();
//}
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void print()
//	{
//		cout << _year << " " << _month << " " << _day << endl;
//	}
//	bool operator==(const Date& d)
//	{
//		return
//		_year == d._year&&
//		_month == d._month&&
//		_day == d._day;
//	}
//	Date& operator++()
//	{
//		cout << "前置++" << endl;
//		return *this;
//	}
//	Date& operator++(int)
//	{
//		Date tmp;
//		cout << "后置++" << endl;
//		return tmp;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date s1;
//	Date& s2=s1++;
//	s2.print();
//	return 0;
//}

//class Date
//{
//public:
//	//缺省构造函数
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//赋值重载操作符
//	Date& operator=(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		return *this;
//	}
//	//拷贝构造
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void print()
//	{
//		cout << _year << " " << _month << " " << _day << endl;
//	}
//	
//	Date operator+(int day);
//	Date operator-(int day);
//	int operator- (const Date & d);
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//friend bool operator==(const Date& d1,const Date&d2)
//{
//	return d1._year == d2._year && d1._month == d2._month && d3._day == d3._day;
//}
//Date d2(d1)//用d1拷贝构造d2,然后调用构造函数Date(Date d),此时形参d不存在,需要用d1实参创建形参d,即Date d(d1),又调用构造函数Date(Date d),此时形参d不存在,要用
////d1实参创建形参d,即Date d(d1)
//class Date
//{
//public:
//	int months[13] = { -1.31,28,31,30,31,30,31,31,30,31,30,30,31};
//	int getday(int year, int month)
//	{
//		if (months[month] == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
//			return 29;
//		return months[month];
//	}
//	Date(int day=1,int month=1 ,int year=1)
//	{
//		_day = day;
//		_month = month;
//		_year = year;
//	}
//	Date& operator=(const Date& d)
//	{
//		_day = d._day;
//		_month = d._month;
//		_year = d._year;
//	}
//	Date& operator+(int day)
//	{
//		Date tmp(*this);
//		tmp._day = _day + day;
//		while (tmp._day > getday(tmp._year, tmp._month))
//		{
//			tmp._day -= getday(tmp._year, tmp._month);
//			tmp._month++;
//			if (tmp._month == 13)
//			{
//				tmp._year++;
//				tmp._month = 1;
//			}
//		}
//		return tmp;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2005, 6, 13);
//	Date d2(d1);
//	Date d3(d1);
//	d3 = d1;
//	d3.print();
//	d2.print();
//	d1.print();
//	d1= Date(1996, 7, 98);
//	int ret = d1 - d2;
//	cout << ret;
//}
class A
{
public:
	A(int a = 0)
	{
		_a1 = a;
	}
	A(const A& aa)
	{
		_a1 = aa._a1;
	}
	A(int a1, int a2)
	{

	}
private:
	int _a1;
	int _a2;
};
class Stack
{
public:
	void push(const A& aa)
	{

	}
private:
	A _aa[10];
	int _top;
};
int main()
{
	A aa1(1);
}