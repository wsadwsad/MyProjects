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

class Employee:

    def __init__(self):
        self.__rate = 7.25 
        self.__totalhour = 0
        self.__regularpay = 0
        self.__overtimepay = 0
        self.__totalpay = 0
        self.__tax = 0
        self.__netpay = 0
        
    def set_name(self):
        self.__name = input("Enter your name (First Last): ")

    def set_rate(self):
        self.__rate = float(input("Enter your hourly rate: "))
        
    def set_hour(self):
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
        self.__Rhour = h1 + h2
        self.__Ohour = oh

    def set_total_hour(self):
        self.__totalhour = self.__Rhour + self.__Ohour

    def set_regular_pay(self):
        self.__regularpay = self.__Rhour * self.__rate

    def set_overtime_pay(self):
        self.__overtimepay = self.__Ohour*(self.__rate*1.5)

    def set_total_pay(self):
        self.__totalpay = self.__regularpay + self.__overtimepay

    def set_tax(self):
        if self.__totalpay > 10000:
            self.__tax = self.__totalpay*0.36
        elif self.__totalpay > 6000:
            self.__tax = self.__totalpay*0.31
        elif self.__totalpay > 3500:
            self.__tax = self.__totalpay*0.28
        elif self.__totalpay > 2000:
            self.__tax = self.__totalpay*0.15
        else:
            self.__tax = self.__totalpay*0.1

    def set_net_pay(self):
        self.__netpay = self.__totalpay - self.__tax
        
    def get_name(self):
        return self.__name

    def get_rate(self):
        return self.__rate

    def get_regular_hour(self):
        return self.__Rhour

    def get_overtime_hour(self):
        return self.__Ohour

    def get_total_hour(self):
        return self.__totalhour

    def get_regular_pay(self):
        return self.__regularpay

    def get_overtime_pay(self):
        return self.__overtimepay

    def get_total_pay(self):
        return self.__totalpay

    def get_tax(self):
        return self.__tax

    def get_net_pay(self):
        return self.__netpay


def Again():
    again = "yes"
    while again =="yes":
        main()
        print()
        again = input("Do you want to run the program again <yes/no>?")

def main():

    test = Employee()

    test.set_name()
    test.set_rate()

    print()

    test.set_hour()
    test.set_total_hour()
    test.set_regular_pay()
    test.set_overtime_pay()
    test.set_total_pay()
    test.set_tax()
    test.set_net_pay()

    print()
    print()

    display(test)

def display(test):

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
          '{:>10}'.format(format(test.get_rate(),'.2f')))
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
        
        
        
