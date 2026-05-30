#include"Date.h"
Date::Date(int year, int month, int day)
{
	_day = day;
	_month = month;
	_year = year;
	assert(CheckDate());
}

bool Date::operator<(const Date& d) const
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month < d._month)
			return true;
		else if (_month == d._month)
		{
			if (_day < d._day)
				return true;
		}
	}
	return false;
}
bool Date::operator<=(const Date& d)const
{
	return !Date::operator>(d);
}
bool Date::operator==(const Date& d)const
{
	return _year == d._year && _month == d._month && _day == d._day;
}
bool Date::operator>(const Date& d)const
{
	return !Date::operator<(d) && !Date::operator==(d);
}
bool Date::operator>=(const Date& d)const
{
	return !Date::operator<(d);
}
bool Date::operator!=(const Date& d)const
{
	return !Date::operator==(d);
}
Date Date:: operator+(int day)const
{
	Date tmp(*this);
	if (day < 0)
	{
		day = -day;
		tmp = tmp - day;
		return tmp;
	}
	tmp._day = tmp._day + day;
	while (tmp._day > getday(tmp._year, tmp._month))
	{
		tmp._day -= getday(tmp._year, tmp._month);
		tmp._month++;
		if (tmp._month == 13)
		{
			tmp._year++;
			tmp._month = 1;
		}
	}
	return tmp;
}
Date& Date::operator+=(int day)
{
	*this = *this + day;
	return *this;
}
Date Date::operator-(int day)const
{
	Date tmp(*this);
	if (day < 0)
	{
		day = -day;
		tmp = (tmp + day);
		return tmp;
	}
	tmp._day =tmp._day - day;
	while (tmp._day <= 0)
	{
		tmp._month--;
		if (tmp._month == 0)
		{
			tmp._month = 12;
			tmp._year--;
		}
		tmp._day = tmp._day + getday(tmp._year, tmp._month);
	}
	return tmp;
}
void Date::print()const
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
} ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}
istream& operator>>(istream& in, Date& d)
{
	while (1)
	{
		cout << "请依次输入年月日" << endl;
		in >> d._year >> d._month >> d._day;
		if (!d.CheckDate())
			cout << "输入非法,请更新输入";
		else break;
	}
	return in;
}
bool Date:: CheckDate() const
{
	if(_month>12||_month<1||_day<1||_day>getday(_year,_month))
		return false;
		return true;
}
Date& Date::operator++()
{
	_day += 1;
	if (_day > getday(_year, _month))
	{
		_day -= getday(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}
int Date::operator-(const Date& d) const
{
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (d > *this)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		n++;
	}
	return n*flag;
}
