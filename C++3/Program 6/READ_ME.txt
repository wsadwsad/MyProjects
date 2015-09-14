This program is written by Firdaus Botirzoda and Jie Zhou

		What it does
Plagarism Checker
This program does what the name suggests, which is checks for plagarism, by comparing 
multiples of text documents. 


			How it Works
First, user has to input the path to the text files, size of the chunks, and a criteria for
how many collision(similarities in number of chunks to compare) is desired. 
The way it works is, all of the text files are broken up into chunks and then all of the 
chunks have special characters taken out as well as letters are capitalized. 
Afterwards, we calculate the ASCII value of each letter and we store it in the 
variable "key". We calculate our hash by taking key%CAPACITY, and that outputed value becomes 
our index for the hash table. That's how we figure out where to put each chunk. 
Each text document can use one hash index only once, since we don't want to compare the 
document with itself. 
After all of the documents are organized in the hash table, we go through it and fin collisions 
by traversing through each hash index, and the number of collisions is stored to a 2D
array, where row = 1st document, column = 2nd document of the collision that has occured. 
Afterwards we sort it from highest to the lowest, then print it out.
Files at index row and col from our 2D array helped us to print out which two files we found
the collisions in. 

			How to use it
At the Linux command line, first type "make" and hit enter.
Then type the name of the executable file, "./plagiarismCatcher"
Then followed by the directory, for example "sm_doc_set"
Then followed by chunk size, for example "6" 
Then followed by number of collisions, for example "200" and hit enter.
 
So the final input should look similar to this format:
"./plagiarismCatcher sm_doc_set 6 200"

		What works, What doesn't
Maximum documents this program can proccess is 2,000 text files.
Each document doesn't have a size restriction. 
We run the program with the " big_doc_set ", it takes 35 seconds.

		Does it have any bugs?
So far, we have not found any bugs and the program runs successfully

		Name of files
array.cpp, array.h, hash.cpp, hash.h, list.h, queue.h, test.cpp
