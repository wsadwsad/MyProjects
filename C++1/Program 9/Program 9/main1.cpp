#include "dayofyear.h"

#include<iostream>
#include<string>
using namespace std;

const int num = 12;
string DayOfYear::monthly[num] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int main()
{	
	
	int nday, ndate;
	string nmonth;
	cout << "Enter a number for the day(1-365): ";
	cin >> nday;
	DayOfYear date1(nday);
	cout <<"\nEnter the month (January to December)and date(in the range of the month): ";
	cin >> nmonth >> ndate;
	DayOfYear date2(nmonth, ndate);
	cout << "\n\n";
	
	int ter = date2.getx();
	if (ter == 0)
	{
		cout << "Wrong input, the number of the day is out of the range.\n";
		
		system("pause");
		return 0;
	}

	date1.setmonth();
	cout << "Showing the result by using constructor 1:\n";
	date1.print();
	cout << "\n";
	

	DayOfYear day2(1);
	DayOfYear day3(1);
	DayOfYear temp_day(1);

	
	int tempday = date1.getday();
	

	day3 = --date1;
	if (tempday == 1)
	{
		DayOfYear day3(365);
		day3.setmonth();
		cout << "Using prefix -- to represent the previous day: ";
		day3.print();
		cout << "\n";
	}
	else
	{
		day3.setmonth();
		cout << "Using prefix -- to represent the previous day: ";
		day3.print();
		cout << "\n";
	}




	day3 = date1--;
	if (tempday == 1)
	{
		DayOfYear day2(365);
		day3.setmonth();
		cout << "Using postfix -- to represent the previous day: ";
		day3.print();
		cout << "\n";
	}
	else
	{
		day3.setmonth();
		cout << "Using postfix -- to represent the previous day: ";
		day3.print();
		cout << "\n";
	}

	temp_day = day3;
	date1 = ++temp_day;
	date1 = temp_day++;
	
	day2 = ++date1;
	if (tempday == 365)
	{
		DayOfYear day2(1);
		day2.setmonth();
		cout << "Using prefix ++ to represent the next day: ";
		day2.print();
		cout << "\n";
	}
	else
	{
		day2.setmonth();
		cout << "Using prefix ++ to represent the next day: ";
		day2.print();
		cout << "\n";
	}
	

	day2 = date1++;
	if (tempday == 365)
	{
		DayOfYear day2(1);
		day2.setmonth();
		cout << "Using postfix ++ to represent the next day: ";
		day2.print();
		cout << "\n";
	}
	else
	{
		day2.setmonth();
		cout << "Using postfix ++ to represent the next day: ";
		day2.print();
		cout << "\n";
	}




	
	cout << "Showing the result by using constructor 2:\n";
	date2.print();

	



	system ("pause");
	return 0;
}