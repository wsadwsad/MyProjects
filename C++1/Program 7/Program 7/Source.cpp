#include <iostream>
#include <iomanip>
using namespace std;

struct data
{
	int date;
	double depth;
};

void sortdata(data[], int);
void showdata(data[], int);

int main()
{
	const int num = 7;
	int index;
	data days[num];
	char month[12];
	int startday;
	int endday;
	int a = 0;

	cout << "Which month: ";
	cin.getline(month,12);

	cout << "The starting day: ";
	cin >> startday;
	
	cout << "The ending day: ";
	cin >> endday;

	if (endday - startday != 6)
	{
		cout << "Invail dates, please enter again\n";

		cout << "The starting day: ";
		cin >> startday;

		cout << "The ending day: ";
		cin >> endday;
	};

	for (index = startday; index <= endday; index++)
	{
		days[a].date = index;
		a++;
	};

	for (index = 0; index < num; index++)
	{
		cout << "The base snow depth of " << days[index].date << " : ";
		cin >> days[index].depth;
	};

	sortdata(days, num);

	cout << "   Snow Report " << month << " " << startday << "-" << endday << endl;
	showdata(days, num);

	system("pause");
	return 0;
}

void sortdata(data days[], int num)
{
	data temp;
	bool swap;

	do
	{
		swap = false;
		for (int count = 0; count < (num - 1); count++)
		{
			if (days[count].depth > days[count + 1].depth)
			{
				temp = days[count];
				days[count] = days[count + 1];
				days[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

void showdata(data days[], int num)
{
	cout << setw(10) << "Date" << setw(6) << "Base"<<endl;
	cout << fixed << showpoint << setprecision(1);

	for (int index = 0; index < num; index++)
	{
		cout << setw(9) << days[index].date << setw(7) << days[index].depth << endl;
	};
}
