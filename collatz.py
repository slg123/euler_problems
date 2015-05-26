#!/usr/bin/python

end = 0
tmp = 0

for i in range(1000000, 2, -1):
    chain = 0
    n = i
    while n != 1:
        if n % 2 == 0:
            n = n/2
            chain = chain + 1
        else:
            n = n*3 + 1
            chain = chain + 1
   
    if chain > tmp:
        tmp = chain
        end = i

print end
