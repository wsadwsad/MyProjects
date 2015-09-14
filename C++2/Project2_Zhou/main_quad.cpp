/* Programmer:Jie Zhou
 * Project Number: 2
 * Project Description: Quadratic Expressions
 * Course: Data Structures - COSC2436
 * Date:Sep.11.2014
 */

#include <iostream>
using namespace std;

#include "Quadratic.h"

void menu();

int main()
{
	Quadratic q1;
	char choice;
	
	cout << "A quadratic called q1 has been created and initialized to a default value." << endl;
	

	do
	{
	    menu();
 
		cout << "\nEnter your choice: ";
		cin  >> choice;

		if (choice == '1')
		{
			// code to test display() function (if you had them write one)
			q1.display();
			cout << "\n";
		}

		else if (choice == '2')
		{
			// code to test get functions
			cout << " a = " << q1.getA() << endl;
			cout << " b = " << q1.getB() << endl;
			cout << " c = " << q1.getC() << endl;
			cout << "\n";
		}
		
		else if (choice == '3')
		{
			// code to test set function
			float qa, qb, qc;
			cout << "Please enter three number for a, b and c.\n";
			cout << "a, b, c = ";
			cin >> qa >> qb >>qc;
			q1.set(qa, qb, qc);
			cout << "\n";
		}

		else if (choice == '4')
		{
			// code to test evaluate function
			float X;
			cout << "Please enter a number for x." << endl;
			cout << "x = ";
			cin >> X;
			cout << "The answer is: " << q1.evaluate(X) << endl;
			cout << "\n";
		}	

		else if (choice == '5')
		{
			// code test number of roots function
			cout << "The equation: ";
			q1.display();
			cout << "has " << q1.numRoots() << " real roots." << endl;
			cout << "\n";
		}

		else if (choice == '6')
		{
			// code to test small root and large root functions
			if (q1.numRoots() == 0)
			{
				cout << "No real roof." << endl;
			}
			else
			{
				cout << "The maxroot is: " << q1.maxRoot() << endl;
				cout << "The minroot is: " << q1.minRoot() << endl;
			}
			cout << "\n";
			
		}

		else if (choice == '7')
		{
			// create a second quadratic from user inputted coefficients
			// and display the sum of q1 and the second quadratic
			float q2a, q2b, q2c;
			Quadratic q2;
			cout << "Please enter other three number for second quadratic`s coefficients." << endl;
			cout << "2nd a, b, c = ";
			cin >> q2a >>q2b >> q2c;
			q2.set(q2a, q2b, q2c);
			Quadratic sumofco = q1 + q2;
			cout << "The sum of a is: " << sumofco.getA() << endl;
			cout << "The sum of b is: " << sumofco.getB() << endl;
			cout << "The sum of c is: " << sumofco.getC() << endl;
			cout << "\n";
		}

		else if (choice == '8')
		{
		    // code to test multiplication operator
		    double R;
		    cout << "Please enter a number for r." << endl;
		    cout << "r = ";
		    cin >> R;
		    Quadratic proofco = R * q1;
		    cout << "The product of a is: " << proofco.getA() << endl;
		    cout << "the product of b is: " << proofco.getB() << endl;
		    cout << "the product of c is: " << proofco.getC() << endl;
		    cout << "\n";
		}
		
		else
			cout << "Not a valid option\n";
			
	} while (choice != '9');
	
	
	return 0;
}

void menu()
{
	cout << "Please choose one of the following:\n"
	         << "   1 - Display q1\n"
	         << "   2 - Display the coefficients of q1\n"
	         << "   3 - Modify the coefficients of q1\n"
		     << "   4 - Display the value of q1 at a given value of x\n"
	         << "   5 - Display the number of roots for q1\n"
		     << "   6 - Display the roots of q1\n"
		     << "   7 - Display the sum of q1 and a second quadratic\n"
		     << "   8 - Display the product of q1 and a given floating-point value\n"
		     << "   9 - Exit" << endl;
}

