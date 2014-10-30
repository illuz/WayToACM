#!/usr/bin/python 
# by hcbbt 2014-10-22 14:58:03
# 

import random

t = 10000

print t

i = 0
while (i < t):
    i += 1
    # n = random.randrange(1, 100)
    n = 5
    k = random.randrange(1, 3)
    print n, k
    j = 0
    while (j < n):
        j += 1
        print random.randrange(-50, 50),
    print
