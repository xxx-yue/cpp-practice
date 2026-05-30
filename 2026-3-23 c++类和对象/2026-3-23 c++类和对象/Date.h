#pragma once
#include<iostream>
using namespace std;
#include <assert.h>
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);
	void print()const;
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
	int getday(int year, int month) 
	{
		static int months[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
			return 29;
		return months[month];
	}
	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator!=(const Date& d)const;
	Date& operator++();
	Date operator-(int day)const;
	Date operator+(int day)const;
	Date& operator+=(int day);
	bool CheckDate() const;
	int operator-(const Date& d) const;
	Date* operator&()
	{
		return this;
	}
private:
	int _year;
	int _month;
	int _day;
};