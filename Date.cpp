#include "Date.h"
#include <iostream>
using namespace std;

int monthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int leapMonthDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };

Date::Date(int year, int month, int day){
	_year = year;
	_month = month;
	_day = day;
}

Date::Date(const Date& d) {
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date::~Date() {}

int Date::isLeapYear(int year) //判断是否闰年
{
	if ((0 == year % 4 && 0 != year % 100) || 0 == year % 400)
	{
		//cout << year << "  leap" << endl;
		return 1;
	}
		//cout << year << "  not leap" << endl;
	return 0;
}

int Date::GetDayByYearAndMonth(int year, int month, int day) //计算当前月份所在天数
{
	int sum = 0;

	for (int i = 1; i < month; i++) {
		if (isLeapYear(year))
			sum += leapMonthDays[i - 1];
		else
			sum += monthDays[i - 1];
	}

	sum += day;
	cout << "GetDayByYearAndMonth:" << sum << endl;

	return sum;
}

Date& Date::operator=(const Date& d) {
	this->_year = d._year;
	this->_month = d._month;
	this->_day = d._day;
	return *this;
}

Date Date::operator+(int days) //计算当前日期day天之后日期
{
	int d[12];
	memcpy(d, monthDays, sizeof(monthDays));
	d[1] = 28 + isLeapYear(_year);
	_day += days;
	while (_day > d[_month - 1])
	{
		_day -= d[_month - 1];
		_month++;
		if (_month > 12)
		{
			_month = 1;
			_year++;
			d[1] = 28 + isLeapYear(_year);
		}
	}
	return *this;
}
Date Date::operator-(int days) //计算当前日期day天之前日期
{
	int d[12];
	memcpy(d, monthDays, sizeof(monthDays));
	d[1] = 28 + isLeapYear(_year);
	while (days >= 1)
	{
		_day--;
		if (_day == 0)
		{
			if (_month == 1)
			{
				_month = 13;
				_year--;
				d[1] = 28 + isLeapYear(_year);
			}
			_day = d[_month - 2];
			_month--;
		}
		days--;
	}
	return *this;
}
int Date::operator-(Date& d) //两个日期x相差的天数
{
	unsigned int days = 0;
	cout << this->_year << "/" << this->_month << "/" << this->_day << endl;
	cout << d._year << "/" << d._month << "/" << d._day << endl;

	if(this->_year == d._year)
		days += GetDayByYearAndMonth(this->_year, this->_month, this->_day) - GetDayByYearAndMonth(d._year, d._month, d._day);
	else if (this->_year - d._year > 1)
	{
		for (int i = this->_year; i > d._year + 1; i--)
		{
			if (isLeapYear(i - 1))
				days += 366;
			else
				days += 365;
		}
		days += GetDayByYearAndMonth(this->_year, this->_month, this->_day) + 365 + isLeapYear(d._year) - GetDayByYearAndMonth(d._year, d._month, d._day);
	}
	else if (this->_year - d._year == 1) {
		days += GetDayByYearAndMonth(this->_year, this->_month, this->_day) + 365 + isLeapYear(d._year) - GetDayByYearAndMonth(d._year, d._month, d._day);
	}
	return days;
}
