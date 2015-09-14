#include <cassert>
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

#include "hash_chn.h"

Table::Table( )
{
   used = 0;
   for ( int i = 0; i < CAPACITY; i++ )
      table[i] = NULL;
}

void Table::insert( const RecordType& entry )
{
   bool alreadyThere;
   Node* nodePtr;
   
   assert( entry.key >= 0 );
   
   findPtr( entry.key, alreadyThere, nodePtr );
   if( !alreadyThere )
   {
      int i = hash( entry.key );      // get index of "bucket" where entry belongs
      // insert at beginning of list
      Node* temp = new Node;
      temp->rec = entry;      // copy record
      temp->next = table[i];
      table[i] = temp;
      used++;
	    
   }
   else 
   {
      // nodePtr points to existing record that should be updated
      nodePtr->rec = entry;
   } 
}


int Table::hash( int key ) const
{
   return key % CAPACITY;
}

int Table::size( ) const
{
   return used;
}  

// findPtr function
//     void findPtr( int key, bool& found, Node*& nodePtr ) const; 
// Preconditions:  key >= 0
// Postconditions: If a record with the indicated key is in the table, 
//    then found is true and nodePtr is set to point to that record.
//    Otherwise, found is false and nodePtr contains garbage. 

void Table::findPtr( int key, bool& found, Node*& nodePtr ) const
{
   int i;
   Node* ptr;

   i = hash( key );
   ptr = table[i];
   found = false;
   while ( !found && ptr != NULL )
   {
      if ( key == ptr->rec.key )
      {
         found = true;
         nodePtr = ptr;
      }
      ptr = ptr->next;
   }   
   if ( !found )
      nodePtr = NULL;
}

void Table::find( int key, bool& found, RecordType& result ) const
{
   Node* nodePtr;
   
   assert( key >= 0 );
   
   findPtr( key, found, nodePtr );
   if ( found )
   {
      result = nodePtr->rec;
   }
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
		while(ptr != 0)
		{
			cout << ptr->rec.key <<"/"<< ptr->rec.data << setw(5);
			ptr = table[i]->next;
			
		}
		cout << endl;			
	}
}

// Erase function
// 	  void erase(int key); 
//    Preconditions:  key >= 0 
//    Postconditions: If a record with the specified key exists in the table, then 
//    that record has been removed; otherwise the table is unchanged. 
void Table::erase(int key)
{	
	int i = hash(key);
	Node* predptr = table[i];
    while(predptr != NULL)
    {
    	if(key == predptr->rec.key)
    	{
    		table[i] = predptr->next;
    		delete predptr;
    		used--;
    	}
    	else
    	{
    		predptr = predptr->next;
    	}
    }
}
