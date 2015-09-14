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

def main():
    q=int(input("How many packages to purchase?" ))
    if q>=100:
        dis=0.5
    elif q>=70:
        dis=0.4
    elif q>=50:
        dis=0.35
    elif q>=20:
        dis=0.3
    elif q>=10:
        dis=0.2
    else:
        dis=0
    total       = q*99
    totalsaving = total*dis
    totalcost   = total-totalsaving

    print("Number of units purchased is:",q)
    print("Discount applied is:",format(dis,'.0%'))
    print("Total savings due to discount is: $",format(totalsaving,',.2f'),sep="")
    print("The total cost of the purchase is: $",format(totalcost,',.2f'),sep="")

def userInfo():
    print('Name:     Jie Zhou')
    print('Course:   Programming Fundamentals I')
    print('Program:  Four')
    print()
    # End of userInfo

userInfo()
main()

# End of Pragram 4
