/* Programmer:Jie Zhou
 * Project Number: 6
 * Project Description: binary search tree
 * Course: Data Structures - COSC2436
 * Date:November 11.2014
 */

#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
using namespace std;
#include "BST.h"  
 
// PROTOTYPES:
void printMenu( );
// Postcondition: A menu of choices has been printed.
 
 
int main( )
{
    BST<int> intBST;	// A BST to perform tests on
    char choice;   		// Command entered by the user
    
    cout << "I have initialized an empty BST of int." << endl;
 
    do
    {
        printMenu( );
        cout << "Enter choice: ";
        cin >> choice; 
        choice = toupper(choice);
        int n = 0;
        
        switch (choice)
        {
            case 'A': // add code to prompt the user for a number n
					  // and insert n random numbers 0-999 into the tree
					  cout << "How many numbers want to be inserted: ";
					  cin >> n;
					  for(int i = 0; i < n; i++)
					  {
					  	intBST.insert(rand() % (999 + 1));
					  }
					  cout << n << " number(s) have been inserted.\n";
                      break;
			case 'H': // add code to print the resuly of height()
					  cout << "The height is: " << intBST.getheight() << endl;
					  cout << "\n";
                      break;
            case 'L': // add code to print the result of leafCount()
            		  cout << "The number of leaves is: " << intBST.getleafcount() << endl;
            		  cout << "\n";
                      break;
            case 'G': // add code to print the result of graph()
            		  intBST.graph(cout);
            		  cout << "\n";
                      break;
            case 'E': // add code to print the result of empty( )
            		  cout << "The tree" << (intBST.empty() ? " is" : " is not") << " empty." << endl;
              		  cout << "\n";
                      break;
            case 'P': // add code to print the result of inorder(), height() and leafCount() with labels
            		  cout << "Display tree by inorder form:" << endl;
            		  intBST.inorder(cout);
            		  cout << endl;
            		  cout << "The height is: " << intBST.getheight() << endl;
            		  cout << "The number of leaves is: " << intBST.getleafcount() << endl;
            		  cout << "\n";
                      break;
            case 'I': // add code to insert a user given item into the tree using insert()
            		  cout << "Input a number: ";
            		  cin >> n;
            		  intBST.insert(n);
                      break;
            case 'S': // add code to search for a user given item in the tree using search() and print result
            		  cout << "Input a number: ";
            		  cin >> n;
            		  cout << "Item " << n << (intBST.search(n) ? " is" : " is not") << " in the tree." << endl;            		  
            		  cout << "\n";
                      break;
            case 'R': // add code to remove a user given item in the tree using remove()
            		  cout << "Input a number: ";
            		  cin >> n;
            		  intBST.remove(n);
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
    cout << " A   Add n random numbers to the tree" << endl;
    cout << " H   Print the height of the tree" << endl;
    cout << " L   Print the leaf count of the tree" << endl;
    cout << " G   Print a graph of the tree using graph()" << endl;
    cout << " E   Print the result from the empty( ) function" << endl;
    cout << " P   Print the entire tree, the height, and the leaf count" << endl;
    cout << " I   Insert a new item with the insert() function" << endl;
    cout << " S   Find an item with the search( ) function" << endl;
    cout << " R   Remove an item with the remove( ) function" << endl;
    cout << " Q   Quit this test program" << endl;
}
