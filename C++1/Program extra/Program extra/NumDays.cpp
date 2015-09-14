#include "NumDays.h"

NumDays operator+(NumDays x, NumDays y)
{
	return NumDays(x.hour + y.hour);
}

NumDays operator-(NumDays x, NumDays y)
{
	return NumDays(x.hour - y.hour);
}

NumDays NumDays::operator++()
{
	hour++;
	return *this;
}

NumDays NumDays::operator++(int)
{
	NumDays temp = *this;
	hour++;
	return temp;
}

NumDays NumDays::operator--()
{
	hour--;
	return *this;
}

NumDays NumDays::operator--(int)
{
	NumDays temp = *this;
	hour--;
	return temp;
}