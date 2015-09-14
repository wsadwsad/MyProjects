#********************************************************************
#
#  Author:            <Your name>
#
#  Program #:         8
#
#  File Name:         Program8.py
#
#  Course:            COSC 1336 Programming Fundamentals I 
#
#  Due Date:          <Due Date>
#
#  Instructor:        Fred Kumi 
#
#  Chapter:           <Chapter #>
#
#  Maximum points:    <>
#
#  Description:
#     This program reads and displays the contents
#     of a file.
#********************************************************************
def main():
    
    inFile = open('program8.txt', 'r')
    
    lineRead = inFile.readline()       # Read first record
    while lineRead != '':              # While there are more records
       words = lineRead.split()        # Split the records into substrings
       annualRainfall = float(words[0])
       print(format(annualRainfall, '.2f'))
       
       lineRead = inFile.readline()    # Read next record
       
    # Close the file.
    inFile.close() # Close file
    
# Call the main function.
main()
