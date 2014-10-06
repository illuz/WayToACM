#!/usr/bin/python 
# by hcbbt 2014-10-02 15:36:31
# data maker of poj 1211 

import random

for i in range(10000):
    t = random.randrange(1, 100)
    for j in range(t):
        print random.randrange(6, 100),
    print 0

print '0 0 0'
