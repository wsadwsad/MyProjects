#********************************************************************
#
#  Author:            Jie Zhou
#
#  Program #:         9
#
#  File Name:         Program9.py
#
#  Course:            COSC 1336 Programming Fundamentals I 
#
#  Due Date:          4/22/2014
#
#  Instructor:        Fred Kumi 
#
#  Chapter:           Chapter 1-9
#
#  Maximum points:    40
#
#  Description:
#     This program reads and displays the contents
#     of a file.
#********************************************************************

outFile = open('program9-out.txt','w')
def main():
    
    inFile = open('program9.txt', 'r')
    
    
    acctdata1=[]
    incomedata1=[]
    memberdata1=[]
    
    lineRead = inFile.readline()       # Read first record
    while lineRead != '':              # While there are more records
       words = lineRead.split()        # Split the records into substrings
       acctNum = int(words[0])         # Convert first substring to integer
       annualIncome = float(words[1])  # Convert second substring to float
       members = int(words[2])         # Convert third substring to integer

       acctdata1.append(acctNum)
       incomedata1.append(annualIncome)
       memberdata1.append(members)
       
      
       
       lineRead = inFile.readline()    # Read next record

    incomedata=sorted(incomedata1)

    acctdata = sortdata1(acctdata1,incomedata1)
    
    memberdata = sortdata2(acctdata,acctdata1,memberdata1)
    
    totalIncome = totalincome(incomedata)
    average=averageincome(memberdata,totalIncome)
    list1(acctdata,incomedata,memberdata)
    print()

    averagein(average)
    print()
    
    list2(average,acctdata,incomedata,memberdata)
    print()

    print("Families below the poverty level:")
    print()

    list3(acctdata,incomedata,memberdata)
    
     
    # Close the file.
    inFile.close() # Close file
    outFile.close()
    
def sortdata1(acctdata1,incomedata1):
    temp1=dict(zip(acctdata1,incomedata1))
    t1=sorted(temp1,key=temp1.get)
    return t1

def sortdata2(acctdata,acctdata1,memberdata1):
    t2=[]
    for aa in acctdata:
        tempposition=acctdata1.index(aa)
        t2.append(memberdata1[tempposition])
    return t2

def list1(acctdata,incomedata,memberdata):
    a=0
    fm='$%s'
    for position in incomedata:
        
        print('{:>12}'.format(acctdata[a]),\
              '{:>18}'.format(fm%(format(position,',.2f'))),\
              '{:>9}'.format(memberdata[a]))
        outFile.write(str(acctdata[a])+'\n')
        outFile.write(str(position)+'\n')
        outFile.write(str(memberdata[a])+'\n')
        a+=1
    
def averagein(average):
    print("Families abbove the average income of $",\
          format(average,',.2f'),sep='')
    outFile.write(str(average)+'\n')
    
def totalincome(incomedata):
    total = 0
    for a in incomedata:
        total += a
    return total

def averageincome(memberdata,totalIncome):
    aver= totalIncome / len(memberdata)
    return aver
    

def list2(average,acctdata,incomedata,memberdata):
    fm='$%s'
    for income in incomedata:
        if income >= average:
            positiona =  incomedata.index(income)
            print('{:>12}'.format(acctdata[positiona]),\
                  '{:>18}'.format(fm%(format(income,',.2f'))),\
                  '{:>9}'.format(memberdata[positiona]))
            outFile.write(str(acctdata[positiona])+'\n')
            outFile.write(str(income)+'\n')
            outFile.write(str(memberdata[positiona])+'\n')

def list3(acctdata,incomedata,memberdata):
    a=0
    b=0
    fm='$%s'
    for m in memberdata:
       povertyLevel = 15130+3960*(m-2)
       if incomedata[a]<povertyLevel:
           print('{:>16}'.format(fm%(format(povertyLevel,',.2f'))),\
                 '{:>11}'.format(acctdata[a]),\
                 '{:>17}'.format(fm%(format(incomedata[a],',.2f'))),\
                 '{:>6}'.format(m))
           outFile.write(str(povertyLevel)+'\n')
           outFile.write(str(acctdata[a])+'\n')
           outFile.write(str(incomedata[a])+'\n')
           b+=1
       a+=1
    percentage=b/a
    print()
    print('Percentage below the poverty level is:',\
          format(percentage,'.2%'))
    outFile.write(str(percentage)+'\n')
# Call the main function.
main()
