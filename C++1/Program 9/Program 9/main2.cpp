#include "dayofyear.h"

#include<iostream>
#include<string>
using namespace std;

int main2()
{
	bool again = false;

	DayOfYear date("January",1);
	string a;
	int b;

	do
	{
		cout << "Enter the month and date seperate by space: ";
		cin >> a >> b;
		DayOfYear date(a, b);
		

		
		date.print();

		string a = "n";
		cout << "Again(y/n): ";
		cin >> a;
		cout << "\n\n";
		if (a == "y")
		{
			again = true;
		}
		else
		{
			break;
		}
	} while (again);

	system("pause");
	return 0;
}