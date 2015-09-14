
#include "stats.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

int main(int argc, char * argv[])
{
   Stats s;
   string str;
   int temp1;	  //a temp variable to get the year data
   float temp2;		//a temp variable to get the month data
   float temp3;		//a temp variable to get the CO2 level data

   cout << argv[0] << " - " << argv[1] << endl;
    
   ifstream inFile;
   inFile.open(argv[1]);
   
   do 
   {
       inFile >> str;
   }while (str != "MLO");	//To throw away the text we don't need 

   do 
   {
       inFile >> temp1;
       inFile >> temp2;
       inFile >> temp3;
       str = " ";
       inFile >> str;
	   s.addVar(temp3);
   }while (str == "MLO");    //To read the text we need till there is nothing.
   
   s.showData();	//show the data
   s.clearData();	//clear the data
   
   inFile.close();
   return 0;
}

