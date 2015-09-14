This program is written by Jie Zhou

					Tree Search
	This program is checking the functins of Queue and inserting and removing items from a binary search tree and then using Queue to do a Breadth-First-search on the BST as well as the typical traversals


				       How to test the program
	For testing this program, first, create a Queue with size 15 and a binary  tree, then generate 10 random numbers and insert them into Queue and Tree, check them are empty and full. Generate other 5 random numbers and insert into Queue, check Queue is empty and full. Then, create another Queue and copy all data from the first Queue to check the copy constructor, print out all data from copy Queue. Then create an array and move all data from Queue to array for tree testing.
Pick 7 numbers from array randomly and do Breadth-First-search, if find a number which is equal the random number, then delete this number from the tree, if not, insert the number into the tree. Finaly, using makeEmpty function to clear all item in Tree.

				       Does it have any bugs?
So far, I have not found any bugs and the program runs successfully

				       Name of files
test.cpp  bst_3358.h  queue_3358.h