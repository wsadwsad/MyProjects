//list_arrays.cpp

#include "list_3358_arrays.h"
#include <iostream>

using namespace std;

List::List()
{
	currentSize = 0;
	cursor = -1;
	head = -1;
	tail = -1;
}

List::List( const List & src )
{
	currentSize = src.currentSize;
	cursor = src.cursor;
	head = src.head;
	tail = src.tail;
	
	for (int i = 0; i < currentSize; i++)
	{
		values[i] = src.values[i];
		next[i] = src.next[i];
		previous[i] = src.previous[i];
	}
}

List::~List()
{
}

void List::insert(const value_type & item)
{
	if (!isFull())
	{
		values[currentSize] = item;
		
		if (isEmpty())
		{
			next[0] = -1;
			previous[0] = -1;
			head = 0;
			tail = 0;
			cursor = 1;
		}
		else if (atEOL())
		{
			next[tail] = currentSize;
			previous[currentSize] = tail;
			next[currentSize] = -1;
			tail = currentSize;
			cursor++;			
		}
		else
		{
			if (cursor == head)  //insert a item at the head
			{
				next[currentSize] = head;
				previous[currentSize] = -1;
				previous[head] = currentSize;
				head = currentSize;
			}
			else				//insert a item at the middle
			{
				next[previous[cursor]] = currentSize;				
				next[currentSize] = cursor;
				previous[currentSize] = previous[cursor];
				previous[cursor] = currentSize;
			}
		}
		
		currentSize++;
	}
	else
		cout << "***The list is full!***" << endl;
}

void List::remove()
{
	if (atEOL())	//if the cursor is at the end, move cursor to tail.
	{
		cursor = tail;
	}
	
	if (!isEmpty())
	{
		if (currentSize > 1)    //2 or more item in the list.
		{
			if (cursor == currentSize-1)	//the cursor is pointing to 
			{								//the last item of the array.
				if (cursor == head)		
				{
					previous[next[cursor]] = -1;
					head = next[cursor];
					cursor = head;
				}
				else if (cursor == tail)
				{
					next[previous[cursor]] = -1;
					tail = previous[cursor];
					cursor = tail;
				}
				else
				{
					previous[next[cursor]] = previous[cursor];
					next[previous[cursor]] = next[cursor];
					cursor = next[cursor];
				}
			}
			else							//the cursor is pointing to
			{								//the middle of the array.
				values[cursor] = values[currentSize-1];
				if (cursor == head)
				{
					previous[next[cursor]] = -1;
					head = next[cursor];
					
					if (tail != currentSize-1)
					{	
						previous[next[currentSize-1]] = cursor;
					}
					
					next[previous[currentSize-1]] = cursor;
					previous[cursor] = previous[currentSize-1];
					next[cursor] = next[currentSize-1];
				}
				else if (cursor == tail)
				{
					next[previous[cursor]] = -1;
					tail = previous[cursor];
					
					if (head != currentSize-1)
					{	
						next[previous[currentSize-1]] = cursor;
					}
					
					previous[next[currentSize-1]] = cursor;
					previous[cursor] = previous[currentSize-1];
					next[cursor] = next[currentSize-1];
				}
				else
				{
					if (previous[cursor] == currentSize-1)
					{
						if (head != currentSize-1)
						{
							next[previous[currentSize-1]] = cursor;
						}
						else
						{
							head = cursor;
						}
						previous[cursor] = previous[currentSize-1];
					}
					else if (next[cursor] == currentSize-1)
					{
						if (tail != currentSize-1)
						{
							previous[next[currentSize-1]] = cursor;
						}
						else
						{
							tail = cursor;
						}
						next[cursor] = next[currentSize-1];
					}
					else
					{
						next[previous[cursor]] = next[cursor];
						previous[next[cursor]] = previous[cursor];
						
						if (head != currentSize-1)
						{
							next[previous[currentSize-1]] = cursor;
						}
						else
						{
							head = cursor;
						}
						
						if (tail != currentSize-1)
						{
							previous[next[currentSize-1]] = cursor;
						}
						else
						{
							tail = cursor;
						}
						
						previous[cursor] = previous[currentSize-1];
						next[cursor] = next[currentSize-1];
					}
				}
			}
		}
		else
		{
			cursor = 0;
		}
	}	
	currentSize--;
}

void List::reset() 
{
    cursor = head;
}

bool List::advance() 
{
    if (atEOL())
    {
        return false;
    }
    else
    {
        cursor = next[cursor];
    }
	return (!atEOL());
}

bool List::isEmpty() const
{
    return (currentSize == 0);
}

bool List::atEOL() const
{
	if (cursor == currentSize || cursor == -1) 
	{
		return true;
	}
	else
		return false;
}
      
bool List::isFull() const
{
    return (currentSize == MAX_ITEMS);
}

List::value_type List::getCurrent() const
{
    if(!atEOL())
    {
        return values[cursor];
	}
}

