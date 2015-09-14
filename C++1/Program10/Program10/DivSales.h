#ifndef DIVSALES_H
#define DIVSALES_H
#include <iostream>

const int num = 4;

class DivSales
{private:
	static double totalsale;
	double qsale;
public:
	DivSales()
	{
		qsale = 0;
	};
	
	double sale[num];
	
	void holddata(double a,int n)
	{
		sale[n] = a;
	};

	void addqsale(double d)
	{
		qsale += d;
	};
	
	double getvalue(int b)
	{
		return sale[b];
	};
	
	void addtotal(double d)
	{
		totalsale += d;
	}
	
	double gettotal()
	{
		return totalsale; 
	}

};
#endif