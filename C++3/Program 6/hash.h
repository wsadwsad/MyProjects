//Table class 

// Warning: The Table class does not have:
//     a destructor, 
//     copy constructor, 
//     or overloaded assignment operator.
// Do not depend on any of these working correctly.
// You should be able to do this assignment 
// without having to to write these functions.
// Just do not pass a Table by value, assign a Table to another Table, etc.

// Member functions

// CONSTRUCTOR function
//    Table( );
// Postcondition: The table is initialized as an empty table.
       
// MODIFICATION MEMBER FUNCTIONS
                  
// Insert function 
//    void insert( const RecordType& entry );
// Preconditions: entry.key >= 0. Also, if entry needs to be added to the table,
//    then there must be room left in the table (size( ) < TABLE_SIZE).
// Postcondition: If the table already has a record with key equal to 
//    the key in entry, that record will be replaced by entry.
//    Otherwise, entry will be added as a new record.
#ifndef HASH_H
#define HASH_H

#include <vector>

const int CAPACITY = 100003;

struct RecordType
{
   int key;
   int data;
   int leng;
   char first;
};

struct Node
{
   RecordType rec;
   Node* next;
};

class Table
{
public:
   Table( );
   void insert( const RecordType& entry);
   void set(vector<string> f, int c);
   void print();
   void printa();
   bool find(int key, const RecordType& entry);
private:
   int hash( int key ) const;
   Node* table[CAPACITY];
   vector<string> files;
   int collisions;
};

#endif
