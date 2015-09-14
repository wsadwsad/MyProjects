/*
Jie Zhou
*/

#include "list_3358_pointers.h"
#include <iostream>

using namespace std;

List::List()
{
	head = NULL;
    tail = NULL;
    cursor = NULL;
}

List::List( const List & src )
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

List::~List() 
{
	Node *p = head;

    while (head != NULL)
    {
    	head = head->next;
        delete p;
        p = head;
    }
 
}

void List::insert(const value_type & item)
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
    
void List::remove()
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

void List::reset()
{        
    cursor = head;
}
      
bool List::advance() 
{
    if (!atEOL())
    {
        cursor = cursor->next;
	}
    return (!atEOL()); 
}      

bool List::isEmpty() const 
{     
    return (head == NULL);
}
   
bool List::atEOL() const 
{
    return (cursor==NULL);        
}

bool List::isFull() const 
{
    return false;
}

List::value_type List::getCurrent() const 
{
    if (!atEOL())
    {
    	return cursor->value;
	}
}
