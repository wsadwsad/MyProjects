/*This class counts number of collisions 
  row and col are the index of the files that we are comparing */

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int maxsize = 2000;

struct data1
{
	int collision;
	int row;
	int col;
};

class Array
{
 private:
   int array[maxsize][maxsize];
   data1 data[maxsize];
   int size;
 public:
   	Array( );
   	void set(int row, int col);
   	int get(int row, int col);
   	void collect(vector<string> &files, int collisions);
   	void sortprint(vector<string> &files);
};

#endif
