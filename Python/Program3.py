#********************************************************************
#
#  Author:            Jie Zhou
#
#  Program #:         Program #3
#
#  File Name:         Program3.py
#
#  Course:            COSC 1336 Programming Fundamentals I 
#
#  Due Date:          2/11/2014
#
#  Instructor:        Fred Kumi 
#
#  Chapter:           Chapter #3
#
#  Maximum points:    20
#
#  Description:
#     An explanation of what the program is designed to do
#
#********************************************************************

import math

def main():
    aValue = float(input('Enter side A of the triangle: '))
    bValue = float(input('Enter side B of the triangle: '))
    cValue = math.sqrt(aValue**2 + bValue**2)
    print('Side C of the triangle is ', format(cValue, '.2f'))

    # End of main
    
def userInfo():
    print('Name:     Jie Zhou')
    print('Course:   Programming Fundamentals I')
    print('Program:  One')
    print()
    # End of userInfo

userInfo()
main()

# End of Pragram 3
