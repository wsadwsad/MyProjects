/* stats.h

Written by Roger Priebe and Jie Zhou
1/27/15

This class will provide some simple statistics functions.

//USE THIS FILE FOR DOCUMENTATION (INCLUDING PRE and POST CONDITIONS)

*/

#ifndef STATS_H
#define STATS_H

using namespace std;


class Stats {
    
   static const int MAX_SIZE = 10000;
   private:     
      int numVars;
      double vars[MAX_SIZE];
      float averagevar,		//to store the value of the average
            highestvar,		//to store the value of the highest
            lowestvar,		//to store the value of the lowest
			stddeviation;	//to store the value of the standard diviation
   public:     
      Stats();
      
      void clearData() {
         numVars = 0;
      }
      
      
      //This function adds one variable to the array in the class.
      //The function returns false if the variable is not successfully added to the class.
      //pre: numVars < MAX_SIZE
      //post: numVars = numvars + 1 and var has been added to the class   
      bool addVar(double var);
      
      //This function show all the data
      //pre: None
      //post: None
      void showData();
      
      //This function calculate the average of data
      //pre: None
      //post: averagevar = the average of data
      double getAverage();
      
      //This function get the highest number of data
      //pre: None
      //post: highestvar = the highest number  
      double findHighest();
      
      //This function get the lowest number of data
      //pre: None
      //post: lowestvar = the lowest number
      double findLowest();
      
      //This function calculate and get the standard deviation of data
      //pre: None
      //post: stddeviation = the standard deviation
      double calcStdDeviation();
      
      //This function returns the size of array
      //pre: None
      //post: return the number of the size 
      int getNumVars() {
         return numVars;
      }
      
      //This function returns the capacity of array
      //pre: None
      //post: return the number of the capacity
      static int getMaxSize() {
         return MAX_SIZE;
      }
      
};

#endif
