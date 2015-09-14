/* Programmer:Jie Zhou
 * Project Number: 5
 * Project Description: Evaluating postfix expressions
 * Course: Data Structures - COSC2436
 * Date:October 22.2014
 */

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

#include "LStack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int getvalue(char token);

int main(int argc, char** argv) {
	
	string exp;
	char token;
	Stack opstack;
	char again;
		
	do
	{
		
		cout << "Enter postfix expression:\n";
		getline(cin, exp);
		
		if (exp.length() == 0)
		{
			cout << "Nothing input!" << endl;
			again = 'N';
		}
		
		else
		{
			
			for (int i = 0; i < exp.length(); i++)
			{
				token = exp[i];
				
				if (isdigit(token))
				{
					opstack.push(getvalue(token));				
				}
				
				else if (token == '+')
				{
					int a = 0;
					int b = 0;
					if (opstack.empty())
					{
						cerr << "*** No number could be processed,"
								"program terminate ***";
						exit(1);
					}
					else
					{
						a = opstack.top();
						opstack.pop();
					}
					
					if (opstack.empty())
					{
						cerr << "*** No number could be processed, "
								"program terminate ***";
						exit(1);
					}
					else
					{
						b = opstack.top();
						opstack.pop();
					}
					opstack.push(a + b);
				}
				
				else if (token == '-')
				{
					int a = 0;
					int b = 0;
					if (opstack.empty())
					{
						cerr << "*** No number could be processed,"
								"program terminate ***";
						exit(1);
					}
					else
					{
						a = opstack.top();
						opstack.pop();
					}
					
					if (opstack.empty())
					{
						cerr << "*** No number could be processed, "
								"program terminate ***";
						exit(1);
					}
					else
					{
						b = opstack.top();
						opstack.pop();
					}
					opstack.push(b - a);
				}
				
				else if (token == '*')
				{
					int a = 0;
					int b = 0;
					if (opstack.empty())
					{
						cerr << "*** No number could be processed,"
								"program terminate ***";
						exit(1);
					}
					else
					{
						a = opstack.top();
						opstack.pop();
					}
					
					if (opstack.empty())
					{
						cerr << "*** No number could be processed, "
								"program terminate ***";
						exit(1);
					}
					else
					{
						b = opstack.top();
						opstack.pop();
					}
					opstack.push(a * b);
				}
				
				else if (token == '/')
				{
					int a = 0;
					int b = 0;
					if (opstack.empty())
					{
						cerr << "*** No number could be processed,"
								"program terminate ***";
						exit(1);
					}
					else
					{
						a = opstack.top();
						opstack.pop();
					}
					
					if (opstack.empty())
					{
						cerr << "*** No number could be processed, "
								"program terminate ***";
						exit(1);
					}
					else
					{
						b = opstack.top();
						opstack.pop();
					}
					opstack.push(b / a);
				}
				
				else
				{
					continue;
				}
			}
			
			if (opstack.empty())
			{
				cerr << "*** No number could be processed, "
						"program terminate ***";
				exit(1);
			}
			
			else
			{
				int a = 0;
				a = opstack.top();
				opstack.pop();
				if (!opstack.empty())
				{
					cerr << "*** More than one value in the stack, "
							"program terminate ***";
					exit(1);
				}
				else
				{
					cout << "The value of the expression is " << a <<endl;
				}
			}
		}
		
		char answer;
		cout << "More expressions (Y or N)? ";
		cin >> answer;
		
		if (toupper(answer) == 'N')
		{
			again = 'N';			
		}
		else
		{
			cin.ignore();
		}
		
	}while(again != 'N');
	
	return 0;
}

int getvalue(char token)
{
	return (token - 48);
}
