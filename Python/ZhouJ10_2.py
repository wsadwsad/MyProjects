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

    def __init__(self, name, temprate, regularhour, overhour):
        self.__name = name
        self.__rate = 7.25
        self.__Rhour = regularhour
        self.__Ohour = overhour
        self.__totalhour = 0
        self.__regularpay = 0
        self.__overtimepay = 0
        self.__totalpay = 0
        self.__tax = 0
        self.__netpay = 0
        
    def set_name(self):
        self.__name = name
        
    def Rate(self,temprate):
        if temprate >= self.__rate:
            return temprate
        else:
            return self.__rate    

    def set_regular_hour(self):
        self.__Rhour = regularhour

    def set_overtime_hour(self):
        self.__Ohour = overhour

    def set_total_hour(self):
        self.__totalhour = self.__Rhour + self.__Ohour

    def set_regular_pay(self,rate):
        self.__regularpay = self.__Rhour * rate

    def set_overtime_pay(self,rate):
        self.__overtimepay = self.__Ohour*(rate*1.5)

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


        
        
        
