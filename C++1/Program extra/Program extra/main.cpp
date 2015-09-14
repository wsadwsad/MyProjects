#include <iostream>
#include "NumDays.h"
using namespace std;

int main()
{
	
	int h;
	double cov1, cov2;

	cout << "Enter a number for hour 1: ";
	cin >> h;
	NumDays hour1(h);
	cout << "Enter another number for hour 2: ";
	cin >> h;
	NumDays hour2(h);

	cov1 = hour1;
	cov2 = hour2;
	hour1.setday(cov1);
	hour2.setday(cov2);
	cout << "\n\n  8 working hours = 1 day.\n";
	cout << "Hour 1: " << hour1.gethour() << " hours = " << hour1.getday() << " day(s).\n";
	cout << "Hour 2: " << hour2.gethour() << " hours = " << hour2.getday() << " day(s).\n\n";

	NumDays hour3(0);
	hour3 = hour1 + hour2;
	cout << "Hour 1 + Hour 2 = " << hour3.gethour() << " hours.\n";
	hour3 = hour1 - hour2;
	cout << "Hour 1 - Hour 2 = " << hour3.gethour() << " hours.\n\n";

	NumDays newhour1(0);
	NumDays newhour2(0);
	double newcov1, newcov2;

	cout << "Using prefix ++ operator for hour 1:\n";
	for (int c = 0; c < 4; c++)
	{
		newhour1 = ++hour1;
		newcov1 = newhour1;
		newhour1.setday(newcov1);
		cout << "Newhour 1: " << newhour1.gethour() << " hours. Hour 1: " << hour1.gethour() << " hours.\n";
	}

	cout << "\nUsing postfix ++ operator for hour 2:\n";
	for (int c = 0; c < 4; c++)
	{
		newhour2 = hour2++;
		newcov2 = newhour2;
		newhour2.setday(newcov2);
		cout << "Newhour 2: " << newhour2.gethour() << " hours. Hour 2: " << hour2.gethour() << " hours.\n";
	}

	cout << "\nUsing prefix -- operator for hour 1:\n";
	for (int c = 0; c < 4; c++)
	{
		newhour1 = --hour1;
		newcov1 = newhour1;
		newhour1.setday(newcov1);
		cout << "Newhour 1: " << newhour1.gethour() << " hours. Hour 1: " << hour1.gethour() << " hours.\n";
	}

	cout << "\nUsing postfix -- operator for hour 2:\n";
	for (int c = 0; c < 4; c++)
	{
		newhour2 = hour2--;
		newcov2 = newhour2;
		newhour2.setday(newcov2);
		cout << "Newhour 2: " << newhour2.gethour() << " hours. Hour 2: " << hour2.gethour() << " hours.\n\n";
	}

	system("pause");
	return 0;
}