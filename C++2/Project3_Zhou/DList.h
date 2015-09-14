/*-- DList.h --------------------------------------------------------------
 
  This header file defines the data type List for processing lists.
  Basic operations are:
     Constructor
     Destructor
     Copy constructor
     Assignment operator
     empty:    Check if list is empty
     insert:   Insert an item
     erase:    Remove an item
     resize:   change capacity Added by Jie Zhou on October 1, 2014
     getmysize:return mySize Added by Jie Zhou on October 1, 2014
     getcapacity:return myCaoacity Added by Jie Zhou on October 1, 2014 
     display:  Output the list
     << :      Output operator
-------------------------------------------------------------------------*/

#include <iostream>

#ifndef DLIST
#define DLIST

typedef int ElementType;
class List
{
 public:
 /******** Function Members ********/
   /***** Class constructor *****/
   List(int maxSize = 1024);
   /*----------------------------------------------------------------------
     Construct a List object.

     Precondition:  maxSize is a positive integer with default value 1024.
     Postcondition: An empty List object is constructed; myCapacity ==
         maxSize (default value 1024); myArray points to a dynamic
         array with myCapacity as its capacity; and mySize is 0.
   -----------------------------------------------------------------------*/

   /***** Class destructor *****/
   ~List();
   /*----------------------------------------------------------------------
     Destroys a List object.

     Precondition:  The life of a List object is over.
     Postcondition: The memory dynamically allocated by the constructor
         for the array pointed to by myArray has been returned to the heap.
   -----------------------------------------------------------------------*/

   /***** Copy constructor *****/
   List(const List & origList);
   /*----------------------------------------------------------------------
     Construct a copy of a List object.

     Precondition:  A copy of origList is needed; origList is a const
         reference parameter. 
     Postcondition: A copy of origList has been constructed.
   -----------------------------------------------------------------------*/

   /***** Assignment operator *****/
   List & operator=(const List & rightHandSide);
   /*----------------------------------------------------------------------
     Assign a copy of a List object to the current object.

     Precondition: none 
     Postcondition: A copy of rightHandSide has been assigned to this
         object. A reference to this list is returned.
   -----------------------------------------------------------------------*/

   /***** empty operation *****/
   bool empty() const;
   //--- See Figure 6.1 for documentation

   /***** insert and erase *****/
   void insert(ElementType item, int pos);
   //--- See Figure 6.1 for documentation (replace CAPACITY with myCapacity)

   void erase(int pos);
   //--- See Figure 6.1 for documentation

   /***** output *****/
   void display(ostream & out) const;
   //--- See Figure 6.1 for documentation
   
    /***** resize operation *****/
  
   void resize(int newcapacity);
    /*----------------------------------------------------------------------
     Change the capacity of a list
 
     Precondition:  None.
     Postcondition: The list's current capacity is changed to newCapacity
         (but not less than the number of items already in the list).
   -----------------------------------------------------------------------*/
   
   int getmysize();
   
   int getcapacity();
   

 private:
 /******** Data Members ********/
   int mySize;                // current size of list
   int myCapacity;            // capacity of array
   ElementType * myArray;     // pointer to dynamic array

}; //--- end of List class

//------ Prototype of output operator
ostream & operator<< (ostream & out, const List & aList);

#endif
