from euler import *

d = dict({})
N = 50

def binomial(n, k):
	return factorial(n)/(factorial(k)*factorial(n-k))

def is_square_free(n):
	primes = factor_concat(n)
	for f in primes:
		if f[1]>1:
			return 0
	return 1

for n in xrange(0, N+1):
	for k in xrange(0, n):
		b = binomial(n, k)
		if b not in d:
			d[b] = 1

l = list(d)
result = 0
for n in l:
	if is_square_free(n)==1:
		result+=n

print result
			
