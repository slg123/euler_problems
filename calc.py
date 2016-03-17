#!/usr/bin/env python

# derivative fxn
def D(f, h=1e-3):
    def df(x):
        derive=(f(x+h)-f(x))/h
        return round(derive, 3)
    return df

def g(x):
    return x*x

N = []
N.append([g(x) for x in range(11)])
print N

# definite integral fxn
def I(f, h=1e-3):
    def intf(b, a=0):
        sum=0
        x=a
        while x <= b:
            sum += h*(f(x+h)+f(x))/2.0
            x += h
        return round(sum, 3)
    return intf

inv1 = I(D(g))
M = []
M.append([inv1(x) for x in range(11)])
print M

Q = []
# reverse I and D
inv2 = D(I(g))
Q.append([inv2(x) for x in range(11)])
print Q


