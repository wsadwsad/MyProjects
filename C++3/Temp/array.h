#ifndef ARRAY_H
#define ARRAY_H

using namespace std;

const int maxsize = 2000;

class ar
{
 private:
   int array[maxsize][maxsize];
 public:
   	ar( );
   	void set(int row, int col);
   	int get(int row, int col);
};

#endif
