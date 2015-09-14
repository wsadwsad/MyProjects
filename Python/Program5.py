#********************************************************************
#
#  Author:            Jie Zhou
#
#  Program #:         Program #5
#
#  File Name:         Program5.py
#
#  Course:            COSC 1336 Programming Fundamentals I 
#
#  Due Date:          2/18/2014
#
#  Instructor:        Fred Kumi 
#
#  Chapter:           Chapter #5
#
#  Maximum points:    20
#
#  Description:
#     An explanation of what the program is designed to do
#
#********************************************************************

def main():
    ID=int(input('Your ID number: '))
    rate=float(input('Hourly rate: '))
    hours=int(input('How many hours: '))
    over=0
    
    if hours>=40:
        over=hours-40
    rhours=hours-over

    rpay=rate*rhours
    opay=rate*1.5*over
    gross=rpay+opay
    gpay=0
    
    if gross>=500:
        gpay=gross*0.15

    ded=gpay+20
    npay=gross-ded

    print("ID Number:     ",ID)
    print("Pay Rate:       $",format(rate,',.2f'),sep='')
    print("Regular Hours: ",rhours)
    print("Overtime Hours:",over)
    print("Total Hours:   ",hours)
    print("Regular Pay:    $",format(rpay,',.2f'),sep='')
    print("Overtime Pay:   $",format(opay,',.2f'),sep='')
    print("Gross Pay:      $",format(gross,',.2f'),sep='')
    print("Deductions:     $",format(ded,',.2f'),sep='')
    print("Net Pay:        $",format(npay,',.2f'),sep='')

    again=0
    y=1
    again=input("again: ")
    if again==1:
        return main()
    else:
        print()
        


def userInfo():
    print('Name:     Jie Zhou')
    print('Course:   Programming Fundamentals I')
    print('Program:  Five')
    print()
    # End of userInfo



userInfo()
main()



# End of Pragram 5
