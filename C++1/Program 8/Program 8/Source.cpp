#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main()
{
	int day;
	int m;
	int year;
	const int num = 12;
	string months[num] = { "January", "February", "March", "April",
		"May", "June", "July", "August", "September",
		"October", "November", "December" };
	int days[num] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	bool again = false;

	do
	{
		cout << "Please enter two integers for the month and year\n";
		cout << "(Seperate two integers by space, enter 0 for both month and year to end program)\n";
		cout << "Month(1-12) and Year: ";
		cin >> m >> year ;
		
		cout << "\n";

		if ((m != 0) && (year != 0))
		{
			if (m == 2)
			{
				if ((year % 100 != 0) && (year % 4 == 0) || (year % 400 == 0))
				{
					day = 29;
				}
			
				else
				{
					day = days[m - 1];
				}
			}
			else
			{
				day = days[m - 1];
			}
			cout << "The month of " << months[m - 1] << " in " << year << " has " << day << " days.\n\n\n";

			again = true;
		}
		else
			break;
	} while (again);

	system("pause");
	return 0;
}