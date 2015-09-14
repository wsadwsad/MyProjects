#include <iostream>
#include <bitset>
using namespace std;
 
char printChar ()
{
    char Char;
     
    cout << "\nEnter a character: ";
    cin>>Char;
    cout << " \n"; 
    cout << "The binary representation for " << Char<<" is: ";

    int inputc = Char;
    
	for (int i=7; i>=0; i--) 
        {
            int n = ((inputc >> i) & 1);
            if((i + 1) % 4 == 0)
			{
			cout<<" ";
			}  
            cout << n;
        }
        cout << endl;
}     
 
int printShort () 
{
    int number;
    cout<<"\nEnter a short: ";
    cin >> number;
    cout << " \n";
    cout << "The binary representation for " << number << " is: ";
        for (int i=15; i>=0; i--) 
        {
            int n = ((number >> i) & 1);
            if((i + 1) % 4 == 0)
			{
				cout<<" ";
			}  
            cout << n;
        }
        cout << endl;
}
 
float printFloat ()
{
    float number;
    cout<<"\nEnter a float: ";
    cin>>number;
    cout << " \n";
	cout << "The binary representation for " << number << " is: "; 
	
	int* n=reinterpret_cast<int*>(&number);
	for(int a=31;a>=0;a--)
	{
		int f = ((*n >> a) & 1);
		if((a + 1) % 4 == 0)
		{
			cout<<" ";
		}
		cout << f;
	}
	cout << endl;
	
}
