#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
#include "List.h"

List::List():first(0),mySize(0)
/* Definition of the Constructor */
{
}

List::List(const List & source)
/* Definition of the copy Constructor */
{
	first = 0;
	if (!source.empty())
	{
		first = new List::Node(source.first->data);
		List::NodePointer lastptr = first,
					  	  origptr = source.first->next;
		while (origptr != 0)
		{
			lastptr->next = new List::Node(origptr->data);
			lastptr = lastptr->next;
			origptr = origptr->next;
		}
		mySize = source.mySize;
	}
	else
   	{
       mySize = 0;
   	}
}

List::~List()
/* Definition of the Destructor */
{
	List::NodePointer currptr = first,
					  nextptr;
	while (currptr != 0)
	{
		nextptr = currptr->next;
		delete currptr;
		currptr = nextptr;
		mySize--;
	}
}

List & List::operator=(const List &rightside)
/* Definition of the assignment operator */
{
	if (this != &rightside)
	{
		this->~List();
		if(rightside.empty())
			first = 0;
		else
		{
			first = new List::Node(rightside.first->data);
			List::NodePointer lastptr = first,
							  rsptr = rightside.first->next;
			while (rsptr != 0)
			{
				lastptr->next = new List::Node(rsptr->data);
				lastptr = lastptr->next;
				rsptr = rsptr->next;
			}
		}
	}
	return *this;
}

int List::getSize() const
/* Definition of getSize function */
{
	return mySize;
}

bool List::empty() const
/* Definition of empty function */
{
	return mySize == 0;
}


void List::display(ostream &out) const
/* Definition of display function */
{
	List::NodePointer ptr;
	for(ptr = first; ptr != 0; ptr = ptr->next)
		out << ptr->data << " ";
	out << "\nThe Size is: " << mySize <<endl;
}

void List::insert(ElementType dataVal, int index)
/* Definition of insert function */
{
	if(first == 0)
	{
		cerr << "*** List is empty! Creating a list with the data which input by user. ***" << endl;
		first = new List::Node(dataVal);
		mySize++;
		return;
	}
	
	else if (index < 0 || index > mySize)
    {
       cerr << "*** Illegal location to insert -- " << index 
            << ".  List unchanged. ***\n";
       return;
    }
    
    else
    {	List::NodePointer pred = first,
    					newptr = new List::Node(dataVal);
    	
    	if(index == 0)
    	{
       		first = newptr;
       		newptr->next = pred;
    		mySize++;
    	}
    	
    	else if (index == mySize)
    	{
    		while (pred->next != 0)
    			pred = pred->next;
    		
			newptr->next = 0;
    		pred->next = newptr;
    		mySize++;
    	}
    	
		else	
		{
			for (int i = 0; i < index-1; i++)
    			pred = pred->next;
    		
			newptr->next = pred->next;
    		pred->next = newptr;
    		mySize++;
    	}
    }
}

void List::erase(int index)
/* Definition of erase function */
{
	if(first == 0)
	{
		cerr << "*** List is empty. ***" << endl;
		return;
	}
	
	else if(index < 0 || index >=mySize)
	{
		cerr << "*** Illegal location to erase -- " << index
             << ".  List unchanged. ***\n";
        return;
	}
	
    else
    {
    	List::NodePointer currptr = first,
					  	nextptr;
					  	
		if (index == 0)
		{
			first = currptr->next;
			delete currptr;
			mySize--;
		}
		else
		{
			for (int i = 0; i < index-1; i++)
			{
				currptr = currptr->next;
			}
			nextptr = currptr->next;
			currptr->next = nextptr->next;
			delete nextptr;
			mySize--;
		}
    }
}

int List::find(ElementType value) const
/* Definition of find function */
{
	List::NodePointer ptr;
	int position = 0;
	for(ptr = first; ptr != 0; ptr = ptr->next)
	{
		if (value.compare(ptr->data) == 0)
		{
			return position;
		}
		else
		{
			position++;
		}		
	}
	return position = -1;
}
