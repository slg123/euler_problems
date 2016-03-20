#!/usr/bin/python

NAMES = open('names.txt').read().split(',')

SORTED = sorted(NAMES)

def sum_word_value(n):
    total = 0
    for i in n:
        if i.isalpha():
            total += ord(i)-64
    return total

position = 0
grand_total = 0
for i in SORTED:
    position += 1
    grand_total += position * sum_word_value(i)

print grand_total

