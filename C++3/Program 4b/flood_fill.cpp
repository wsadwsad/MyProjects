//stack_test.cpp
//CS3358- Jie Zhou
//tests a very simple cursor based Stack ADT

#include <iostream>
#include <fstream>

#include "stack_3358.h"

using namespace std;

int main (int argc, char * argv[]) 
{  
   Stack_3358<int> myStack;
   string exp;
   
   //create a 2-D array to store the picture
   const int num = 25;
   char myarray[num][num];
   //to store number of row of the picture
   int arrayRow = 0;
   //to count number of items that store in the array	
   int numberofitem = 0;  
   
   //read txt file line by line to store into the array
   ifstream inFile;
   inFile.open(argv[1]);
   while(getline(inFile, exp))	
   {
     for ( int i = 0; i < exp.length(); i++)
     {
     	myarray[arrayRow][i] = exp[i];
     	numberofitem++;
     }
     arrayRow++;
   }
   
   //create two variables to hold uer`s inputing
   int row = 0;
   int col = 0;
   // calculate the number of colume of the pucture
   int arrayCol = numberofitem/arrayRow; 
   
   //check if row is -1, if is, terminate program
   while (row != -1)						
   {
   	  //create a char variable to hold the color that uer`s input
   	  char color;
	  //print the picture
   	  for (int j = 0; j < arrayRow; j++)	
	  {	 
		 for (int k = 0; k < arrayCol; k++)
		 {
			 cout << myarray[j][k];
		 }
		 cout <<"\n";
	  }
      
	  //ask user to enter numbers
	  cout <<"\n";							
      cout << "Enter a row: ";
      cin >> row;
      cout << "Enter a colume: ";
      cin >> col;
      cout << "Enter a color: ";
      cin >> color;
      
	  //check the row, if it is -1. terminater program
      if (row == -1)						
      {
      	  cout << "\nProgram terminate..." << endl;
      }
	  //check the numbers that user input are in the range, if not, input again
      else if (row >= arrayRow || row < -1 || col >= arrayCol || col < 0)	
      {
      	  cout << "\nEnter a number between 0 to " << arrayRow - 1 << " for row." << endl;
      	  cout << "Enter a number between 0 to " << arrayCol - 1 << " for colume." << endl;
      	  cout << "Input again...\n\n";
      }
      else if (myarray[row][col] == color)
      {
      	  cout << "The color user input is same as the position where user choose..\n" << endl;
      }
      else
      {
	     //create a variable to hold the old value that uer need to change
	     char temp = myarray[row][col];
      	 //push the position that user input into stack		
		 myStack.push((row * 100) + col);		
		 
		 //check if there are items in stack
		 //if there id no item in stack means all color has been changed
		 while(!myStack.isEmpty())				
		 {
		    //pop the position from stack
		    int position = myStack.pop();
			//get the row		
      	  	row = position / 100;
			//get the columne				
      	  	col = position % 100;
      	  	//change the value at that position to what user input
      	  	myarray[row][col] = color;
      	  	
			//check if the curren position is the first row, if it is, then there is no item above this position
			if (row > 0)
      	  	{
      	  		//check the value of the position where is above the curren position
				if (myarray[row - 1][col] == temp)
      	  	 	{
      	  	 		myStack.push(((row - 1) * 100) + col);
      	  	 	}
      	  	}
      	  	//check if the curren position is the last row, if it is, then there is no item below this position
      	  	if (row < arrayRow - 1)
      	  	{
      	  		//check the value of the position where is below the curren position
      	  	 	if (myarray[row + 1][col] == temp)
      	  	 	{
      	  	 		myStack.push(((row + 1) * 100) + col);
      	  	 	}
      	  	}
      	  	//check if the curren position is the first colume, if it is, then there is no item on the left of this position
      	  	if (col > 0)
      	  	{
      	  		//check the value of the position where is on the left of the curren position
      	  		if (myarray[row][col - 1] == temp)
      	  		{
      	  			myStack.push((row * 100) + (col - 1));
      	  		}
      	  	}
      	  	//check if the curren position is the last colume, if it is, then there is no item on the right of this position
      	  	if (col < arrayCol - 1)
      	  	{
      	  		//check the value of the position where is on the right of the curren position
      	  		if (myarray[row][col + 1] == temp)
      	  		{
      	  			myStack.push((row * 100) + (col + 1));
      	  		}
      	  	}
      	  	//check if the curren position is the top left corner
      	  	if (row > 0 && col > 0)
      	  	{
      	  		//if the curren position is not the top left corner and the values of it above and left are not match with the old value, check the top left one
      	  		if(myarray[row - 1][col] != temp && myarray[row][col - 1] != temp && myarray[row - 1][col - 1] == temp)
      	  		{
      	  			myStack.push(((row - 1) * 100) + (col - 1));
      	  		}
      	  	}
      	  	//check if the curren position is the top right corner
      	  	if (row > 0 && col < arrayCol - 1)
      	  	{
      	  		//if the curren position is not the top right corner and the values of it above and right are not match with the old value, check the top right one
      	  		if(myarray[row - 1][col] != temp && myarray[row][col + 1] != temp && myarray[row - 1][col + 1] == temp)
      	  		{
      	  			myStack.push(((row - 1) * 100) + (col + 1));
      	  		}
      	  	}
      	  	//check if the curren position is the lower left corner
      	  	if (row < arrayRow - 1 && col > 0)
      	  	{
      	  		//if the curren position is not the lower left corner and the values of it below and left are not match with the old value, check the lower left one
      	  		if(myarray[row + 1][col] != temp && myarray[row][col - 1] != temp && myarray[row + 1][col - 1] == temp)
      	  		{
      	  			myStack.push(((row + 1) * 100) + (col - 1));
      	  		}
      	  	}
      	  	//check if the curren position is the lower right corner
      	  	if (row < arrayRow - 1 && col < arrayCol - 1)
      	  	{
      	  		//if the curren position is not the lower right corner and the values of it below and right are not match with the old value, check the lower right one
      	  		if(myarray[row + 1][col] != temp && myarray[row][col + 1] != temp && myarray[row + 1][col + 1] == temp)
      	  		{
      	  			myStack.push(((row + 1) * 100) + (col + 1));
      	  		}
      	  	}
      	  	
      	  	
      	  }
      	  //reset two variables for holding next data
      	  row = 0;
      	  col = 0;
      	  cout <<"\n\n";
      }
      
   }
   
   
   inFile.close();
}
