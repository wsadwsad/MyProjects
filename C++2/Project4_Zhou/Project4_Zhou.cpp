/* Programmer:Jie Zhou
 * Project Number: 4
 * Project Description: Link List
 * Course: Data Structures - COSC2436
 * Date:October 13.2014
 */

#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
using namespace std;
#include "List.h"  
 
// PROTOTYPES:
void printMenu( );
// Postcondition: A menu of choices has been printed.
 
 
int main( )
{
    List test;     // A List to perform tests on
	List asgTest;	
    char choice;   // Command entered by the user
    
    cout << "I have initialized an empty list of integers." << endl;
 
    do
    {
        printMenu( );
        cout << "Enter choice: ";
        cin >> choice; 
        choice = toupper(choice);
        const int leng = 10;
        char item1[leng],
        	 item2[leng],
        	 item3[leng];
        int index = 0;
		   
        
        switch (choice)
        {
            case 'A': // add code prompt to the user for 3 strings and append them to list
            		  cout << "Input item 1: ";
            		  cin.ignore();
            		  cin.getline(item1, leng);
            		  test.insert(item1, test.getSize());
            		  
					  cout << "Input item 2: ";
            		  cin.getline(item2, leng);
            		  test.insert(item2, test.getSize());
            		  
					  cout << "Input item 3: ";
            		  cin.getline(item3, leng);
            		  test.insert(item3, test.getSize());
            		  
            		  test.display(cout);
                      break;
			
			case 'S': // add code to print the result of getSize()
					  cout << "The size of the list is :" << test.getSize() << endl;
                      break;
            
			case 'C': // add code to test the copy constructor, display the results            		  
            		  cout << "Testing the copy constructor.\n";            		  
            		  (List(test)).display(cout);
                      break;
            
			case 'O': // add code to test the assignment operator, display the results
            		  cout << "The origin list is: \n";
            		  test.display(cout);
            		  
            		  asgTest = test;
            		  cout << "The copy list is: \n";
            		  asgTest.display(cout);
                      break;
            
			case 'E': // add code to print the result of empty( )
            		  cout << "Check the list is empty?" << endl;
            		  if(test.empty())
            		  {
            		  	cout <<"The list is empty.";
            		  }
            		  else
            		  {
            		  	cout <<"No, the list is:\n";
            		  	test.display(cout);
            		  }
                      break;
            
			case 'P': // add code to print the list
            		  cout << "The list is :\n";
					  test.display(cout);
                      break;
            
			case 'I': // add code to input an item and position, and insert item into the list
            		  cout << "Input item : ";
            		  cin.ignore();
            		  cin.getline(item1, leng);
            		  cout << "(Starting with 0 for the first position)\nInput the position for item: ";
            		  cin >> index;
					  test.insert(item1, index);
            		  
            		  test.display(cout);
                      break;
            
			case 'F': // add code to input an item, and print the position where it was found in the list
            		  cout << "Input item : ";
            		  cin.ignore();
            		  cin.getline(item1, leng);
            		  cout << "(Starting with 0 for the first position)\nThe position for item is: " << test.find(item1);
            		  cout <<"\n";
                      break;
            
			case 'R': // add code to input a position, and erase the item at that position
            		  cout << "Input a position(starting with 0 for the first position): ";
            		  cin >> index;
            		  test.erase(index);
            		  test.display(cout);
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
    cout << " A   Append 3 strings to list" << endl;
    cout << " S   Display the size of list" << endl;
    cout << " C   Print the result from using the copy constructor" << endl;
    cout << " O   Print the result from using the assignment operator" << endl;
    cout << " E   Print the result from the empty( ) function" << endl;
    cout << " P   Print the entire list" << endl;
    cout << " I   Insert a new item with the insert(...) function" << endl;
    cout << " F   Find an item with the find( ) function" << endl;
    cout << " R   Remove an item with the erase( ) function" << endl;
    cout << " Q   Quit this test program" << endl;
}

