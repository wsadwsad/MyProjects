#include <iostream>
#include <cmath>
using namespace std;

#include "Quadratic.h"

Quadratic::Quadratic()
{
	a = b = c = 0;
}

void Quadratic::set(float Numa, float Numb, float Numc)
{
	a = Numa;
	b = Numb;
	c = Numc;
}

void Quadratic::display()
{
	cout << a << "(x^2) + " << b << "(x) + " << c << endl;
}

float Quadratic::evaluate(float x) const
{
	return a*(x*x) + b*x + c;
}

float Quadratic::getA() const
{
	return a;
}

float Quadratic::getB() const
{
	return b;
}

float Quadratic::getC() const
{
	return c;
}

int Quadratic::numRoots()
{
	int numR = -999;
	
	if (a == 0 && b == 0 && c == 0)
	{
		numR = 3;
	}
	else if ((a ==0 && b == 0 &&  (c != 0)) || ((a != 0) && ((b*b) < (4*a*c))))
	{
		numR = 0;
	}
	else if ((a == 0) && (b != 0))
	{
		numR = 1;
	}
	else if ((a != 0) && ((b*b) == (4*a*c)))
	{
		numR = 1;
	}
	else if ((a != 0) && ((b*b) > (4*a*c)))
	{
		numR = 2;
	}
	else
	{
		numR = -2;
	};
	
	return numR;
}

float Quadratic::maxRoot()
{
	float Mx = -999;
	if (a == 0 && b == 0 && c == 0)
	{
		Mx = 0;
	}
	else if ((a == 0) && (b != 0))
	{
		Mx = -c/b;
	}
	else if ((a != 0) && ((b*b) == (4*a*c)))
	{
		Mx = -b/(2*a);
	}
	else if ((a > 0) && ((b*b) > (4*a*c)))
	{
		Mx = (-b + sqrt((b*b)-(4*a*c)))/(2*a);
	}
	else if ((a < 0) && ((b*b) > (4*a*c)))
	{
		Mx = (-b - sqrt((b*b)-(4*a*c)))/(2*a);
	}
	else
	{
		cout << "No real roots." << endl;
	};
	return Mx;
}

float Quadratic::minRoot()
{
	float Mn = -999;
	if (a == 0 && b == 0 && c == 0)
	{
		Mn = 0;
	}
	else if ((a == 0) && (b != 0))
	{
		Mn = -c/b;
	}
	else if ((a != 0) && ((b*b) == (4*a*c)))
	{
		Mn = -b/(2*a);
	}
	else if ((a < 0) && ((b*b) > (4*a*c)))
	{
		Mn = (-b + sqrt((b*b)-(4*a*c)))/(2*a);
	}
	else if ((a > 0) && ((b*b) > (4*a*c)))
	{
		Mn = (-b - sqrt((b*b)-(4*a*c)))/(2*a);
	}
	else
	{
		cout << "No real roots." << endl;
	};
	return Mn;
}


Quadratic operator+ (const Quadratic &q1, const Quadratic &q2)
{
	Quadratic q3;
	q3.set(q1.getA() + q2.getA(), q1.getB() + q2.getB(), q1.getC() +q2.getC());
	return q3;
}

Quadratic operator* (double r, const Quadratic &q)
{
	Quadratic tempq;
	tempq.set(r * q.getA(), r * q.getB(), r * q.getC());
	return tempq;
}
