/* Programmer:Jie Zhou
 * Project Number: 8
 * Project Description: heap
 * Course: Data Structures - COSC2436
 * Date:December 2.2014
 */

#include <cstdlib>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void heapify(int array[], int s);
void percolatedown(int array[], int r, int s);
void displayarray(int a[], int s);
void displaytree(int a[], int s);
void displayonelevel(int a[], int numrows, int level, int beginindex, int endindex);

int main(int argc, char** argv) 
{
	int size = 0;
	int array[size];
	bool again = true;
	char choice = ' ';
	
	do
	{
		cout << "Input the number of integers in the array: ";
		cin >> size;
		for (int i = 0; i < size; i++)
		{
			array[i] = (rand() % (999 + 1));
		}
		
		displayarray(array, size);
		cout << "\n\n";
		displaytree(array,size);
		
		cout << "\n\n H - Heapify." << endl;
		cout << " S - Heapsort." << endl;
		cout << "Your choice: ";
		cin >> choice;
		choice = toupper(choice);
		if (choice == 'H')
		{
			heapify(array, size);
		}
		else 
		{
			
		}
		
		displayarray(array, size);
		cout << "\n\n";
		displaytree(array,size);
		
		cout << "\n\nAgain?(y/n)";
		cin >> choice;
		choice = toupper(choice);
		if (choice == 'N')
		{
			again = false;
		}
		
	}while(again);
	
	return 0;
}

void heapify(int array[], int s)
/*-------------------------------------------------------------
	 Taking an integer array and turning it into a heap
	 
	 Precondition: Array a is the array be taken; s is the size
		of the array.
	Postcondition: The array has been turned into a heap.
---------------------------------------------------------------*/
{
	for (int i = s/2; i >= 0; i--)
	{
		percolatedown(array, i, s);
	}
}

void percolatedown(int array[], int r, int s)
/*-------------------------------------------------------------
	Convert array into a heap
	
	Precondition: Array a is the array to be converted; a[i] is 
		the root of the subtree, s is the size of the array.
	Postcondition: The array has been turned into a heap.
---------------------------------------------------------------*/
{
	int temp = 0;
	int c = 2*r;
	while (c <= s)
	{
		if (c < s && array[c] < array[c + 1])
		{
			c+=1;
		} 
		if (array[r] < array[c])
		{
			temp = array[r];
			array[r] = array[c];
			array[c] = temp;
			
			r = c;
			c = c*2;
		}
		else
			break;
	}
}

void displayarray(int a[], int s)
/*-------------------------------------------------------------
	Display the elements in an array.
	
	Precondition: Array a is the array to display; s is the size
		of the array.
	Postcondition: The array has been displayed.
---------------------------------------------------------------*/
{
	for (int i = 0; i < s; i++)
		cout << a[i] << "  ";
}


void displaytree(int a[], int s)
/*--------------------------------------------------------------
	Display a binary tree stored in an array in tree format.
	
	Precondition: Binary tree is stored in an array a; 
			s is the number of nodes in the tree.
	Postcondition: The binary tree has been displayed.
---------------------------------------------------------------*/
{
	int beginindex = 0,
		endindex = 0,
		rowlength,
		numlevels = int(ceil(log(float(s))/log(2.0)));
		
	for (int level = 0; level < numlevels; level++)
	{
		displayonelevel(a, numlevels, level, beginindex, endindex);
		rowlength = endindex - beginindex + 1;
		beginindex = endindex + 1;
		endindex = min(endindex + 2*rowlength, s - 1);
	}
}


void displayonelevel(int a[], int numrows, int level, int beginindex, int endindex)
/*----------------------------------------------------------------
	Display nodes on one level of a binary tree stored in an array.
	
	Precondition: Binary tree is stored in an array a; numrows is the number of rows used to 
		display the entire tree, level is the current level being displayed; and beinindex 
		and endindex are the indices in a of the first and last nodes in this level.
	Postcondition: Nodes on this level of binary tree have een displayed.
-----------------------------------------------------------------*/
{
	int skip = int(pow(2.0, numrows - level)-1);
	for (int i = beginindex; i <= endindex; i++)
	{
		cout << setw(skip) << " ";
		cout << setw(2) << a[i];
		cout << setw(skip) << " ";
	}
	cout << "\n\n";
}
	
