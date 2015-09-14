#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

#include "stats.h"

Stats::Stats()
{
	averagevar = highestvar = stddeviation = 0;
	lowestvar = 10000;
}

bool Stats::addVar(double var)
{
	if (numVars >= MAX_SIZE)
	{
		return false;
	}
	else
	{
		vars[numVars] = var;
		numVars++;
		return true;
	}
}

double Stats::getAverage()
{
	if (numVars == 0)
	{
		cout << "empty data";
	}
	else
	{
	    int total = 0;
	    for(int i = 0; i < numVars; i++)
	    {
		    total += vars[i];
	    }
	    averagevar = total / numVars;
    }
}

double Stats::findHighest()
{
	for(int i = 0; i < numVars; i++)
	{
		if (vars[i] > highestvar)
		{
			highestvar = vars[i];
		}
	}
}

double Stats::findLowest()
{
	for(int i = 0; i < numVars; i++)
	{
		if (vars[i] < lowestvar)
		{
			lowestvar = vars[i];
		}
	}
}

double Stats::calcStdDeviation()
{
	float total = 0;
	for(int i = 0; i < numVars; i++)
	{
		total += (vars[i] - averagevar)*(vars[i] - averagevar);
	}
	
	stddeviation = sqrt(total / numVars);
}

void Stats::showData()
{
	findHighest();
	findLowest();
	getAverage();
	calcStdDeviation();
	cout << "The highest CO2 level is:  " << highestvar << endl;
	cout << "The lowest CO2 level is:   " << lowestvar << endl;
	cout << "The average CO2 level is:  " << averagevar << endl;
	cout << "The standard deviation is: " << stddeviation << endl;
}
