#!/usr/bin/python

from collections import OrderedDict

def getInts():
    with open("new.dat", "r") as f:
        a = [int(x) for x in f.read().split()]

    return a


ints = getInts()

def getFreq(n):
    total = 0
    for i in ints:
        if i == n:
            total += 1

    return total


def makeHistogram(n):
    histogram = []
    for i in range(n):
        histogram.append("*")

    return ''.join(histogram)

numFreq = {}
for k in range(1, 55):
    numFreq[k] = getFreq(k)

sortedByValue = OrderedDict(sorted(numFreq.items(), key=lambda x: x[1]))

for k, v in sortedByValue.items():
    if k < 10:
        if v > 100:
            print str(k) + "  -> " + str(v) + " : " + makeHistogram(getFreq(k))
        else:
            print str(k) + " ->  " + str(v) + " : " + makeHistogram(getFreq(k))
          
    else:
        if v > 100:
            print str(k) + " -> " + str(v) + " : " + makeHistogram(getFreq(k))
        else:
            print str(k) + " ->  " + str(v) + " : " + makeHistogram(getFreq(k))
