#include <iostream>
#include <algorithm> 
void printout(int array[],int a ,int b);
int qsort(int begin, int j, int a[]);

using namespace std;

const int size = 22;

int main()
{
	
	int array[size] = {55,55,25,36,4,15,84,12,41,54,14,98,11,51,95,654,25,478,54,147,2,3};
	
	printout(array,0, size-1);
	
	qsort(0, size-1, array);
	
	printout(array,0,size-1);
	
	return 0;
}

void printout(int array[], int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}

int qsort(int begin, int s, int a[])
{
	printout(a, begin,s);
	int i = begin+1;
	int j = s;
	int p = begin;
	
	if(i == j)
	{
		if(a[p] > a[j])
		{
			swap(a[p], a[j]);
		}
	}
	else
	{
		while(i < j)
		{
			while(a[i] < a[p] && i < j)
			{
				i++;
			}
			while(a[j] > a[p] && j > i)
			{
				j--;
			}
			if(i != j)
			{
				swap(a[i],a[j]);
			}			
		}
		if(a[p] > a[i])
		{
			swap(a[p], a[i]);
			j++;
		}
		else
		{
			if(p != j-1)
			{
				swap(a[p], a[j-1]);
			}
		}
		if(p < j-2)
		{
			qsort(p,j-2,a);
		}
		if(i <= s-1)
		{
		    qsort(i,s,a);
		}
		
	}
	
}

