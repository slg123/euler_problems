#!/usr/bin/python

def pascals_triangle(n):
    first_row = [1]
    last_row = []
    this_row = [1]
    print first_row
    for i in range(n):
        last_row = this_row
        this_row = [1]
        for j in range(i):
            this_row.append(last_row[j]+last_row[j+1])
        this_row.append(1)
        print this_row

if __name__ == "__main__":
    pascals_triangle(13)


