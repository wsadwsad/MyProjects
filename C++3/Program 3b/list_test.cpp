//list_test.cpp
//CS3358_Roger Priebe, Jie Zhou
//tests a very simple cursor based list ADT

#include <iostream>
#include "list_3358_pointers.h"

using namespace std;

void showList(List &myList);
bool search (List & myList, List::value_type target);

int main () {
   List myList;
   cout << "Insert 42..." <<endl;
   myList.insert(42);
   
   cout << "Insert 52..." <<endl;
   myList.insert(52);
   
   cout << "Insert 12..." <<endl;
   myList.insert(12);
   
   cout << "Insert -42..." <<endl;
   myList.insert(-42);
   
   cout << "Insert 2...\n" <<endl;
   myList.insert(2);
   
   cout <<"Now show the list:" << endl;
   showList(myList);
   
   cout <<"Everytime after showing the list," << endl;
   cout <<"the list will be reseted automatically\n" << endl;
   
   cout << "test copy constructor" << endl;
   List myList2 = myList; //copy constructor
   cout <<"This is list 2: " << endl;
   showList(myList2);
   
   cout <<"\nBack to the first list\nReset list..." << endl;
   myList.reset();
   
   cout <<"The cursor should points to the head..." << endl;
   cout << myList.getCurrent()<< endl;
   
   cout <<"\nAdvance once." << endl;
   cout <<"The cursor should pints to the next one.." << endl;
   myList.advance();
   cout << myList.getCurrent()<< endl;
 
   cout <<"\ntest inserts" << endl;
   cout <<"show the list:" << endl;  
   showList(myList);
   
   cout <<"\nThe cursor point to: " << endl; 
   cout << myList.getCurrent()<< endl;
   cout <<"\nReset..." << endl;
   myList.reset();   
   
   cout << "Insert 88...\n" <<endl;
   myList.insert(88);
   
   cout << "test inserts" << endl; 
   cout <<"show the list: " << endl; 
   showList(myList);
   
   cout << "\ntest advance and if is at the end" << endl;
   myList.reset();
   while(!myList.atEOL())
   {
   	 cout <<"Not at the end" << endl;
   	 cout <<"cursor is pointing to: " << myList.getCurrent() << endl;
   	 cout <<"Moving cursor to the next..." << endl;
   	 myList.advance();
   }
   if(myList.atEOL())
   {
   	 cout <<"At the end of list" << endl;
   }
   myList.reset();
   
   cout << "\ntest search and remove a number from the middle of list" << endl;
   cout << "Searching 12..." << endl;
   if (search(myList,12))
   {
     cout << "The cursor is point to: " << endl;
     cout << myList.getCurrent() << endl;
     cout << "Now remove 12..." << endl;
	 myList.remove();
	 cout << " \ntest remove after search" << endl; 
	 cout <<"show the list: " << endl;  
     showList(myList);
   }
   else
   {
   	 cout << "12 is not in the list" << endl;
   }
   
   cout << "\ntest search and remove a number from the middle of list" << endl;
   cout << "Searching 42..." << endl;
   if (search(myList,42))
   {
     cout << "The cursor is point to: " << endl;
     cout << myList.getCurrent() << endl;
     cout << "Now remove 42..." << endl;
	 myList.remove();
	 cout << " \ntest remove after search" << endl;
	 cout <<"show the list: " << endl;   
     showList(myList);
   }
   else
   {
   	 cout << "42 is not in the list" << endl;
   }
   
   cout << "\ntest search and remove a number from the head of list" << endl;
   cout << "Searching 88..." << endl;
   if (search(myList,88))
   {
     cout << "The cursor is point to: " << endl;
     cout << myList.getCurrent() << endl;
     cout << "Now remove 88..." << endl;
	 myList.remove();
	 cout << " \ntest remove after search" << endl;
	 cout <<"show the list: " << endl;   
     showList(myList);
   }
   else
   {
   	 cout << "88 is not in the list" << endl;
   }
   
   cout << "\ntest search and remove a number from the tail of list" << endl;
   cout << "Searching 2..." << endl;
   if (search(myList,2))
   {
     cout << "The cursor is point to: " << endl;
     cout << myList.getCurrent() << endl;
     cout << "Now remove 2..." << endl;
	 myList.remove();
	 cout << " \ntest remove after search" << endl;
	 cout <<"show the list: " << endl;   
     showList(myList);
   }
   else
   {
   	 cout << "2 is not in the list" << endl;
   }
     
   cout << "\nshow list 2 again to test if list 2 is changed or not" << endl;
   showList(myList2);

}   


//prints list.
//list will be reset after prints
void showList(List  &myList) {

   myList.reset();

   while (!myList.atEOL())
   {
      cout << myList.getCurrent() << endl;
      myList.advance();
   }
   myList.reset();
}

//if found, places the cursor at the target and returns true
//otherwise returns false
bool search (List & myList, List::value_type target) {

   bool found = false;

   myList.reset();

   while (!found && !myList.atEOL())
   {
      if (target == myList.getCurrent())
         found = true;
      else
         myList.advance();
   }
   return found;
    
}
