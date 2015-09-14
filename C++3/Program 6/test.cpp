/*by: Firdaus Botirzoda and Jie Zhou*/

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <cctype>
#include <iomanip>

#include "queue.h"
#include "hash.h"


using namespace std;

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(dirp->d_name);
    }
    closedir(dp);
    return 0;
    
    
}

int main(int argc, char * argv[])
{
    string dir = string(argv[1]); //get parameter from command line
    
    vector<string> files = vector<string>();
    Queue<string> queue;//create a queue for using it as a chunk
    
    ifstream infile;
//	ofstream fout;
	
//	fout.open("output.txt");//create a txt file for output 

    getdir(dir,files);
    
	Table htable;
	RecordType rec;
	
	string str;               //create several strings for holding data from files
    string allline;
	string strword = "";
	
	int chunksize = atoi(argv[2]);
	int collisions = atoi(argv[3]);
	
//	fout << "n = " << chunksize << "\n\n";//output the n to a txt file
		
    htable.set(files, collisions);
        
    for (unsigned int i = 2;i < files.size();i++)       
	{
	   cout << i-2 << ". " << files[i] << endl;	  
    }
    
	int k = files.size();
	
	cout << "\nProcessing..." << endl;
	cout << "(The system does not crash, it just need a few minutes, please be patient!)" << endl; 

	if( files.size() > 200)
	{ 	   
	   cout << "0%" << setw(40) << "100%" << endl;
	   cout <<"|";
	   k = files.size() / 40;
	}
	
	for (unsigned int i = 2;i < files.size();i++)
	{	
	   
//	   fout << files[i] << "\n\n";//output the name of each file to a txt file
	   string name = argv[1];//get the folder name from the command line
	   name +='/';
	   name += files[i];//get file name from vector
       infile.open(name.c_str());  
	   
       for (int j = 0; j < chunksize; j++)
       {
          infile >> str;//get data from files
          for(int t =0; t < str.length(); t++)
		  {
		     if (isalnum(str[t]))//chech each character
		     {			 		     	
		     	str[t] = toupper(str[t]);//convert each character to uppercase
                strword+=str[t];//put all characters into a new string
             }          
		  }   		       
          queue.push(strword);//push the new string with only uppercase letters and numbers into queue
          strword = "";//empty string for next using
	   }
	   
       while (str != "")       
       {  
          allline = queue.getall();//get all data from queue and store it into another string
//		  fout << allline << "\n";//output to a txt file

		  int number = 0;
		  for (int l = 0; l < allline.size(); l++)
		  {
		      number += (int)allline[l];
		  }
		  rec.key = number;
		  rec.data = i;
		  rec.leng = allline.size();
		  rec.first = allline[0];
		  htable.insert(rec);
		  
		  str = "";
		  infile >> str;//get another word from file
		  for(int t =0; t < str.length(); t++)// do the same thing as before
		  {
		     if (isalnum(str[t]))
		     {
		     	str[t] = toupper(str[t]);
                strword+=str[t];
             }         
          }          
          queue.push(strword);//push it to queue
          strword = "";//empty string for next using
          queue.pop();//pop the first word which pushed before to keep the chunk on same size
	   }
	   queue.makeEmpty();
//	   fout << "\n";//output to a txt file
       infile.close();
       
	   if( i % k == 0)
       { 
       	  cout <<"|";      	  
       }

    }
    cout << "\n";
    htable.printa();
//	fout.close();//output file close
    
	return 0;
}

   
