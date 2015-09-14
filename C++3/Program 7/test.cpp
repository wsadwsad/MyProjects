//by Jie Zhou

#include <cctype>   
#include <iostream>
#include <time.h>
#include "queue_3358.h"
#include "bst_3358.h"

using namespace std;
const int maxsize = 100;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
		
	Queue_3358<int> q(15);   //create an object of Queue with size of 15
	BST_3358<int> bt;        //create an object of binary tree
	int array[maxsize];      //create an array for testing
/*
	srand(time(NULL));
	int numbers = 0;
	for(int i = 0; i < 20; i++)
	{
		int randnumber = rand() % 100;
		if(!bt.breadthFirstSearch(randnumber))
	    {
		    bt.insertItem(randnumber);
		    numbers++;
	    }
	}
	cout << numbers << " has been inserted......" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	
	bt.graph(cout);
*/	
	cout << "Queue and Tree Test..." << endl;
	cout << "Create a Queue with size 15 and a tree..." << endl;
	
	cout << "Is Queue empty? ";  //check if Queue is empty
	if(q.isEmpty())
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	cout << "Is Queue full? ";   //check if Queue is full
	if(q.isFull())
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	
	cout << "Is Tree empty? ";   //check if Tree is empty
	if(bt.isEmpty())
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	cout << "Is Tree full? ";   //check if Tree is full
	if(bt.isFull())
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	
		
	cout << "\nInsert 10 random numbers (0-100) into Queue and Tree..." << endl;
	srand(time(NULL));
	for(int i = 0; i < 10; i++)   //using ramdon number operator to generate 10 ramdon numbers and insert them into Queue and Tree
	{
		int randnumber = rand() % 100;
		cout << "insert number " << randnumber << " into Queue" << endl;
		q.enQueue(randnumber);   //insert number to Queue
		bt.insertItem(randnumber);   //insert number to Tree
	}
	
	cout << "Is Queue empty? ";
	if(q.isEmpty())
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	cout << "Is Queue full? ";
	if(q.isFull())
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	
	cout << "\nInsert other 5 random number (0-100) into Queue" << endl;  //generate other 5 numbers and insert them into tree
	for(int i = 0; i < 5; i++)
	{
		int randnum = rand() % 100;
		q.enQueue(randnum);
		cout << "insert number " << randnum << " into Queue" << endl;
	}
	
	cout << "Is Queue empty? ";
	if(q.isEmpty())
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	cout << "Is Queue full? ";
	if(q.isFull())
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	cout << "\nCheck copy constructor of Queue..." << endl;   //check copy constructor 
	Queue_3358<int> q2;
	q2 = q;
	cout <<"Print all elements in copy Queue..." << endl;
	while(!q2.isEmpty())  //print out items from the copy Queue
	{
		cout << q2.deQueue() << " ";
	}
	
	cout << "\n\nMove all element from Queue into an test array..." << endl;   //move items from Queue to array for testing
	for(int i = 0; i < 15; i++)
	{
		array[i] = q.deQueue();
		cout << "Move " << array[i] << " from Queue to array" <<endl;
	}
	
	cout << "\nTree test........" << endl;
	cout << "Print elements in the tree by preorder, inorder and postorder" << endl;
	
	cout << "\nPreOrder:  ";  //print items in tree by preorder
	bt.preOrderTraversal();
	cout << "\nInOrder:   " ;  //print items in tree by inorder
	bt.inOrderTraversal();
	cout << "\nPostOrder: ";   //print items in tree by postorder
	bt.postOrderTraversal();
	
	cout << "\nIs Tree empty? ";	
	if(bt.isEmpty())
	{
		cout << "Yes..." << endl;
	}
	else
	{
		cout << "No..." << endl;
	}
	cout << "Is Tree full? ";
	if(bt.isFull())
	{
		cout << "Yes..." << endl;
	}
	else
	{
		cout << "No..." << endl;
	}
	
	cout << "\nPick 7 random numbers from array for breadth-First-Search," << endl;//there are 15 numbers in array and 10 of them are also in Tree, pick 7 random numbers from array and use
	cout << "if the number is in tree, delete it from tree," << endl;              //breadth-First-search function to check if them are in Tree, if it is, use delete function to remove 
	cout << "otherwise, insert it into the tree..." << endl;                       //the number from Tree, if it is not, insert the number to Tree
	for(int i = 0; i < 7; i++)
	{
	    int index = rand() % 15;
	    cout << "\nPick number " << array[index] << " from array and do breadth-First-Search" << endl;
	    if(bt.breadthFirstSearch(array[index]))
	    {
	    	cout << array[index] << " found!" << endl;
	    	bt.deleteItem(array[index]);
	    	cout << array[index] << " has been deleted from the tree" << endl;
	    }
	    else
	    {
	    	cout << array[index] << " did not found!" << endl;
	    	bt.insertItem(array[index]);
	    }
    }
    
	cout << "\nPreOrder:  ";
	bt.preOrderTraversal();
	cout << "\nInOrder:   " ;
	bt.inOrderTraversal();
	cout << "\nPostOrder: ";
	bt.postOrderTraversal();
	
	cout << "\n\nTesting makeempty function...\nDeleting all items in Tree..." << endl; //check makeempty function
	bt.makeEmpty();
	cout << "Is Tree empty? ";	
	if(bt.isEmpty())
	{
		cout << "Yes..." << endl;
	}
	else
	{
		cout << "No..." << endl;
	}
	
	cout << "\n\nTest over..." << endl;
		
	return 0;
}
