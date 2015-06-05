#!/usr/bin/python3

import functools

@functools.lru_cache(maxsize=None)
def fibonacci(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fibonacci(n-1) + fibonacci(n-2)

for i in range(0,10000):
    if len(str(fibonacci(i))) == 1000:
        print("term: "+str(i))
        break

