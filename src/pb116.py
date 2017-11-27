from math import *

def nCr(n, k):
	return factorial(n)/(factorial(n-k)*factorial(k));

n = 5
count = 0

""" Counting red configurations """
for i in xrange(1, int(n/2)+1):
	count += nCr(n-i, n-2*i)


""" Counting green configurations """
for i in xrange(1, int(n/3)+1):
	count += nCr(n-2*i, n-3*i)

""" Counting blue configurations """
for i in xrange(1, int(n/4)+1):
	count += nCr(n-3*i, n-4*i)

print count
