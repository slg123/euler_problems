#!/usr/bin/env python

from fractions import Fraction
import math

def trapezium(f,x,h):
    return (f(x) + f(x+h))/2.0

def integrate(f, a, b, steps, method):
    h = (b-a) / steps
    ival = h * sum(method(f, a+i*h, h) for i in range(steps))
    return ival

def f1(x):
    return 2*x

print integrate(f1, 1, math.pi, 100, trapezium)
