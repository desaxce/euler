import sys
from math import *

def totientsum(n):
	if n==1:
		return 1
	elif n==2:
		return 2
	elif n==3:
		return 4
	L = int((n*1./log(log(n)))**(2./3))
	sieve = [i for i in range(0, L+1)]
	bigV = [0 for i in range(0, int(n/L)+1)]

	for p in range(2, L+1):
		if p == sieve[p]:
			k = p
			while k <= L:
				sieve[k] -= sieve[k]//p
				k +=p

		sieve[p] += sieve[p-1]
	
	for x in range(int(n/L), 0, -1):
		k = int(n/x)
		res = k*(k+1)//2

		for g in range(2, int(sqrt(k))+1):
			if int(k/g) <= L:
				res -= sieve[int(k/g)]
			else:
				res -= bigV[x*g]

		for z in range(1, int(sqrt(k))+1):
			if z != int(k/z):
				res -= sieve[z] * (int(k/z) - int(k/(z+1)))

		bigV[x] = res

	return bigV[1]


