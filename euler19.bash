#!/usr/bin/bash

i=1901
num_sundays=0
while [ $i -le 2000 ]; do
    j=1
    echo "working on year $i..."
    while [ $j -le 12 ]; do
        val=`cal $j $i | awk -F, '{sum += $1} END {print sum}'`
        if [ $val -eq 46 ]; then
            let num_sundays=$num_sundays+1
        fi
        if [ $val -eq 75 ]; then
            let num_sundays=$num_sundays+1
        fi
        let j=$j+1
    done
    let i=$i+1
done
echo "$num_sundays sundays fall on the first of the month" 
echo "from 1 Jan 1901 to 31 Dec 2000"
