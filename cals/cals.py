#!/usr/bin/python

import csv

def get_totals():
    with open("calories.csv","r") as f:
        total_cals    = 0
        total_protein = 0
        for row in csv.reader(f):
            total_cals += (int(row[2]) * int(row[0]))
            total_protein += (int(row[3]) * int(row[0]))
    
    return total_cals, total_protein

(cals, protein) = get_totals()
print "cals: " + str(cals) + " protein: " + str(protein)
