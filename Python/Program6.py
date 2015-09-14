#********************************************************************
#
#  Author:            Jie Zhou
#
#  Program #:         6
#
#  File Name:         Program1.py
#
#  Course:            COSC 1336 Programming Fundamentals I 
#
#  Due Date:          3/18/2014
#
#  Instructor:        Fred Kumi 
#
#  Chapter:           Chapter 6
#
#  Maximum points:    20
#
#  Description:
#     An explanation of what the program is designed to do
#
#********************************************************************

def main():
    floors=int(input("Floors on the hotel:"))
    print()
    totalrooms=0
    totaloccupied=0
    
    for x in range(floors):
        
        print("Rooms on floor",x+1,end='')
        rooms=int(input(': '))

        occupied=int(input("Room occupied:    "))
        print()

        totalrooms+=rooms
        totaloccupied+=occupied

        unoccupied=totalrooms-totaloccupied

        per=totaloccupied/totalrooms

    print("Number of rooms in the hotel:        ",totalrooms)
    print("Number of rooms are occupied:        ",totaloccupied)
    print("Number of rooms are unoccupied:      ",unoccupied)
    print("The percentage of rooms are occupied:",format(per,'.0%'))
        
def userInfo():
    print('Name:     Jie Zhou')
    print('Course:   Programming Fundamentals I')
    print('Program:  Six')
    print()
    # End of userInfo

userInfo()
main()
