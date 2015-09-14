#include <cassert>
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

#include "hash.h"
#include "array.h"
 
Array arraydata;

Table::Table()
{ 
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
   	  if (!find(i, entry))
   	  {
   	     temp->next = table[i];
         table[i] = temp;
         ptr = temp->next;
         while (ptr != NULL)
         {
      	    int row = temp->rec.data;
      	    int col = ptr->rec.data;
		    if(temp->rec.leng == ptr->rec.leng && temp->rec.first == ptr->rec.first && row != col)       	 
      	    {
      	       arraydata.set(row, col);
      	    }
      	    ptr = ptr->next;
         }
      }
   }	    
}

void Table::set(vector<string> f, int c)
{
	files = f;
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

void Table::printa()
{
	arraydata.collect(files, collisions);
	arraydata.sortprint(files);
}

bool Table::find(int key, const RecordType& entry)
{
	Node* ptr = table[key];
	while(ptr->next != NULL)
	{
		if(ptr->rec.data == entry.data)
		{
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}
