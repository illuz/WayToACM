#!/usr/bin/python 
# by hcbbt 2014-06-28 21:50:26
# 

import random

rr = random.randrange

t = rr(1, 10)

print t

for i in range(t):
    n = rr(1, 10)
    k = rr(1, 6)
    print n, k
    for i in range(n):
        for i in range(4):
            print rr(1, 1000),
        print rr(1, 1000)
