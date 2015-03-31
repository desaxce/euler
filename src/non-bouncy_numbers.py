from math import factorial

def nCr(n, k):
	return factorial(n)/(factorial(n-k)*factorial(k));

count = 0
for i in xrange(1, 101):
	count += nCr(8+i, i)
	count += nCr(9+i, i)
	count -= 10
print count
