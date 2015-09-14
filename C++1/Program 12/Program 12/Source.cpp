#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

const int des_size = 30, date_size = 20;

void addrecord();
void displayrecord();

struct inventory
{
	char des[des_size];
	int qatt;
	double wholecost;
	double retailcost;
	char date[date_size];
};


int main()
{
	int choice;

	do
	{

		cout << "1. Add new records.\n";
		cout << "2. Display and change any record.\n";
		cout << "3. Close.\n\n";
		cout << "Please choose: ";
		cin >> choice;

		switch (choice)
		{case 1:
			addrecord();
			break;
		case 2:
			displayrecord();
			break;

		default: cout << "Invalid Choice" << endl;
		}
	} while (choice != 3);
		
	system("pause");
	return 0;
	
}


void addrecord( )
{
	inventory item;
	string a;

	fstream inv("inventory.dat", ios::out | ios::binary);

	if (!inv)
	{
		cout << "Error opening file!";
	};

	do
	{
		cout << "Enter the following information about a item:\n";
		cout << "Description: ";
		cin.ignore();
		cin.getline(item.des, des_size);
		cout << "Quantity on hand: ";
		cin >> item.qatt;
		if (item.qatt < 0)
		{
			cout << "Invalid enter, please enter again\n";
			cout << "Quantity on hand: ";
			cin >> item.qatt;
		}
		cout << "Wholesale cost: ";
		cin >> item.wholecost;
		if (item.wholecost < 0)
		{
			cout << "Invalid enter, please enter again\n";
			cout << "Wholesale cost: ";
			cin >> item.wholecost;
		}
		cout << "Retail cost: ";
		cin >> item.retailcost;
		if (item.retailcost < 0)
		{
			cout << "Invalid enter, please enter again\n";
			cout << "Retail cost: ";
			cin >> item.retailcost;
		}
		cout << "Date added to inventory(MMDD, exp:0101): ";
		cin.ignore();
		cin.getline(item.date, date_size);
		inv.write(reinterpret_cast<char *>(&item), sizeof(item));
		

		cout << "\n\n";
		cout << "Do you want to enter another record? (y/n)";
		cin >> a;
	} while (a == "y" || a == "Y");
	inv.close();
}

void displayrecord()
{
	inventory item;
	int number = 0;
	int answer1, answer2;

	fstream inv("inventory.dat", ios::in | ios::out | ios::binary);
	if (!inv)
	{
		cout << "Error opening file!";
	};

	cout << "Here are the menu of all item int he inventory: \n";
	inv.read(reinterpret_cast<char *>(&item), sizeof(item));
	while (!inv.eof())
	{
		cout << "Item "<<(number +1)<<": ";
		cout << item.des << endl;
		number++;
		inv.read(reinterpret_cast<char *>(&item), sizeof(item));
	}
	cout << "\n\n";
	cout << "Please choose a item number: ";
	cin >> answer1;

	inv.seekg((answer1 - 1)*sizeof(item), ios::beg);
	inv.read(reinterpret_cast<char *>(&item), sizeof(item));

	cout << "Description: ";
	cout << item.des << endl;
	cout << "Quantity on hand: ";
	cout << item.qatt << endl;
	cout << "Wholesale cost: ";
	cout << item.wholecost << endl;
	cout << "Retail cost: ";
	cout << item.retailcost << endl;
	cout << "Date added to inventory: ";
	cout << item.date << endl;

	cout << "\n\n";
	cout << "1. Change data\n";
	cout << "2. Return to main menu\n";
	cout << "Please choose: ";
	cin >> answer2;

	switch (answer2)
	{case 1:
		cout << "Enter the new data:\n";
		cout << "Description: ";
		cin.ignore();
		cin.getline(item.des, des_size);
		cout << "Quantity on hand: ";
		cin >> item.qatt;
		if (item.qatt < 0)
		{
			cout << "Invalid enter, please enter again\n";
			cout << "Quantity on hand: ";
			cin >> item.qatt;
		}
		cout << "Wholesale cost: ";
		cin >> item.wholecost;
		if (item.wholecost < 0)
		{
			cout << "Invalid enter, please enter again\n";
			cout << "Wholesale cost: ";
			cin >> item.wholecost;
		}
		cout << "Retail cost: ";
		cin >> item.retailcost;
		if (item.retailcost < 0)
		{
			cout << "Invalid enter, please enter again\n";
			cout << "Retail cost: ";
			cin >> item.retailcost;
		}
		cout << "Date added to inventory(MMDD, exp:0101): ";
		cin.ignore();
		cin.getline(item.date, date_size);
		inv.seekp((answer1 - 1)*sizeof(item), ios::beg);
		inv.write(reinterpret_cast<char *>(&item), sizeof(item));
		inv.close();
		break;
	case 2:
		inv.close();
		break;
	default:
		inv.close();
		break;
		cout << "Invalid Choice" << endl;
	}

}


