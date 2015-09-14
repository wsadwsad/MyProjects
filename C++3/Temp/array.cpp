#include "array.h"

ar::ar()
{
	for(int r = 0; r < maxsize; r++)
   {
   	  for(int c = 0; c < maxsize; c++)
      {
	     
		    array[r][c] = 0;
		 
	  }
   }
}

void ar::set(int row, int col)
{
	array[row][col]++;
}

int ar::get(int row, int col)
{
	return array[row][col];
}
