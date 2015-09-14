// Programmer: Jie Zhou
// Project Number: 1
// Project Desc: Binary Representation of Data
// Course: Data Structures
// Date: Sep. 02, 2014
 
#include <iostream>
#include <bitset>
using namespace std;
 
#include "PrintFunctions.cpp"
char printChar ();
int printShort ();
float printFloat ();
 
int main()
{
     
    int choice;
     
    do
    {
        cout<< "\nMenu: \n";
        cout<< " 1 - Print the binary representation of a character.\n";
        cout<< " 2 - Print the binary representation of a short integer.\n";
        cout<< " 3 - Print the binary representation of a float.\n";
        cout<< " 4 - Exit program. \n\n";
       	cout << "Enter your choice : ";
       	cin>>choice;

    if (choice >=1 && choice <=4)
    {
             switch(choice)
             {
			 case 1: 
			 printChar();
             break;
 
    		 case 2:
             printShort ();
             break;

    		 case 3:
             printFloat ();    
             break;

    		 case 4:
        	 break;
    		}	
    }
     
    else if (choice != 4)
    {
        cout << "Invalid choice, please chose again.\n"; 
    }
         
   } while (choice != 4); 
    return 0;
}
