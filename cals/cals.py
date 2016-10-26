#!/usr/bin/python

import csv

def get_totals():

    total_cals    = 0
    total_protein = 0

    with open("calories.csv", "r") as f:

        for row in csv.reader(f):
            total_cals += (float(row[2]) * float(row[0]))
            total_protein += (float(row[3]) * float(row[0]))
    
    return total_cals, total_protein

(cals, protein) = get_totals()
print "cals: " + str(cals) + " protein: " + str(protein)
