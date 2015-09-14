#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int sale1,
		sale2,
		sale3;

	cout << "Enter today`s sales for store 1: ";
	cin  >> sale1;
	cout << "Enter today`s sales for store 2: ";
	cin  >> sale2;
	cout << "Enter today`s sales for store 3: ";
	cin  >> sale3;

	cout << "\n";
	cout << "    " << "DAILY SALES\n";
	cout << "  " << "(each * = $100)\n";

	cout << "Store 1: ";
	for (int x = 0; x < (sale1 / 100); x++)
	{
		cout << '*';
	}
	cout << "\n";

	cout << "Store 2: ";
	for (int x = 0; x < (sale2 / 100); x++)
	{
		cout << '*';
	}
	cout << "\n";

	cout << "Store 3: ";
	for (int x = 0; x < (sale3 / 100); x++)
	{
		cout << '*';
	}

	cout << "\n";
	system("pause");
	return 0;
}