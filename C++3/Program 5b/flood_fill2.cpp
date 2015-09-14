//CS3358- Jie Zhou
//tests a very simple cursor based Stack ADT

#include <iostream>
#include <fstream>

using namespace std;
const int num = 25;

void floodfill(char myarray[num][num], int row, int col, char color, int arrayRow, int arrayCol);
void printp(char myarray[num][num], int row, int col, int arrayRow, int arrayCol);

int main (int argc, char * argv[]) 
{  
   string exp;
   
   //create a 2-D array to store the picture
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
   	  /*for (int j = 0; j < arrayRow; j++)	
	  {	 
		 for (int k = 0; k < arrayCol; k++)
		 {
			 cout << myarray[j][k];
		 }
		 cout <<"\n";
	  }
      */
      printp(myarray, 0, 0, arrayRow, arrayCol);
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
	      floodfill(myarray, row, col, color, arrayRow, arrayCol);
      	  //reset two variables for holding next data
      	  row = 0;
      	  col = 0;
      	  cout <<"\n\n";
      }
      
   }
   
   
   inFile.close();
}

//Function floodfill
//input parameter - an array, four integers and an character
//change the color of the position where uer input, then compare the color around the position
//if match, then call the function by passing the new position as parameter  
void floodfill(char myarray[num][num], int row, int col, char color, int arrayRow, int arrayCol)
{
		 
	char temp = myarray[row][col];
    //change the value at that position to what user input
    myarray[row][col] = color;
      	  	
	//check if the curren position is the first row, if it is, then there is no item above this position
	if (row > 0)
    {	
      	//check the value of the position where is above the curren position
		if (myarray[row - 1][col] == temp)
      	{
      	  	floodfill(myarray, row-1, col, color, arrayRow, arrayCol);
      	}
    }
    //check if the curren position is the last row, if it is, then there is no item below this position
    if (row < arrayRow - 1)
    {
      	//check the value of the position where is below the curren position
      	if (myarray[row + 1][col] == temp)
      	{
      	  	floodfill(myarray, row+1, col, color, arrayRow, arrayCol);
      	}
    }
    //check if the curren position is the first colume, if it is, then there is no item on the left of this position
    if (col > 0)
    {
      	//check the value of the position where is on the left of the curren position
      	if (myarray[row][col - 1] == temp)
      	{
      	  	floodfill(myarray, row, col-1, color, arrayRow, arrayCol);
      	}
    }
    //check if the curren position is the last colume, if it is, then there is no item on the right of this position
    if (col < arrayCol - 1)
    {
      	//check the value of the position where is on the right of the curren position
      	if (myarray[row][col + 1] == temp)
      	{
      	  	floodfill(myarray, row, col+1, color, arrayRow, arrayCol);
      	}
    }
    //check if the curren position is the top left corner
    if (row > 0 && col > 0)
    {
      	//if the curren position is not the top left corner and the values of it above and left are not match with the old value, check the top left one
      	if(myarray[row - 1][col] != temp && myarray[row][col - 1] != temp && myarray[row - 1][col - 1] == temp)
      	{
      	  floodfill(myarray, row-1, col-1, color, arrayRow, arrayCol);
      	}
    }
    //check if the curren position is the top right corner
    if (row > 0 && col < arrayCol - 1)
    {
      	//if the curren position is not the top right corner and the values of it above and right are not match with the old value, check the top right one
      	if(myarray[row - 1][col] != temp && myarray[row][col + 1] != temp && myarray[row - 1][col + 1] == temp)
      	{
      	  	floodfill(myarray, row-1, col+1, color, arrayRow, arrayCol);
      	}
    }
    //check if the curren position is the lower left corner
    if (row < arrayRow - 1 && col > 0)
    {
      	//if the curren position is not the lower left corner and the values of it below and left are not match with the old value, check the lower left one
      	if(myarray[row + 1][col] != temp && myarray[row][col - 1] != temp && myarray[row + 1][col - 1] == temp)
      	{
      	  	floodfill(myarray, row+1, col-1, color, arrayRow, arrayCol);
      	}
    }
    //check if the curren position is the lower right corner
    if (row < arrayRow - 1 && col < arrayCol - 1)
    {
      	//if the curren position is not the lower right corner and the values of it below and right are not match with the old value, check the lower right one
      	if(myarray[row + 1][col] != temp && myarray[row][col + 1] != temp && myarray[row + 1][col + 1] == temp)
      	{
      	  	floodfill(myarray, row+1, col-1, color, arrayRow, arrayCol);
      	}
    }
      	  	
}

//Print funciton
//print element in the array one by one
void printp(char myarray[num][num], int row, int col, int arrayRow, int arrayCol)
{
	if(row < arrayRow)
	{
		if(col < arrayCol)
		{
			cout << myarray[row][col];
			printp(myarray, row, col+1, arrayRow, arrayCol);
		}
		else
		{
			cout <<"\n";
			printp(myarray, row+1, 0, arrayRow,arrayCol);
		}
	}
}
