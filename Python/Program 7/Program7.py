#********************************************************************
#
#  Author:            Jie Zhou
#
#  Program #:         7
#
#  File Name:         Program7.py
#
#  Course:            COSC 1336 Programming Fundamentals I 
#
#  Due Date:          3/25/2014
#
#  Instructor:        Fred Kumi 
#
#  Chapter:           7
#
#  Maximum points:    28
#
#  Description:
#     This program reads and displays the contents
#     of a file.
#********************************************************************
def main():
    
    inFile = open('program7.txt', 'r')
    cout = 0
    totaloldpay = 0
    totalrais = 0
    totalpay = 0
    lineRead = inFile.readline()
    while lineRead != '':
       
       words = lineRead.split() 
       for word in words:
           num = float(word)
           cout += 1
           if num > 60000:
                rais = num * 0.04
                pay = num + rais

           elif num > 50000:
                rais = num * 0.07
                pay = num + rais
 
           else:
               rais = num * 0.055
               pay = num + rais

           totaloldpay += num
           totalrais += rais
           totalpay += pay
           
           
           print("Faculty number:",cout)
           print("Old Salary:    $",format(num,'.2f'),sep='')
           print("Raise:         $",format(rais,'.2f'),sep='')
           print("New Salary:    $",format(pay,'.2f'),sep='')
           print()
            
       lineRead = inFile.readline()

    averageoldpay = totaloldpay/cout
    averagerais = totalrais/cout
    averagepay = totalpay/cout

    print("Sum of Old Salaries:     $",format(totaloldpay,'.2f'),sep='')
    print("Sum of New Salaries:     $",format(totalpay,'.2f'),sep='')
    print("Average of Raises:       $",format(averagerais,'.2f'),sep='')
    print("Average of Old Salaries: $",format(averageoldpay,'.2f'),sep='')
    print("Average of New Salaries: $",format(averagepay,'.2f'),sep='')
          
       
    # Close the file.
    inFile.close()

def userInfo():
    print('Name:     Jie Zhou')
    print('Course:   Programming Fundamentals I')
    print('Program:  Seven')
    print()
    # End of userInfo

userInfo()    
# Call the main function.
main()
