#!/usr/bin/python

def dec2bin(n):
    l = []
    while n > 0:
        if n % 2 == 0:
            l.append(0)
        else:
            l.append(1)
        n = n / 2
    #return ''.join(map(str, l))[::-1]
    return ''.join(reversed((map(str, l))))

print dec2bin(42)
print dec2bin(512)
print dec2bin(1024)
print dec2bin(1138)
print dec2bin(2016)
