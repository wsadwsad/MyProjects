#include <iostream>
#include <iomanip>
using namespace std;

struct Monthly
{
	double housing,
		   uti,
		   household,
		   transp,
		   food,
		   medical,
		   insu,
		   ent,
		   clo,
		   mis;
}Budget = {500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00, 50.00 };

Monthly getdata(Monthly Spend)
{
	
	cout << "Enter your spending \n";
	cout << "Housing: ";
	cin >> Spend.housing;
	cout << "Utilities: ";
	cin >> Spend.uti;
	cout << "Household Expenses: ";
	cin >> Spend.household;
	cout << "Transportation: ";
	cin >> Spend.transp;
	cout << "Food: ";
	cin >> Spend.food;
	cout << "Medical: ";
	cin >> Spend.medical;
	cout << "Insurance: ";
	cin >> Spend.insu;
	cout << "Entertainment: ";
	cin >> Spend.ent;
	cout << "Clothing: ";
	cin >> Spend.clo;
	cout << "Miscellaneous: ";
	cin >> Spend.mis;
	
	return Spend;
};

void compare(int num1, int num2)
{
	if (num1 >= num2)
		cout << "Your spending is equal or less than budget" << endl;
	else
		cout << "Your spending is greater than budget" << endl;

};

void showresult(Monthly Budget, Monthly data)
{
	int total1 = 0,
		total2 = 0;
	
	cout << "\n";
	cout << "\n";
	cout << "Those are your Budget and spending in this month:\n";
	cout << "\n";
	cout << "Category            Budget  Spending" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "Housing:            " << Budget.housing << "     " << data.housing << "   "; compare(Budget.housing, data.housing);
	cout << "Utilities:          " << Budget.uti << "     " << data.uti << "   "; compare(Budget.uti, data.uti);
	cout << "Household Expenses: " << Budget.household << "      " << data.household << "   "; compare(Budget.household, data.household);
	cout << "Transportation:     " << Budget.transp << "      " << data.transp << "   "; compare(Budget.transp, data.transp);
	cout << "Food:               " << Budget.food << "     " << data.food << "   "; compare(Budget.food, data.food);
	cout << "Medical:            " << Budget.medical << "      " << data.medical << "   "; compare(Budget.medical, data.medical);
	cout << "Insurance:          " << Budget.insu << "     " << data.insu << "   "; compare(Budget.insu, data.insu);
	cout << "Entertainment:      " << Budget.ent << "     " << data.ent << "   "; compare(Budget.ent, data.ent);
	cout << "Clothing:           " << Budget.clo << "      " << data.clo << "   "; compare(Budget.clo, data.clo);
	cout << "Miscellaneous:      " << Budget.mis << "      " << data.mis << "   "; compare(Budget.mis, data.mis);
	
	total1 = Budget.housing + Budget.uti + Budget.household + Budget.transp + Budget.food + Budget.medical + Budget.insu + Budget.ent + Budget.clo + Budget.mis;
	total2 = data.housing + data.uti + data.household + data.transp + data.food + data.medical + data.insu + data.ent + data.clo + data.mis;
	
	cout << "\n";
	cout << "Total of the month: " << total1 << "    " << total2 << "   "; compare(total1, total2);
	cout << "\n";

};



int main()
{
	Monthly data;
	Monthly Spend = {};

	data = getdata(Spend);
	showresult(Budget, data);
	system("pause");

	return 0;
}