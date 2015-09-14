#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
#include <iostream>
#include <string>
using namespace std;

class DayOfYear
{
private:
	string month;
	int day;
	int n_month;
	static string monthly[];
	int x;
	int tempday;
public:
	DayOfYear(int a)
	{
		day = tempday = a;
		setday(day);
	}
	DayOfYear(string m,int d)
	{
		day = d;
		month = m;
		findmonth();
	}

	void findmonth()
	{
		for (int cont = 0; cont <12; cont++ )
		if (month == monthly[cont])
			checkday(cont, day);

	}

	void checkday(int b, int c)
	{
		if (b = 0)	  { if (c > 31 || c < 1) { x = 0; }; }
		if (b = 1)  { if (c > 28 || c < 1) { x = 0; }; }
		if (b = 2)	  { if (c > 31 || c < 1) { x = 0; }; }
		if (b = 3)	  { if (c > 30 || c < 1) { x = 0; }; }
		if (b = 4)		  { if (c > 31 || c < 1) { x = 0; }; }
		if (b = 5)	  { if (c > 30 || c < 1) { x = 0; }; }
		if (b = 6)	  { if (c > 31 || c < 1) { x = 0; }; }
		if (b = 7)	  { if (c > 31 || c < 1) { x = 0; }; }
		if (b = 8) { if (c > 30 || c < 1) { x = 0; }; }
		if (b = 9)	  { if (c > 31 || c < 1) { x = 0; }; }
		if (b = 10)  { if (c > 30 || c < 1) { x = 0; }; }
		if (b = 11)  { if (c > 31 || c < 1) { x = 0; }; }
		else x = 1;
	}

	int getx()
	{
		return x;
	}

	void setday(int a)
	{
		n_month = 0;
		if (a >= 1 && a <= 31) { this->day = a; }

		else if (a >= 32 && a <= 59) { this->day = (a - 31); n_month = 1; }

		else if (a >= 60 && a <= 90) { this->day = (a - 59); n_month = 2; }

		else if (a >= 91 && a <= 120) { this->day = (a - 90); n_month = 3; }

		else if (a >= 121 && a <= 151) { this->day = (a - 120); n_month = 4; }

		else if (a >= 152 && a <= 181) { this->day = (a - 151); n_month = 5; }

		else if (a >= 182 && a <= 212) { this->day = (a - 181); n_month = 6; }

		else if (a >= 213 && a <= 243) { this->day = (a - 212); n_month = 7; }

		else if (a >= 244 && a <= 273) { this->day = (a - 243); n_month = 8; }

		else if (a >= 274 && a <= 304) { this->day = (a - 273); n_month = 9; }

		else if (a >= 305 && a <= 334) { this->day = (a - 304); n_month = 10; }

		else if (a >= 335 && a <= 365) { this->day = (a - 334); n_month = 11; }

		else { cout << "\n" << "Wrong input, default day to 1" << "\n"; this->day = 1; }
	};

	void checkday2()
	{
		if (day = 1)
		{
			day = 366;
		}
		else if (day = 365)
		{
			day = 0;
		}
	}

	void setmonth()
	{
		month = monthly[n_month];
	}
	
	string getmonth()
	{
		return month;
	}

	int getday()
	{
		return tempday;
	}
	
	void print()
	{
		cout << "\n" << "The date is: " << getmonth() << " " << this->day << "\n";
	}

	DayOfYear operator++()
	{
		day++;
		return *this;
	}

	DayOfYear operator++(int)
	{
		DayOfYear temp = *this;
		day++;
		return temp;
	}

	DayOfYear operator--()
	{
		day--;
		return *this;
	}

	DayOfYear operator--(int)
	{
		DayOfYear temp = *this;
		day--;
		return temp;
	}
};
#endif