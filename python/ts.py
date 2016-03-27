#!/usr/bin/python

import time

#
#     n
#    E    n + 1
#     i=1
#
def one():
    def sumOfN(n):
        start = time.time()

        sum = 0
        for i in range(1, n+1):
            sum = sum + i

        end = time.time() 

        return sum, end-start

    for i in range(10):
        print("Sum is %d required %10.7f seconds"%sumOfN(10000000))

    print("\n\n\n"); 

#
#     n
#    E    (n)(n+1)
#     i=1  ------
#            2
#
def two():
    def sumOfN2(n):
        start = time.time()
        return (n*(n+1))/2, time.time()-start

    for i in range(10):
        print("Sum is %d required %10.7f seconds"%sumOfN2(10000000))

    print("\n\n\n"); 
         

#
#     n
#    E    (n)(n+1)
#     i=1  ------
#            3
#
def three():
    def sumOfN3(n):
        start = time.time()
        return (n*(n+1))/3, time.time()-start

    for i in range(10):
        print("Sum is %d required %10.7f seconds"%sumOfN3(10000000))

    print("\n\n\n"); 

#
#     n    2
#    E    n
#     i=1 
#        
#
def four():
    def nSquared(n):
        i = 0
        start = time.time()
        j = 5 * (n**2) + 27*n + 1005
        i = (n**2)
        end = time.time()
        return i, end-start

    for i in range(10):
        print("Sum is %d required %10.7f seconds"%nSquared(10000000))

    print("\n\n\n")

    for j in range(10):
        print("Sum is %d required %10.7f seconds"%nSquared(10000000))

    print(nSquared(2)); 
    print(nSquared(3)); 
    print(nSquared(4)); 
    
one()
two()
three()
four()



