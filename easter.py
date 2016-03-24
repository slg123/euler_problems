#!/usr/bin/python

from math import *
import datetime

""" calculate the date of easter                  """
""" Meeus / Jones / Butcher algorithm             """
""" From Practical Astronomy With Your Calculator """

Y = input('Enter the year: ')
a = Y % 19
b = floor(Y/100)
c = Y % 100
d = floor(b/4)
e = b % 4
f = floor((b+8)/25)
g = floor((b-f+1)/3)
h = (19*a+b-d-g+15)%30
i = floor(c/4)
k = c % 4
L = (32+2*e+2*i-h-k)%7
m = floor((a+11*h+22*L)/451)
month = int ( floor((h+L-7*m+114)/31) )
day = int ( ((h+L-7*m+114) % 31) + 1 )

monthname = datetime.date(1900, month, 1).strftime('%B')

print str(day)+" "+str(monthname)
