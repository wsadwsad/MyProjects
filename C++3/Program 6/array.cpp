#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

#include "array.h"

Array::Array()
{
	for(int r = 0; r < maxsize; r++)
   {
   	  for(int c = 0; c < maxsize; c++)
      {	     
		    array[r][c] = 0;		 
	  }
   }
   
   size = 0;
}

void Array::set(int row, int col)
{
	array[row][col]++;
}

int Array::get(int row, int col)
{
	return array[row][col];
}

void Array::collect(vector<string> &files, int collisions)
{
    for (int c = 2; c < files.size()-1; c++)
	{
        for (int r = c+1; r <files.size(); r++)
		{
		
	       if(array[r][c] >= collisions)
      	   {
		      data[size].collision = array[r][c];
		      data[size].row = r;
		      data[size].col = c;
		      size++;
      	   }
        }
    }
}

void Array::sortprint(vector<string> &files)
{
	data1 temp;
	bool on = false;
	while (on == false)
	{
		on = true;
		for (int i = 0; i < size-1; i++)
		{
			if(data[i].collision < data[i+1].collision)
			{
				temp = data[i];
				data[i] = data[i+1];
				data[i+1] = temp;
				on = false;
			}
		}
	}
	
	cout << "\nCollisions          File1 name               File2 name" << endl;
	for (int j = 0; j < size; j++)
	{
		cout << setw(5) <<data[j].collision << setw(25) 
		     << files[data[j].row] << setw(25) << files[data[j].col] << endl;
    }
	
}
