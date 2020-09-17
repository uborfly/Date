#pragma once
class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1);
    Date(const Date &d);
    ~Date();
    Date &operator=(const Date &d);

public:
    int isLeapYear(int year);                               //判断是否闰年
    int GetDayByYearAndMonth(int year, int month, int day); //计算当前月份所在天数
    Date operator+(int days);                               //计算当前日期day天之后日期
    Date operator-(int days);                               //计算当前日期day天之前日期
    int operator-(Date &d);                                 //两个日期x相差的天数
private:
    int _year;
    int _month;
    int _day;
};
