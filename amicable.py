#!/usr/bin/python

def factor_sum(n):
    f = [i for i in range(1, n//2 + 1) if not n % i] + [n]
    return sum(f) - n

A = []
def make_amicable_list(n):
    k = factor_sum(n)
    j = factor_sum(k)
    if j == n and n != k:
        A.append(n)

for i in range(10000):
    make_amicable_list(i)

print sum(A)


