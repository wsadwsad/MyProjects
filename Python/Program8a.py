#********************************************************************
#
#  Author:            Jie Zhou
#
#  Program #:         8
#
#  File Name:         Program8.py
#
#  Course:            COSC 1336 Programming Fundamentals I 
#
#  Due Date:          4/08/2014
#
#  Instructor:        Fred Kumi 
#
#  Chapter:           Chapter 8
#
#  Maximum points:    40
#
#  Description:
#     This program reads and displays the contents
#     of a file.
#********************************************************************

months=['January','February','March','April','May','Jun','July',\
           'August','September','October','November','December']



def main():
    
    inFile = open('program8.txt', 'r')

    outFile= open('program8-out.txt','a')

    totalr=0
    a=0
    data=[]
    
    lineRead = inFile.readline()       # Read first record
    while lineRead != '':              # While there are more records
       words = lineRead.split()        # Split the records into substrings
       annualRainfall = float(words[0])
       
       
       month=months[a]

       print('{:<13}'.format(month),format(annualRainfall, '.2f'))

       outFile.write(str(annualRainfall) + '\n')

       lineRead = inFile.readline()    # Read next record

       data.append(annualRainfall)
       a+=1

       totalr+=annualRainfall

    Max=months[data.index(max(data))]
    Min=months[data.index(min(data))]

    a=aver(totalr,data)

    print('Total rainfall for the year was',format(totalr,'.2f'),'inches')
    print('Average rainfall for the year was',a,'inches')
    print('The largest amount of rainfall was',max(data),'inches in the',\
          'month of',Max)
    print('The smallest maount of rainfall was',min(data),'inches in the',\
          'month of',Min)

    outFile.write(str(format(totalr,'.2f')) + '\n')
    outFile.write(str(aver) + '\n')
    outFile.write(str(max(data)) + '\n')
    outFile.write(str(min(data)) + '\n')
    
    # Close the file.
    inFile.close() # Close file
    outFile.close()
# Call the main function.

def aver(totalr,data):
   averager=totalr/len(data)
   return format(averager,'.2f')
    
main()
