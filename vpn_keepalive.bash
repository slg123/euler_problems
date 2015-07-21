#!/bin/bash

GATEWAY=$1
if [ !$GATEWAY ]; then
    echo "usage: $0 <gateway ip address>"
    exit -1
fi

i=0
while [ $i -lt 10000 ]; do
    random_sleep=$((RANDOM % 120))
    ping -c 1 $GATEWAY
    echo "sleeping $random_sleep seconds"
    sleep $random_sleep
done

