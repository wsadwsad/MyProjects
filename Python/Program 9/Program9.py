#********************************************************************
#
#  Author:            <Your name>
#
#  Program #:         9
#
#  File Name:         Program9.py
#
#  Course:            COSC 1336 Programming Fundamentals I 
#
#  Due Date:          <Due Date>
#
#  Instructor:        Fred Kumi 
#
#  Chapter:           <Chapter #>
#
#  Maximum points:    < >
#
#  Description:
#     This program reads and displays the contents
#     of a file.
#********************************************************************
def main():
    
    inFile = open('program9.txt', 'r')
    
    lineRead = inFile.readline()       # Read first record
    while lineRead != '':              # While there are more records
       words = lineRead.split()        # Split the records into substrings
       acctNum = int(words[0])         # Convert first substring to integer
       annualIncome = float(words[1])  # Convert second substring to float
       members = int(words[2])         # Convert third substring to integer
       print(acctNum, format(annualIncome, '.2f'), members, sep=' ')
       
       lineRead = inFile.readline()    # Read next record
       
    # Close the file.
    inFile.close() # Close file
    
# Call the main function.
main()
