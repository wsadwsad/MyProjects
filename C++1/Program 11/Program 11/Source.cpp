#include<iostream>
#include<cctype>
using namespace std;

bool test(char[],int);

const int num = 20;
int main()
{
	char password[num];

	cout << "Set your password:\n";
	cout << "(The password is at least six characters long including at least one uppercase,\n";
	cout << "one lowercaseletter and one digit number)\n\n";
	
	bool again = true;
	do
	{

		cout << "Password: ";
		cin.getline(password, num);

		int length = strlen(password);
		
		cout << "\n\n";
		if (test(password,length)) { again = false; }
		else{ cout << "\n\nPlease enter your password again\n"; }

	} while (again);


	cout << "Your password has been set!\n\n";
	
	system ("pause");
	return 0;
}

bool test(char p[], int len)
{
	bool testup = false;
	bool testlo = false;
	bool testdi = false;
	
	if (len < 6) { cout << "The password should have at least six charactors\n"; }

	for (int a = 0; a < len; a++)
	{
		if (isupper(p[a]))
		{
			testup = true;
		}

		if (islower(p[a]))
		{
			testlo = true;
		}

		if (isdigit(p[a]))
		{
			testdi = true;
		}
	}
		
	if (testup == false) { cout << "The password should have at least one uppercase letter\n"; };
	if (testlo == false) { cout << "The password should have at least one lowercase letter\n"; };
	if (testdi == false) { cout << "The password should have at least one digit number\n"; };
	
	if (len < 6 || testup == false || testlo == false || testdi == false) { return false; }
	else{ return true; }

}