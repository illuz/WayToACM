import random

for i in range(100):
	x = random.randrange(7)
	print x + 1
	for y in range(x + 1):
		print random.randrange(-100, 100), random.randrange(-100, 100)
		print random.randrange(100), random.randrange(100)

print '0'

