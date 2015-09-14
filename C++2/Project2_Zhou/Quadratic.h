#ifndef QUADRATIC_H
#define QUADRATIC_H
#include <iostream>
#include <cmath>
using namespace std;

class Quadratic
{
	private:
		float a,b,c;

	public:
		//constructor
		Quadratic();
		
		void display();
		
		//Set the value to a, b, c
		void set(float Numa, float Numb, float Numc);
		
		//return value
		float getA() const;
		float getB() const;
		float getC() const;
		
		//evaluate the function by giving values
		float evaluate(float) const;
		int numRoots();
		float minRoot();
		float maxRoot();
};


Quadratic operator+(const Quadratic &q1, const Quadratic &q2);
Quadratic operator*(double r, const Quadratic &q);

#endif
