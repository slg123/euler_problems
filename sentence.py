#!/usr/bin/env python

alphabet = 'abcdefghijklmnopqrstuvwxyz'
sentence = 'this is a sentence'
absent = []
for i in alphabet:
    if i in alphabet and i not in sentence:
        absent.append(i)

print absent
