#ifndef NUMDAYS_H
#define NUMDAYS_H
#include <iostream>
using namespace std;


class NumDays
{private:
	int hour;
	double day;
public:
	NumDays(int h)
	{
		sethour(h);
	}

	void sethour(int h)
	{
		hour = h;
	}

	void setday(double hr)
	{
		day = hr / 8;
	}

	double getday()
	{
		return day;
	}

	int gethour()
	{
		return hour;
	}

	operator double()
	{
		return hour;
	}

	friend NumDays operator+(NumDays x, NumDays y);
	friend NumDays operator-(NumDays x, NumDays y);

	NumDays operator++();
	NumDays operator++(int);

	NumDays operator--();
	NumDays operator--(int);
};
#endif