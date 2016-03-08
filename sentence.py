#!/usr/bin/env python

alphabet = 'abcdefghijklmnopqrstuvwxyz'
sentence = 'this is a sentence with quite a few letters in it, look, a zebra!'
absent = []
for i in alphabet:
    if i in alphabet and i not in sentence:
        absent.append(i)

print absent
