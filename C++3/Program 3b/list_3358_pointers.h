/*  list.h

Jie Zhou

  a very simple cursor based List ADT
  
  -It is homogenious -- the elements in the collection are all of the same type.
    -It has a finite length (the number of elements).
    -The elements are arranged sequentially:
          o There is a first element and a last element
          o Every element except the last has a unique successor
          o Every element except the first has a unique predecessor
*/

#ifndef LIST_H
#define LIST_H

#include <cstdlib>  // Provides size_t




using namespace std;


 class List 
 {
   
   public:
          
          
      typedef int value_type;
      typedef size_t size_type;
      
   
      //Constructor/Destructor
      //Preconditions: None.
      //Postconditions: Creates an empty list capable of holding Item type data items. 
      //Current position is at BOL/EOL. 
      //The List has a capacity of at most MAX_ITEMS items.
      
      List ( );

      //Preconditions: None
      //Postconditions: Creates a new List which is a deep copy of the passed src List. 
      //Implement the copy constructor last, after the rest of the implementation has been debugged.
      
      List ( const List & src );

      //Preconditions: None.
      //Postconditions: Destroys the list, cleaning up all resources associated with the object.
      
      ~List ( );

      
      //************************************
      //Mutator(s)
      
      //Preconditions: List is not full (i.e. the number of items currently in the list is less than its capacity).
      //Postconditions: The item has been inserted by copying into the list. 
      //Location of the insert occurs at the current position (the item previously at the current position
      // is moved to the next position in the list). 
      //After an insert, the current position remains the same.
      //If the current position is at the end of the list, the current position will remain 
      //at the end of the list after the insert.
      
      void insert ( const value_type & item );


      //Preconditions: Current position is not EOL and list is not empty.
      //Postconditions: The item at the current position is removed from the list. 
      //The current position becomes that of the item's successor, 
      //or EOL if the removed item were the last in the list.  
      
      void remove ( );


      //Preconditions: None.
      //Postconditions: Resets the current position to the beginning of the list BOL. 
      //If the list is empty, then the position is set to EOL. 
      
      void reset ( );


      //Preconditions: None.
      //Postconditions: Advances the current position to the next item in the list. 
      //Advancing from EOL leaves the current position at EOL. 
      //If the position following the advance is not EOL, the result of the function is TRUE, 
      //and if the position following the advance is EOL, the result of the function is FALSE. 
      
      bool advance ( );

      

      //*******************
      // Accessor(s)
      
      //Preconditions: None.
      //Postconditions: Return value is true if the list contains no items, and false otherwise.
      
      bool isEmpty ( ) const;


      //Preconditions: None.
      //Postconditions: Return value is true if the current position is logically at EOL, 
      //and false otherwise.
      
      bool atEOL ( ) const;


      //Preconditions: None.
      //Postconditions: Return value is true if the list contains its capacity of items, 
      //and false otherwise.
      
      bool isFull ( ) const;



      //Preconditions: Current position is not EOL or at BOL.
      //Postconditions: Return value is a copy of the item at the current position. 
      //The list is unaffected. 
       
       value_type getCurrent ( ) const;
      
     
   private:
           
      struct Node {
         value_type value;
         Node* next;
         Node* previous;
      };
      
      Node* head;
      Node* tail;
      Node* cursor;
      
 };


#endif
         
         
   
