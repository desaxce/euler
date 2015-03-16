from euler import *

def is_harshad(x):
	xx = x
	result = 0
	while xx!=0:
		result += xx%10
		xx /= 10
	return (x%result==0)

def is_strong_harshad(x):
	result = 0
	xx = x
	while xx!=0:
		result += xx%10
		xx /= 10
	return ((x%result==0) and is_prime(x/result))

n = 13
l = [[] for i in xrange(0, n)]
l[0] = [1, 2, 3, 4, 5, 6, 7, 8, 9]
r = []

for i in xrange(1, n):
	for x in l[i-1]:
		for j in xrange(0, 10):
			if is_harshad(10*x+j):
				l[i].append(10*x+j)

for i in xrange(0, n):
	for x in l[i]:
		for j in xrange(0, 10):
			if is_strong_harshad(x) and is_prime(10*x+j):
				r.append(10*x+j)

print sum(r)
