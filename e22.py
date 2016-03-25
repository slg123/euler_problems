#!/usr/bin/python

#
# open a file called names.txt.
# alphabetically sort the names as a list.
# for each name in the list, calculate the letter value of each letter in each name.
#
#    i.e. A = 1, B = 2, ... Z = 26
#
# calculate the word value of each name by adding letter values.
# multiply the position of the word in the sorted list by it's word value.
#
#

NAMES = open('names.txt').read().split(',')

SORTED = sorted(NAMES)

def sum_word_value(n):
    sum = 0
    for i in n:
        if i.isalpha():
            sum += ord(i)-64
    return sum

position = total = 0
for i in SORTED:
    position += 1
    total += position * sum_word_value(i)

print total
