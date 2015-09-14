#include <iostream>
using namespace std;

void Compute(int Num_order, int Num_stock, int charge)
{
	int backorder;
	
	if (charge <10)
	{
		charge = 10;
	};

	if (Num_order > Num_stock)
	{
		backorder = Num_order - Num_stock;
		cout << "The number of ordered spools ready to ship from current stock:" << "    $" << Num_stock << "\n";
		cout << "THe number of ordered spools on backorder:" << "                        $" << backorder << "\n";
		cout << "Total selling price of the portion ready to ship :" << "                $" << Num_stock * 100 << "\n";
		cout << "Total shipping and handling charges on the portion ready to ship: $" << charge << "\n";
		cout << "Total of the order ready to ship:" << "                                 $" << Num_stock * 100 + charge << "\n";
	}

	else
	{
		cout << "The number of ordered spools ready to ship from current stock:" << "    $" << Num_order << "\n";
		cout << "Total selling price of the portion ready to ship :" << "                $" << Num_order * 100 << "\n";
		cout << "Total shipping and handling charges on the portion ready to ship: $" << 10 + charge << "\n";
		cout << "Total of the order ready to ship:" << "                                 $" << Num_order * 100 + charge << "\n";
	}
}

int main()
{
	int Num_order,
		Num_stock,
		charge;

	cout << "The number of spools ordered: ";
	cin >> Num_order;
	if (Num_order < 0)
	{
		cout << "Invail Input, please enter again\n";
		cout << "The number of spools ordered: ";
		cin >> Num_order;
	};

	cout << "The number of spools in stock: ";
	cin >> Num_stock;
	cout << "Any special shipping and handling charges (above the regular $10 rate):";
	cin >> charge;
	cout << "\n" << "\n";

	Compute (Num_order, Num_stock, charge);
	cout << "\n" << "\n";

	system("pause");
	return 0;
}

