#!/usr/bin/env python

import time

fed=False
count=0
while not fed:
    print "meow meow meow"
    count=count+1
    time.sleep(1)
    if count % 10 == 0:
        fstatus = raw_input('feed me? (y/n)')
        if fstatus == 'y':
            fed=True
        else:
            fed=False


