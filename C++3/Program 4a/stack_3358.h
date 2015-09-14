
/*  stack_3358_LL.h
  CS 3358 Spring 2011
  
  Jie Zhou
  
  a very simple linked list Stack ADT
  
*/

#ifndef STACK_3358_H
#define STACK_3358_H

#include <cassert>
#include "list_3358.h"

using namespace std;

template<class ItemType>
class Stack_3358 {
 public:
        
   // typedef int value_type;
    typedef int size_type;
    
    Stack_3358();
    
    //Copy constructor
    Stack_3358(const Stack_3358 & src);
    
/****************************  
makeEmpty
  
Function: Removes all the items from the stack. 
Preconditions: Stack has been initialized 
Postconditions: All the items have been removed
*****************************/        
    void makeEmpty();
    
/****************************  
isEmpty
  
Function: Checks to see if there are any items on the stack. 
Preconditions: Stack has been initialized
Postconditions: Returns true if there are no items on the stack, else false.
*****************************/        
    bool isEmpty() const;
    
/****************************  
isFull
  
Function: Determines if you have any more room to add items to the stack
Preconditions: Stack has been initialized
Postconditions: Returns true if there is no more room to add items, else false
*****************************/        
    bool isFull() const;

/****************************  
push
  
Function: Adds newItem to the top of the stack. 
Preconditions: Stack has been initialized and is not full.
Postconditions: newItem is at the top of the stack.
*****************************/    
 	void push(const ItemType &);
 	
/****************************  
pop
  
Function: Removes topItem from stack and returns it.
Preconditions: Stack has been initialized and is not empty.
Postconditions: Top element has been removed from stack and item is a copy of the removed element. 
*****************************/  	
ItemType pop();
    
    
 private:
    List<ItemType> list;

}; 

/*******************************
/ Function implementations
********************************/

template<class ItemType>
Stack_3358<ItemType>::Stack_3358 ()
{
}

template<class ItemType>
Stack_3358<ItemType>::Stack_3358(const Stack_3358 & src)
{
        list.list(src);
}


template<class ItemType>
void Stack_3358 <ItemType>::makeEmpty()
{

         while(!list.isEmpty())
         {
         	list.remove();
         }
   
}

template<class ItemType>
bool Stack_3358 <ItemType>::isEmpty() const
{  
   return list.isEmpty();  
}

template<class ItemType>
bool Stack_3358 <ItemType>::isFull() const
{
   return false; //temporary (could use the try/catch memory allocation)    
}


template<class ItemType>
void Stack_3358 <ItemType>::push(const ItemType& newItem)
{
   list.reset();
   list.insert(newItem);
}


template<class ItemType>
ItemType Stack_3358 <ItemType>::pop()
{
   assert(!isEmpty());
	
   list.reset();
   ItemType temp = list.getCurrent();
   list.remove();

   return temp;
   
}

#endif
