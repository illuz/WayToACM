#!/usr/bin/python 
# by hcbbt 2015-01-24 01:20:06
# 

import random

for i in range(1000):
    t = random.randrange(1, 40)
    print t, random.randrange(1<<t) + 1
