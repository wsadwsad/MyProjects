/* Programmer:Jie Zhou
 * Project Number: 3
 * Project Description: Lists
 * Course: Data Structures - COSC2436
 * Date:October 1.2014
 */

#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
using namespace std;
#include "DList.h"  
 
// PROTOTYPES:
void printMenu( );
// Postcondition: A menu of choices has been printed.
 
int getNumber( );
char getUserCommand( );
// Postcondition: The user has been prompted to enter an integer number. The
// number has been read, echoed to the screen, and returned by the function.
 
 
int main( )
{
    List test;     // A List to perform tests on
    List copytest;
    int numb;
    char choice;   // Command entered by the user
    
	cout << "I have initialized an empty list of integers." << endl;
 
    do
    {
        printMenu( );
        cout << "Enter choice: ";
        cin >> choice; 
        choice = toupper(choice);
        
        switch (choice)
        {
            case 'A': // add code to add n integers to end of list
					  numb = getNumber( );
					  for (int i = 0; i < numb; i++)
					  {
					  	test.insert(rand() % (999 + 1),test.getmysize());
  					  }
					  cout << "the list is: \n" << test << endl;
            		  cout << "\n";
                      break;
                      
            case 'C': // add code to change the capacity of the list
            		  int newC;
					  cout << "Enter a integer for new capacity: ";
            		  cin >> newC;            		             		  
					  
					  test.resize(newC);            		  
					  cout << test << endl;
            		  cout << "\n";
                      break;
                      
            case 'E': // add code to print the result of empty( )
            		  if(test.empty())
            		  {
            		  	cout << "The list is empty. \n" << test << endl;
            		  }
            		  else
            		  {
            		  	cout << "The list is not empty. \n" << test << endl;
            		  }
            		  cout << "\n";
                      break;
                      
            case 'P': // add code to print the list
            		  copytest = test;					  
					  cout << copytest << endl;
            		  cout << "\n";
                      break;
                      
            case 'I': // add code to input an item and position, and insert item into the list
            		  int Number;
            		  int position;           		  
					  cout << "Enter a integer number to add into the list: ";
            		  cin >> Number;           		  
					  cout << "Enter a integer number for the position: ";
            		  cin >> position;           		  
					  
					  test.insert(Number, position);           		  
					  cout << test;
            		  cout << "\n";
                      break;
                      
            case 'R': // add code to input a position, and erase the item at that position
            		  int position2;
					  cout << "Enter a integer number for the position: ";
            		  cin >> position2;
            		  
					  test.erase(position2);            		  
					  cout << test;
            		  cout << "\n";
                      break;  
					     
            case 'Q': cout << "Test program ended." << endl;
                      break;
                      
            default:  cout << choice << " is invalid." << endl;
        }
    }
    while ((choice != 'Q'));
 
    return EXIT_SUCCESS;
}
 
void printMenu( )
{
    cout << endl; 
    cout << "The following choices are available: " << endl;
    cout << " A   Add a number of random integers to end of list" << endl;
    cout << " C   Change the capacity of the list using resize( )" << endl;
    cout << " E   Print the result from the empty( ) function" << endl;
    cout << " P   Print a copy of the entire list" << endl;
    cout << " I   Insert a new number with the insert(...) function" << endl;
    cout << " R   Remove a number with the erase( ) function" << endl;
    cout << " Q   Quit this test program" << endl;
}
 
char getUserCommand( )
// Library facilities used: iostream
{
    char command;
 
    cout << "Enter choice: ";
    cin >> command; // Input of characters skips blanks and newline character
 
    return command;
}
 
int getNumber( )
// Library facilities used: iostream
{
    int result;
    
    cout << "Please enter an integer number for the list: ";
    cin  >> result;
    cout << result << " has been read." << endl;
    return result;
}
