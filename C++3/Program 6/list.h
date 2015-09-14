#ifndef LIST_H
#define LIST_H

#include <cstdlib>  // Provides size_t

using namespace std;

template<class ItemType>
 class List 
 {
   
   public:
          
          
      typedef ItemType value_type;
      
   
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
      
      
      void toEol ( );


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
       
       ItemType getCurrent ( ) const;
      
     
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


/*******************************
/ Function implementations
********************************/

template<class ItemType>
List<ItemType>::List()
{
	head = NULL;
    tail = NULL;
    cursor = NULL;
}

template<class ItemType>
List<ItemType>::List( const List & src )
{
	if (src.head == NULL)
    {
    	head = NULL;
        tail = NULL;
        cursor = NULL;
    }
    else
    {
    	Node *temp;
    	Node *priv = NULL;
    	
    	for ( Node *p = src.head; p != NULL; p = p->next)
    	{
    		temp = new Node;
    		temp->value = p->value;
    		temp->next = NULL;
    		
    		if(priv == NULL)
    		{
    			priv = temp;
    		}
    		else
    		{
    			temp->previous = priv;
    			priv->next = temp;
				priv = temp;	
    		}
    		
    		if(p == src.head)
    		{
    			temp->previous = NULL;
    			head = temp;
    		}
    		if (p == src.cursor)
            {
                cursor = temp;
            }
            if (p == src.tail)
            {
                tail = temp;
                temp->next = NULL;
            }
    		
    	}
    }
}

template<class ItemType>
List<ItemType>::~List() 
{
	Node *p = head;

    while (head != NULL)
    {
    	head = head->next;
        delete p;
        p = head;
    }
 
}

template<class ItemType>
void List<ItemType>::insert(const value_type & item)
{ 

    if (!isFull())
    {
        Node *temp = new Node;
        temp->value = item;
        temp->next = NULL;
        temp->previous = NULL;
        
        if(isEmpty())
        {
        	head = temp;
        	tail = temp;
        }
        else if(atEOL())
        {
        	tail->next = temp;
        	temp->previous = tail;
        	tail = temp;
        }
        else
        {
        	if(cursor == head)
        	{
        		temp->next = cursor;
        		cursor->previous = temp;
        		head = temp;
        	}
        	else
        	{
        		Node *p = head;
                while (p->next != cursor)
                {
                	p = p->next;
                }

                p->next = temp;
                temp->previous = p;
                temp->next = cursor;
                cursor->previous = temp;
        	}
        }
    }

}

template<class ItemType>    
void List<ItemType>::remove()
{
	if (atEOL())
	{
		cursor = tail;
	}
	
	if(!isEmpty())
    {
    	Node *p = head;
    		
    	if(cursor == head)
    	{
    		head = head->next;
    		delete p;
    		cursor = head;
    		
    		if(head == NULL)
    		{
    			tail = NULL;
    		}
    	}
    	else
    	{
    		while(p->next != cursor)
    		{
    			p = p->next;
    		}    		

    		p->next = cursor->next;
 
    		if (cursor == tail)
            {
            	delete cursor;
                tail = p;
                cursor = tail;
            }
            else
            {
                delete cursor;
                cursor = p->next;
                cursor->previous = p;   		
    		}
    	}
	}
}

template<class ItemType>
void List<ItemType>::reset()
{        
    cursor = head;
}

template<class ItemType>
void List<ItemType>::toEol()
{        
    cursor = tail;
}

template<class ItemType>      
bool List<ItemType>::advance() 
{
    if (!atEOL())
    {
        cursor = cursor->next;
	}
    return (!atEOL()); 
}      

template<class ItemType>
bool List<ItemType>::isEmpty() const 
{     
    return (head == NULL);
}

template<class ItemType>   
bool List<ItemType>::atEOL() const 
{
    return (cursor==NULL);        
}

template<class ItemType>
bool List<ItemType>::isFull() const 
{
    return false;
}

template<class ItemType>
ItemType List<ItemType>::getCurrent() const 
{
    if (!atEOL())
    {
    	return cursor->value;
	}
}

#endif
