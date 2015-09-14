#include <iostream>
#include <iomanip>
#include "DivSales.h"
using namespace std;

double DivSales::totalsale = 0;

int main()
{
	const int numdiv = 6;
	DivSales division[numdiv];
	for (int c = 1; c <= numdiv; c++)
	{
		double s;
		cout << "Please enter four quarters of sales for Division " << c << "\n";
		for (int d = 0; d < 4; d++)
		{
			cout << "Sale " << (d+1) << " : ";
			cin >> s;
			if (s < 0)
			{
				cout << "Invalid Input!";
				system ("pause");
				return 0;
			}
			division[c].holddata(s,d);
			division[c].addqsale(s);
			division[c].addtotal(s);
		}
	};

	cout << "\n\n";
	cout << setprecision(2);
	cout << showpoint << fixed;
	cout << "There are the sales you entered:\n\n";
	for (int c = 1; c <= numdiv; c++)
	{
		cout << "Division " << c << "\n";
		for (int d = 0; d < 4; d++)
		{
			cout << "Sale " << (d + 1) << " : " << division[c].getvalue(d) << "   ";
		}
		cout << "\n\n";
	}
	
	cout << "The total sale for this year is : " << division[0].gettotal()<<"\n\n";

	system ("pause");
	return 0;

}