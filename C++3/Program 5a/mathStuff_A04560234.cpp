/* mathStuff_A04560234.cpp

Roger Priebe and Jie Zhou
cs3358 3/25/2015

Finish comments here
*/

#include <iostream>
#include <fstream>

using namespace std;

//**********  Function Prototypes  ******************

//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number);

//helper function checkPrime
//input parameters - positive integers
//return true if the divisor equal to the number, otherwise keep calling the function by increase divisor by 1
//or reture false if the number is divisble by the divisor

bool checkPrime(int number, int divisor);



//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n. 

void printPrimes (int n);


//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0 
//Fib(1) -> 1 
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n);


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number);

//Helper function getFactors
//input parameter - positive integers
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void getFactors(int number, int divisor);


//******************  MAIN  *****************************

int main () {
    
    
    int testNum;
    
    //test for the isPrime function
    cout << "Enter a test number - ";
    cin >> testNum;
    cout << endl;
    
    if (isPrime(testNum ))  
       cout << testNum << " is prime." << endl;
    else
       cout << testNum << " is not prime." << endl;
    
    //test for printing primes
    cout << "\nEnter n to print the prime numbers between 1 and n: ";
    cin >> testNum;
    
    
    printPrimes(testNum);
    
    cout << endl;
    //test for Fibonacci number finder
    cout << "\nWhich Fibonacci number? ";
    cin >> testNum;
    cout << endl;
    
    cout << "The " << testNum << " Fibonacci number is : " << findFibo(testNum) << endl;
    
    cout << endl;
    //test for prime factors
    cout << "Factor what number: ";
    cin >> testNum;
    cout << endl;
    
    findFactors(testNum);
    
    
    return 0;
}




//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number) 
{
   const int START_DIVISOR = 2; 
   if (number <= 1)
   {
   	  return false;
   }
   return checkPrime(number, START_DIVISOR);
}

//helper function checkPrime
//input parameters - positive integers
//return true if the divisor equal to the number, otherwise keep calling the function by increase divisor by 1
//or reture false if the number is divisble by the divisor
bool checkPrime(int number, int divisor)
{
	if (divisor == number)
	{
		return true;
	}
	else
	{
		if(number % divisor != 0)
		{
			checkPrime(number, divisor + 1);
		}
		else
		{
			return false;
		}
	}
}

//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n. 

void printPrimes (int n) 
{
   if(n < 1)
   {
   	   cout <<"\ninvalid number.." << endl;
   }
   else if(n == 1)
   {
   	   cout << "\n";
   }
   else
   {
   	   if(isPrime(n))
   	   {
   	   	   
   	   	   printPrimes(n - 1);
		   cout << n << " ";
   	   }
   	   else
   	   {
   	   	   printPrimes(n - 1);
   	   }
   }

} 



//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0 
//Fib(1) -> 1 
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n) 
{
	if (n < 0)
	{
		cerr << "Invalid input.." << endl;
		return -1;
	}
	if (n == 0)
    {
      	return 0;
    }
    if (n == 1)
    {
    	return 1;
    }
    else
    {
    	return (findFibo(n-1) + findFibo(n-2));
    }
    
}


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number) 
{
    const int START_DIVISOR = 2; //HINT: You may want a helper function
	if (number < 1)
	{
		cout << "Invalid input.." << endl;
	}
	else if (number == 1)
	{
		cout << number << " = 1" << endl;
	}
    else
    {
        cout << number << "=";
        if(isPrime(number))
        {
     	   cout << "prime" << endl;
        }
        else
        {
     	   getFactors(number, START_DIVISOR);
        }
    }

}

//Helper function getFactors
//input parameter - positive integers
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime
void getFactors(int number, int divisor)
{
	if(divisor <= number)
	{
		if(number%divisor ==0)
		{
			if(number/divisor == 1)
			{
			   cout << divisor;
		    }
			else
			   cout << divisor << "*";
			   
			getFactors(number/divisor, divisor);
		}
		else
		{
			getFactors(number, divisor+1);
		}
	}
}
 
