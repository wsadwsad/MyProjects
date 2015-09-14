#********************************************************************
#
#  Author:            Jie Zhou
#
#  Program #:         Bonus Program
#
#  File Name:         ZhouJ_Bonus.py
#
#  Course:            COSC 1336 Programming Fundamentals I 
#
#  Due Date:          5/06/2014
#
#  Instructor:        Fred Kumi 
#
#  Chapter:           Chapter 1-13
#
#  Maximum points:    40
#
#  Description:
#     Classes
#
#********************************************************************


def main():
    retail = Retail_Item()
    test = Cash_Register()
    test.data(retail.get_item_number(),\
              retail.get_description(),\
              retail.get_unit_in_inventory(),\
              retail.get_price())
    answer = 'n'

    while answer == 'n' or answer == 'N':
        test.Menu()
        print()
        print()
        Number = int(input("Enter the menu number of the item \
you would like to purchase: "))
        if Number == 8:
            test.show_items()
        else:
            test.purchase_item(Number)
        answer = input("Are you ready to check out <Y/N>?")
        x = 1
        while x == 1:
            if answer == 'y' or answer == 'n':
                x = 0
            else:
                print("Invalid input!")
                answer = input("Are you ready to check out <Y/N>?")
        
    else:
        test.get_total()
        test.clear()



class Retail_Item:

    def __init__(self):
        self.__item_number = [1000,2000,3000,4000,5000,6000,7000]
        self.__description = ['Pants','Jeans','Shirt',\
                             'Dress','Socks','Sweater','Jacket']
        self.__unit_in_inventory = [10,2,15,3,50,5,1]
        self.__price = [19.99, 25.95, 12.50, 79.00, 1.98, 49.99, 85.95]

    def get_item_number(self):
        return self.__item_number

    def get_description(self):
        return self.__description

    def get_unit_in_inventory(self):
        return self.__unit_in_inventory

    def get_price(self):
        return self.__price


class Cash_Register:

    def __init__(self):
        self.__item_number_list = []
        self.__description_list = []
        self.__unit_list = []
        self.__price = []
        self.__total_item_number = []
        self.__total_des = []
        self.__total_price = []
        self.__sub_total = 0

    def data(self,list1,list2,list3,list4):
        self.__item_number_list = list1
        self.__description_list = list2
        self.__unit_list = list3
        self.__price = list4

    def Menu(self):
        print("1. Pants")
        print("2. Jeans")
        print("3. Shirt")
        print("4. Dress")
        print("5. Socks")
        print("6. Sweater")
        print("7. Jacket")
        print("8. Show Inventory")

    def purchase_item(self,Number):
        self.__total_item_number.append(self.__item_number_list[Number-1])
        self.__total_des.append(self.__description_list[Number-1])
        self.__total_price.append(self.__price[Number-1])
        if self.__unit_list[Number-1] - 1 >= 0:
            self.__unit_list[Number-1] = self.__unit_list[Number-1] - 1
        else:
            print("The item is out of stock")
                
    def show_items(self):
        print('Item Number','{:>18}'.format('Description'),\
              '{:>24}'.format('Units in inventory'),\
              '{:>11}'.format('Price'))
        for a in range(0,7):
            print('   ','{:<17}'.format(self.__item_number_list[a]),\
                  '{:<20}'.format(self.__description_list[a]),\
                  '{:<15}'.format(self.__unit_list[a]),\
                  '{:>8}'.format(format(self.__price[a],'.2f')))

    def get_total(self):
        print('Item Number','{:>18}'.format('Description'),\
              '{:>19}'.format('Price'))
        for a in range(0,len(self.__total_item_number)):
            print('   ','{:<17}'.format(self.__total_item_number[a]),\
                  '{:<18}'.format(self.__total_des[a]),\
                  '{:>9}'.format(format(self.__total_price[a],'.2f')))
        print()
        print()
        self.__sub_total = sum(self.__total_price)
        tax = self.__sub_total * 0.0825
        total_price = self.__sub_total * 1.0825
        print('{:<12}'.format('Sub Total:'),\
              '{:>10}'.format(format(self.__sub_total,'.2f')))
        print('{:<12}'.format('Tax:'),\
              '{:>10}'.format(format(tax,'.2f')))
        print('{:<12}'.format('Total Price:'),\
              '{:>10}'.format(format(total_price,'.2f')))
        
        
    def clear(self):
        self.__total_item_number = []
        self.__total_des = []
        self.__total_price = []
        input('Press any key to continue')

main()
