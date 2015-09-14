#***************************************************************
#
#  Author:            Leo Li
#
#  Program #:         Assignment Seven
#
#  File Name:         Program7.py
#
#  Course:            COSC 1336 Programming Fundamentals I 
#
#  Due Date:          Oct 28 2014
#
#  Instructor:        Fred Kumi 
#
#  Chapter:           Chapter 7
#
#  Course synonom:    15836
#
#  Description:
#     Used to read file and calculate raise
#
#***************************************************************

#***************************************************************
#
#  Function:     main
# 
#  Description:  The main function of the program
#
#  Parameters:   None
#
#  Returns:      Nothing 
#
#**************************************************************
def main():
    print ()
    file = open('program7.txt', 'r')
    num = file.readline()
    Total = 0
    Average = 0
    before = 0
    after = 0
    counter = 0
    while num != '':
        single = num.split()
        for number in single:
            number = float(number)
            if number > 60000:
                Raise = number * 0.04
                new = number + Raise
            elif number > 50000:
                Raise = number * 0.07
                new = number + Raise
            else:
                Raise = number * 0.055
                new = number + Raise
            Total += Raise
            counter += 1
            before += number
            after += new
            

            print('salary:\t\t$',format(number, ',.2f'),sep='')
            print('Increase by:\t$',format(Raise, ',.2f'),sep='')
            print('New salary:\t$',format(new, ',.2f'),sep='')
            print()
        num = file.readline()
    file.close()
    
    Average = Total / counter
    print('Total Raise:\t\t$',format(Total, ',.2f'),sep='')
    print('Average Raise:\t\t$',format(Average, ',.2f'),sep='')
    print('Total Payroll before:\t$',format(before, ',.2f'),sep='')
    print('Total Payroll after:\t$',format(after, ',.2f'),sep='')
        
    # End of main
    
#***************************************************************
#
#  Function:     userInfo
# 
#  Description:  Prints Programmer's information
#
#  Parameters:   None
#
#  Returns:      Nothing 
#
#**************************************************************
def userInfo():
    print('Name:     Leo Li')
    print('Course:   Programming Fundamentals I')
    print('Program:  Seven')
    print()
    # End of userInfo


# Call functions
userInfo()
main()

# End of Pragram 1
