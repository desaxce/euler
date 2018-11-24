import sys
from math import *

def totientsuma(n):
	if n==1 or n==2:
		return n
	if n==3:
		return 4

	L = int((n*1./log(log(n)))**(2./3))
	sieve = [i for i in range(0, L+1)]
	bigV = [0 for i in range(0, n//L+1)]

	for p in range(2, L+1):
		if p == sieve[p]:
			k = p
			while k <= L:
				sieve[k] -= sieve[k]//p
				k +=p
		sieve[p] += sieve[p-1]
	
	for x in range(n//L, 0, -1):
		k = n//x
		res = (k*(k+1))//2

		fin = int(sqrt(k))+1
		for g in range(2, fin):
			if k//g <= L:
				res -= sieve[k//g]
			else:
				res -= bigV[x*g]
			if g != k//g:
				res -= sieve[g]*(k//g-k//(g+1))
		
		if k != 1:
			res -= sieve[1]*(k-(k//2))

		bigV[x] = res

	return bigV[1:n//L+1]

def totientsum(n):
	if n==1 or n==2:
		return n
	if n==3:
		return 4

	L = int((n*1./log(log(n)))**(2./3))
	sieve = [i for i in range(0, L+1)]
	bigV = [0 for i in range(0, n//L+1)]

	for p in range(2, L+1):
		if p == sieve[p]:
			k = p
			while k <= L:
				sieve[k] -= sieve[k]//p
				k +=p
		sieve[p] += sieve[p-1]
	
	for x in range(n//L, 0, -1):
		k = n//x
		res = (k*(k+1))//2

		fin = int(sqrt(k))+1
		for g in range(2, fin):
			if k//g <= L:
				res -= sieve[k//g]
			else:
				res -= bigV[x*g]
			if g != k//g:
				res -= sieve[g]*(k//g-k//(g+1))
		
		if k != 1:
			res -= sieve[1]*(k-(k//2))

		bigV[x] = res

	return bigV[1]

