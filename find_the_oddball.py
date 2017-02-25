#!/usr/bin/python

a = [ 10, 10, 20, 20, 20, 30, 30, 9, 9, 8, 8, 7, 7, 4, 4, 4 ]

def get_num(n, *a):
    count = 0
    for i in a:
        if n == i:
            count += 1
    return count


wanted = []
for i in set(a):
    n = get_num(i, *a)
    if n % 2 != 0:
        wanted.append(i)
    

print wanted
    
