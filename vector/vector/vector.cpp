#include<iostream>
#include<vector>
using namespace std;
#include"vector.h"
void test_vector1()
{
	vector<int>s1;
	vector<int>s2(3, 6);
	vector<int>s3(s2);
	vector<int>s4(++s3.begin(), s3.end());
	for (size_t i = 0; i < s4.size(); i++)
	{
		cout << s4[i] << " ";
	}
	vector<int>::iterator it = s3.begin();
	while (it != s3.end())
	{
		cout << *it << " " << endl;
		it++;
	}
	cout << endl;
	for (auto e : s3)
	{
		cout << e << " ";
	}
	cout << endl;
}
void TestVectorExpand()
{
	size_t sz;
	vector<int> v;
	v.reserve(90);
	sz = v.capacity();
	cout << "capacity changed:" << sz << endl;
	cout << "capacity grow" << endl
		;
	for (int i = 0; i < 100; i++)
	{
		v.push_back(1);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity grow:" << sz << endl;
		}
	}
}
void test_vector()
{
	vector<int> v(10, 1);
	v.reserve(20);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.reserve(15);
	cout << v.size() << endl;
	cout << v.capacity() << endl; 
	v.reserve(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}
void test_string()
{
	vector<int> v(10, 1);
	v.reserve(20);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.reserve(15);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.reserve(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}
void _test_vector1()
{
	bit::vector<int>t;
	t.push_back(1);
	t.push_back(1);
	t.push_back(1);
	t.push_back(1);
	t.push_back(1);
	print_vector( t);
}
void _test_vector2()
{
	bit::vector<double>t;
	t.push_back(1.1);
	t.push_back(1.2);
	t.push_back(1.3);
	t.push_back(1.4);
	t.push_back(1.5);
	double x;
	cin >> x;
	auto p = find(t.begin(), t.end(), x);
	if (p != t.end())
	{
		p = t.insert(p, 40);
		(*p) *= 10;
	}
	print_vector(t);
	//print_vector(t);
	//cout << endl;
	//t.insert(t.begin()+2, 2.9);
	////t.pop_back();
	//cout << t[1] << endl;
	//cout << t.size()<<endl;
	//cout << t.capacity()<<endl;
	////cout << !t.empty() << endl;
	//print_vector(t);
}
void test_vector3()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	auto it = v.begin();
	while (it!=v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
			it++;
	}
	print_container(v);
}
void test_vector4()
{
	/*int i = int();
	int j = int(1);
	int k(2);
	cout << i << j << k;*/
	vector<int>v;
	v.reserve(20);
	v.resize(15,3);
	/*cout << v.size() << v.capacity();*/
	v.resize(10, 2);
	v.resize(25, 2);
}
void test_vector5()
{
	bit::vector<int>v1;
	v1.push_back(12);
	v1.push_back(12);
	v1.push_back(12);
	v1.push_back(12);
	bit::vector<int>v2(v1);
	print_vector(v2);
	print_container(v2);
	bit::vector<int>v3 = v1;
	v3.push_back(20);
	print_vector(v3);
}
void test_vector6()
{
	//vector<int>v1;
	//v1.push_back(20);
	//v1.push_back(80);
	//v1.push_back(60);
	//v1.push_back(50);
	//v1.push_back(40);
	//v1.push_back(30);
	////vector<int>v2(++v1.begin(), v1.begin() + 3);//后面的是不会被初始化进去的,即左闭右开[ , )
	////print_container(v2);
	//list<int>l1;
	//l1.push_back(10.5);
	//l1.push_back(20.6);
	//l1.push_back(30);
	//vector<double>v2(l1.begin(), l1.end());
	//print_container(l1);
	//cout << endl;
	//print_container(v2);
	/*vector<string>v1(5,"11111111");
	print_container(v1);
	vector<int>v2(10);*/
	vector<int>v6(10u, 1);
	print_container(v6);
	vector<int>v7(10, 1);

}
void test_vector7()
{
	vector<string> v;
	v.push_back("11111111111111111111");
	v.push_back("11111111111111111111");
	v.push_back("11111111111111111111");
	v.push_back("11111111111111111111");
	print_container(v);
	v.push_back("11111111111111111111");
	print_container(v);
}
int main()
{
	//test_vector1();
	//TestVectorExpand();
	//test_vector();
	//test_vector3();
	//test_vector4();
	//test_vector5();
	//test_vector6();
	test_vector7();
}