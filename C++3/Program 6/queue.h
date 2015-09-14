#ifndef Queue_H
#define Queue_H

#include <cassert>
#include "list.h"

using namespace std;

template<class ItemType>
class Queue {
 public:
        
   // typedef int value_type;
    typedef int size_type;
    
    Queue();
    
    //Copy constructor
    Queue(const Queue & src);
    
/****************************  
makeEmpty
  
Function: Removes all the items from the Queue. 
Preconditions: Queue has been initialized 
Postconditions: All the items have been removed
*****************************/        
    void makeEmpty();
    
/****************************  
isEmpty
  
Function: Checks to see if there are any items on the Queue. 
Preconditions: Stack has been initialized
Postconditions: Returns true if there are no items on the Queue, else false.
*****************************/        
    bool isEmpty() const;
    
/****************************  
isFull
  
Function: Determines if you have any more room to add items to the Queue
Preconditions: Queue has been initialized
Postconditions: Returns true if there is no more room to add items, else false
*****************************/        
    bool isFull() const;

/****************************  
push
  
Function: Adds newItem to the top of the Queue. 
Preconditions: Queue has been initialized and is not full.
Postconditions: newItem is at the top of the Queue.
*****************************/    
 	void push(const ItemType &);
 	
 	
/****************************  
pop
  
Function: Removes topItem from Queue and returns it.
Preconditions: Queue has been initialized and is not empty.
Postconditions: Top element has been removed from Queue and item is a copy of the removed element. 
*****************************/  	
ItemType pop();
ItemType getall();
    
    
 private:
    List<ItemType> list;

}; 

/*******************************
/ Function implementations
********************************/

template<class ItemType>
Queue<ItemType>::Queue ()
{
}

template<class ItemType>
Queue<ItemType>::Queue(const Queue & src)
{
   list.list(src);
}


template<class ItemType>
void Queue <ItemType>::makeEmpty()
{

   while(!list.isEmpty())
   {
   list.remove();
   }
   
}

template<class ItemType>
bool Queue <ItemType>::isEmpty() const
{  
   return list.isEmpty();  
}

template<class ItemType>
bool Queue <ItemType>::isFull() const
{
   return false; //temporary (could use the try/catch memory allocation)    
}


template<class ItemType>
void Queue <ItemType>::push(const ItemType& newItem)
{
   list.insert(newItem);
}


template<class ItemType>
ItemType Queue <ItemType>::pop()
{
   assert(!isEmpty());
   
   list.reset();
   ItemType temp = list.getCurrent();
   list.remove();

   return temp;
}

template<class ItemType>
ItemType Queue <ItemType>::getall()
{
	string temp;
	list.reset();
	
	while (!list.atEOL())
	{
		temp += list.getCurrent();
		list.advance();
	}

	return temp;
}

#endif
