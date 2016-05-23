#!/usr/bin/python

# pascal's triangle up to row 20, no pretty printing

n=20
last_row = []
this_row = [1]
for i in range(n):
    last_row = this_row
    this_row = [1]
    for j in range(i):
        this_row.append(last_row[j]+last_row[j+1])
    this_row.append(1)
    print this_row
    
    
    
        




    
