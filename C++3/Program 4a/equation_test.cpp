//stack_test.cpp
//CS3358- Jie Zhou
//tests a very simple cursor based Stack ADT

#include <iostream>
#include <fstream>

#include "stack_3358.h"

using namespace std;

int main (int argc, char * argv[]) 
{  
   Stack_3358<char> myStack;
   
   string exp;
   //read file
   ifstream inFile;
   inFile.open(argv[1]);
   while(getline(inFile, exp))
   {   
      //create two variables to check status
      int mark_1 = 0;
      int mark_2 = 0;
      
      for(int j = 0; j < exp.length(); j++)
	  {
	  	 cout << exp[j];
	  }

	  //empty the stack to get ready for check equation
      myStack.makeEmpty();
      
      for (int i = 0; i < exp.length(); i++)
	  {
         //scan each character of the equation one by one to check if it is match the condition, if is, push into stack
	     if ( exp[i] == '(' ||  exp[i] == '[' || exp[i] == '<')
		 {
			myStack.push(exp[i]);
		 }
		 //scan each character to check if match the condition, pop from stack and check with each other if is match
		 if ( exp[i] == ')' ||  exp[i] == ']' || exp[i] == '>')
		 {
		    if (myStack.isEmpty())
			{
			   //set mark_1 to 1 to signify that the stack is empty but the equation are invalid and jump out from loop
			   mark_1 = 1;
			   if (exp[i] != ')')
			   {
			      cout << " === missing (" << endl;
				  i = exp.length();
			   }
			   if (exp[i] != ']')
			   {
			      cout << " === missing [" << endl;
				  i = exp.length();
			   }
			   if (exp[i] != '>')
			   {
			      cout << " === missing <<" << endl;
				  i = exp.length();
			   }
			}
   			else
			{
			   //pop from stack and check, if the equation are invalid, show the error, jump out from loop and set mark_1 and mark_2 to 1
			   char check = myStack.pop();			   
			   if (check == '(')
			   {
			      if (exp[i] != ')')
			      {
			         cout << " === missing )" << endl;
				     i = exp.length();
				     mark_1 = 1;
				     mark_2 = 1;
				  }
			   }
			   if (check == '[')
			   { 
			      if (exp[i] != ']')
	              {
	                 cout << " === missing ]" << endl;
				     i = exp.length();
				     mark_1 = 1;
				     mark_2 = 1;
				  }
			   }
			   if (check == '<')
			   {
			      if (exp[i] != '>')
			      {
			         cout << " === missing >>" << endl;
				     i = exp.length();
				     mark_1 = 1; 
				     mark_2 = 1;
				  }
			   }
			}
   		 }
   		 
      }
      //if stack is not empty but out from loop with mark_2 does not change, means there are some closing missing at the end of the equation, pop from stack and check  
      if (!myStack.isEmpty() && mark_2 == 0)
      {
      	char checkagain = myStack.pop();
      	if (checkagain == '(')
		{
		   cout << " === missing )" << endl;
		}
		if (checkagain == '[')
		{ 
		   cout << " === missing ]" << endl;
		}
		if (checkagain == '<')
		{
		   cout << " === missing >>" << endl;
		}
      }
      //if stack is empty and the mark_1 does not change, means the equation is valid
      else if (mark_1 == 0)
      {
      	 cout << " === valid expression" << endl;
      }
         
      
   }
   inFile.close();
  
}



