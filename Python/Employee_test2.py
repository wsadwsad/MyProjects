#********************************************************************
#
#  Author:            Jie Zhou
#
#  Program #:         Program 10
#
#  File Name:         ZhouJ10.py
#
#  Course:            COSC 1336 Programming Fundamentals I 
#
#  Due Date:          5/06/2014
#
#  Instructor:        Fred Kumi 
#
#  Chapter:           Chapter 10
#
#  Maximum points:    40
#
#  Description:
#     Classes
#
#********************************************************************

import ZhouJ10_2

def Again():
    again = "yes"
    while again =="yes":
        main()
        print()
        again = input("Do you want to run the program again <yes/no>?")

def main():

    name = input("Enter your name (First Last): ")
    temprate = float(input("Enter your hourly rate: "))
    print()

    h1 = 0
    h2 = 0
    oh = 0
    for a in range(1,5):
        hours = int(input("Enter hours worked for week"+str(a)+": "))
        if hours > 40:
            oh += hours - 40
            h1 += 40
        else:
            h2 += hours
    regularhour = h1 + h2
    overhour = oh

    test = ZhouJ10_2.Employee(name,temprate,regularhour,overhour)
    rate = test.Rate(temprate)

    test.set_total_hour()
    test.set_regular_pay(rate)
    test.set_overtime_pay(rate)
    test.set_total_pay()
    test.set_tax()
    test.set_net_pay()

    print()
    print()
    print('{:<19}'.format("Employee`s name:"),\
          '{:>10}'.format(test.get_name()))
    print()
    print('{:<19}'.format("regular hours:"),\
          '{:>10}'.format(format(test.get_regular_hour(),'.2f')))
    print('{:<19}'.format("Overtime hours:"),\
          '{:>10}'.format(format(test.get_overtime_hour(),'.2f')))
    print('{:<19}'.format("Total hours:"),\
          '{:>10}'.format(format(test.get_total_hour(),'.2f')))
    print()
    print('{:<19}'.format("Pay rate:"),\
          '{:>10}'.format(format(rate,'.2f')))
    print()
    print('{:<19}'.format("Regular pay:"),\
          '{:>10}'.format(format(test.get_regular_pay(),'.2f')))
    print('{:<19}'.format("Overtime amount:"),\
          '{:>10}'.format(format(test.get_overtime_pay(),'.2f')))
    print('{:<19}'.format("Monthly gross pay:"),\
          '{:>10}'.format(format(test.get_total_pay(),'.2f')))
    print('{:<19}'.format("Taxes:"),\
          '{:>10}'.format(format(test.get_tax(),'.2f')))
    print('{:<19}'.format("Monthly net pay:"),\
          '{:>10}'.format(format(test.get_net_pay(),'.2f')))
    print()

Again()
