#include <cassert>
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

#include "hash.h"
#include "array.h"
 
ar arr;

Table::Table()
{ cout << " loop" ;
   for ( int i = 0; i < CAPACITY; i++ )
   {
      table[i] = NULL;
   }
   
  
   
}

void Table::insert( const RecordType& entry)
{
   assert( entry.key >= 0 );

   int i = hash( entry.key ); 
   
   Node* ptr;
   Node* temp = new Node;
   temp->rec = entry;      
   temp->next = NULL;
   ptr = table[i];
   if(ptr == NULL)
   {
      table[i] = temp;
   }
   else
   {
      temp->next = table[i];
      table[i] = temp;
      ptr = temp->next;
      while (ptr != NULL)
      {
      	 int row = temp->rec.data;
      	 int col = ptr->rec.data;     	 
      	 arr.set(row, col);
      	 if(arr.get(row, col) == collisions)
      	 {
      	 	cout << "4444 and 6666" << " have "
      	 	<< collisions << " or more collisions!" << endl;
      	 }
      	 ptr = ptr->next;
      }
   }	    
}

void Table::set(int c)
{
	
    collisions = c;
}

int Table::hash( int key ) const
{
   return key % CAPACITY;
}

// print function
//     void print(); 
// Preconditions:  key >= 0
// Postconditions: print record in the table.
void Table::print()
{
	cout << "The hash table is: " << endl; 
    cout << "Index  Key/Data" << endl; 
    
	for(int i = 0; i < CAPACITY; i++)
	{
		Node* ptr = table[i];
		cout << setw(5) <<i << setw(5);
		while(ptr != NULL)
		{
			cout << ptr->rec.key <<"/"<< ptr->rec.data << setw(5);
			ptr = ptr->next;
			
		}
		cout << endl;			
	}
}
