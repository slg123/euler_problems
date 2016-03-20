#!/usr/bin/python

NAMES = open('names.txt').read().split(',')

SORTED = sorted(NAMES)

def letter_value(n):
    # well this isn't pretty. 
    if n == 'A': return 1
    if n == 'B': return 2
    if n == 'C': return 3
    if n == 'D': return 4
    if n == 'E': return 5
    if n == 'F': return 6
    if n == 'G': return 7
    if n == 'H': return 8
    if n == 'I': return 9
    if n == 'J': return 10
    if n == 'K': return 11
    if n == 'L': return 12
    if n == 'M': return 13
    if n == 'N': return 14
    if n == 'O': return 15
    if n == 'P': return 16
    if n == 'Q': return 17
    if n == 'R': return 18
    if n == 'S': return 19
    if n == 'T': return 20
    if n == 'U': return 21
    if n == 'V': return 22
    if n == 'W': return 23
    if n == 'X': return 24
    if n == 'Y': return 25
    if n == 'Z': return 26
    return 0

def sum_word_value(n):
    total = 0
    for i in n:
        total += int(letter_value(i))
    return total

position = 0
grand_total = 0
for i in SORTED:
    position += 1
    grand_total += position * int(sum_word_value(i))

print grand_total



