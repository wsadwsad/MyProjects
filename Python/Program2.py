#********************************************************************
#
#  Author:            Jie Zhou
#
#  Program #:         Program 2
#
#  File Name:         Program2.py
#
#  Course:            COSC 1336 Programming Fundamentals I 
#
#  Due Date:          2/4/2014
#
#  Instructor:        Fred Kumi 
#
#  Chapter:           Chapter 2
#
#  Maximum points:    20
#
#  Description:
#     An explanation of what the program is designed to do
#
#********************************************************************

def main():
    propertyValue = float(input('Enter the assessed value of the property: '))
    taxRate = float(input('Enter the current tax rate: '))
    Value=propertyValue*0.6
    currentTaxRate=taxRate/100
    tax=Value*currentTaxRate
    print('The tax is',format(tax,',.2f'))


    # End of main

def userInfo():
    print('Name:     Jie Zhou')
    print('Course:   Programming Fundamentals I')
    print('Program:  One')
    print()
    # End of userInfo

userInfo()
main()

# End of Pragram 1
