#!/usr/bin/python

calories = []
protein = []
fat = []

items = 0
for line in open('cals_python.txt'):
    if line.startswith('#'):
        continue

    column = line.split()
    calories.append(float(column[5]) * float(column[2])) # total calories based on qty
    protein.append(float(column[6]) * float(column[2]))
    fat.append(float(column[7]) * float(column[2]))
    items += 1

print "total calories: " + str(sum(calories))
print "total protein: " + str(sum(protein)) + "g"
print "total fat: " + str(sum(fat)) + "g"
