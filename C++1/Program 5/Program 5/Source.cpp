#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	const int types = 5;
	string name[types] = { "Mild", "Medium", "Sweet", "Hot", "Zesty" };
	int sales[types];
	int chip = 0,
		total = 0,
		highest = 0;

	string highest_name,
		lowest_name;

	cout << "Please enter each salsa`s sale: \n\n";


	
	for (int chip = 0; chip < types; chip++)
	{
		cout << name[chip] << " :";
		cin >> sales[chip];
		while (sales[chip] < 0)
		{
			cout << "Invalid number! please enter again\n";
			cout << name[chip] << " :";
			cin >> sales[chip];
		}
		total += sales[chip];

		if (sales[chip]>highest)
		{
			highest = sales[chip];
			highest_name = name[chip];
		}
	}
	

	int lowest = sales[0];
	for (int a = 1; a < types; a++)
	{
		if (sales[a] < lowest)
			lowest = sales[a];
			lowest_name = name[a];

	}

	cout << "The Statistcs of Sales for last month:\n\n";
	for (int b = 0; b < types; b++)
	{
		cout << setw(6) << name[b] << " :  " << sales[b] << endl;
	}
	cout << "The total sales: " << total << endl;
	cout << "The highest sale: " << highest_name << endl;
	cout << "The lowest sale:  " << lowest_name << endl;
	
	system("pause");
	return 0;

}