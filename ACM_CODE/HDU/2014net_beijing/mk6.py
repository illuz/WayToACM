#!/usr/bin/python 
# by hcbbt 2014-09-21 14:24:19
# 

import random

N = 20
M = 1000

t = 100
print t

for i in range(t):
    n = random.randrange(N)
    m = random.randrange(1, M)
    l = random.randrange(1, M / 5)
    print n, m, l
    for j in range(n):
        print random.randrange(1, m),
    print

