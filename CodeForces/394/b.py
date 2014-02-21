p, x = map(int, raw_input().split())
a, b, c = 1, (10 ** p - 1), (10 * x - 1)
x = b % c
while ((a * b // c * 10 < 10 ** p) or (a * x) % c) and a < 10:
	a += 1
if a >= 10: print 'Impossible'
else: print a * b // c
