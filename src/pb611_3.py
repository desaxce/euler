import sys

from math import floor, ceil
from math import log
from math import sqrt
from sympy.ntheory import mobius
from bisect import bisect

import time
from sympy.ntheory.factor_ import factorint
from sympy.physics.mechanics.tests.test_system import out_eqns

T1 = []
T1C = []

T3 = []
T3C = []

out = []

queueF = []

F_tilde_cache = {}

def biggest_prime_index_below_or_equal(y):
	if y > out[len(out)-1]:
		return -1
	else:
		a = 0
		b = len(out)-1
		prevm = -1
		m = int((a+b)/2)
		while prevm!=m:
			if out[m] > y:
				b = m-1
			else:
				a = m
			prevm = m
			m = int((a+b)/2)
		if out[b] <= y:
			return b
		else:
			return a

def smallest_prime_index_above(y):
	if y > out[len(out)-1]:
		return -1
	else:
		a = 0
		b = len(out)-1
		m = int((a+b)/2.)
		while a!=b:
			if out[m] > y:
				b = m
			else:
				a = m+1
			m = int((a+b)/2.)
		return m
		
def count_pp(N):
	result = 0
	out = list()
	sieve = [True] * (N+1)
	for p in range(2, N+1):
		if sieve[p]:
			out.append(p)
			for i in range(p, N+1, p):
				sieve[i] = False
	return len(out)

def count_p(N, l):
	out = list()
	sieve = [True] * (N+1)
	for p in range(2, N+1):
		if sieve[p]:
			out.append(p)
			for i in range(p, N+1, p):
				sieve[i] = False
	result = 0
	for p in out:
		if p%4==l:
			result+=1
	return result

def initialize1(y):
	global T1, T1C, T3, T3C, out
	T1 = []
	T1C = []
	T3 = []
	T3C = []
	out = []

	sieve = [True] * (y+1)
	for p in range(2, y+1):
		if sieve[p]:
			out.append(p)
			for i in range(p, y+1, p):
				sieve[i] = False
	
	for p in out[1:]:
		if p%4==1:
			T1.append(p)
		elif p%4 ==3:
			T3.append(p)
			
	"""T1C = [0]*(y+1)	
	for i in range(0, len(T1)):
		T1C[T1[i]] = T1C[T1[i]-1]+1
		if i == len(T1)-1:
			limit = y+1
		else:
			limit = T1[i+1]
		for j in range(T1[i]+1, limit):
			T1C[j] = T1C[T1[i]]
			
	T3C = [0]*(y+1)	
	for i in range(0, len(T3)):
		T3C[T3[i]] = T3C[T3[i]-1]+1
		if i == len(T3)-1:
			limit = y+1
		else:
			limit = T3[i+1]
		for j in range(T3[i]+1, limit):
			T3C[j] = T3C[T3[i]]"""
			
def prime_pi_naif(x, l):
	if l==1:
		return bisect(T1, int(x))#T1C[int(x)]
	else:
		return bisect(T3, int(x))#T3C[int(x)]

def F(x, y, l):
	if y <= 1:
		return 0
# 	return betterF_tilde(x, y, l)
	pa_index = biggest_prime_index_below_or_equal(y)
 	#queueF.append([x, pa_index, l, 1])
	#return F_tilde(x, pa_index, l)
	return phimod(x, pa_index, l)

phi_cachemod = {}

def phimod(x, a, l):
	"""
	Implementation of the partial sieve function, which 
	counts the number of integers n <= x with:
		- no prime factor less than or equal to the ath prime
		- n%4 = l
	"""
	# If value is cached, just return it
	if (x, a, l) in phi_cachemod: return phi_cachemod[(x, a, l)]
	
	#Base case: phi(x, a, l) is computable easily
	if x < 1:
		return 0
	if a == 0:
		if l == 1:
			return int((x-1)/4)+1
		else:
			return int((x+1)/4)
	
	result = phimod(x, a-1, l) - phimod(int(x / out[a]), a-1, (l*out[a])%4)
	phi_cachemod[(x, a, l)] = result # Memoize
	return result

def F_tilde(x, a, l):
# 	if (x, a, l) in F_tilde_cache.keys():
# 		print "Using cache"
# 		return F_tilde_cache.get((x, a, l))
	if x < 1:
		return 0
	if a==0:
		if l == 1:
			return int((x-1)/4)+1
		else:
			return int((x+1)/4)
	
	premier = F_tilde(x, a-1, l)
# 	F_tilde_cache[(x, a-1, l)] = premier
	
	deuxieme = F_tilde(int(x/out[a]), a-1, (l*out[a])%4)
# 	F_tilde_cache[(x/out[a], a-1, (l*out[a])%4)] = deuxieme
	
	return  premier-deuxieme
# 	ftilde = 0
# 	while len(queueF)!=0:
# 		x, a, l, eps = queueF.pop()
# 		if x >= 1:
# 			if a == 0:
# 				if l%4 == 1:
# 					ftilde += ((x-1)/4+1)*eps
# 				else:
# 					ftilde += ((x+1)/4)*eps
# 			else:
# 				queueF.append([x, a-1, l, eps])
# 				queueF.append([x/out[a], a-1, l*out[a], -eps])
# 	return ftilde

def betterF_tilde(x, y, l):
	z = y
	result = 0
	print ("Computing S0...")
	result += S0(x, y, l, z)
	print ("Done!")
	
	print ("Computing S...")
	result += -S(x, y, l, z)
	print ("Done!")
	return result;
# 	return S0(x, y, l, z) - S(x, y, l, z)

def S0(x, y, l, z):
	somme = 0
	for m in range(1, z+1):
		if gamma(m) <= y:
			queueF.append([x/m, 0, (l*m)%4, 1])
			somme += mobius(m)*F_tilde()
	return somme

def gamma(m):
	if m==1:
		return 1
	return max(factorint(m), key=int)

def delta(m):
	if m==1:
		return 1
	return min(factorint(m), key=int)

def S(x, y, l, z):
	somme = 0
	a = biggest_prime_index_below_or_equal(y)
	print ("a = ", a)
	for b in range(1, a+1):
		pb = out[b]
		print ("from ", z/pb+1, "to ", z)
		for m in range(z/pb+1, z+1):
			if delta(m) > pb and gamma(m) <= y:
				queueF.append([x/(m*pb), b-1, (l*m*pb)%4, 1])
				somme+=mobius(m)*F_tilde()
	return somme
# 	result = 0
# 	
# 	print "Computing S1...",
# 	result += S1(x, y, l, z)
# 	print "Done!"
# 	
# 	return result
# 	limit = int(x**(1/4.))
# 	return S3(x, y, l, z, limit);

def S1(x, y, l, z):
	somme = 0
	start = smallest_prime_index_above(int(x**(1/3)))
	fin = biggest_prime_index_below_or_equal(y)
	if out[fin] == y:
		fin -= 1
	for i in range(start, fin+1):
		somme += prime_pi_naif(y, (l*out[i])%4)-prime_pi_naif(out[i], (l*out[i])%4)
	return somme
	
def S3(x, y, l, z, limit):
	somme = 0
	a = biggest_prime_index_below_or_equal(limit)
	for b in range(1, a+1):
		pb = out[b]
		for m in range(z/pb+1, z+1):
			if delta(m) > pb and gamma(m) <= y:
				queueF.append([x/(m*pb), b-1, (l*m*pb)%4, 1])
				somme+=mobius(m)*F_tilde()
	return somme
	
def P2(x, y, l):
	global out
	somme = 0
	#print ("y = ", y)
	#print ("int(sqrt(x)) = ", int(sqrt(x)))
	fromLimit = smallest_prime_index_above(y)
	#print (out[fromLimit])
	toLimit = biggest_prime_index_below_or_equal(int(sqrt(x)))
	#print(toLimit)
	for p in out[fromLimit: toLimit+1]:
		ll = (l*p)%4
		somme += prime_pi_naif(x/p, ll)
		somme -= prime_pi_naif(p-1, ll)
	return somme

def P3(x, y, l):
	global out
	somme = 0
	a = biggest_prime_index_below_or_equal(y)
	limit = smallest_prime_index_above(int(sqrt(x)))
	for i in range(a+1, limit):
		somme += P2(int(x/out[i]), out[i-1], (l*out[i])%4)
	return somme

# def inverse(l, p):
# 	return (p*l)%4
	
def prime_pi(x, l):
	y = int(2*x ** (1./4)+1)
	
	#initialize1(int(x/y)+1)
	
	if l == 1:
		result = -1
	else:
		result = 0
		
	#print ("Computing naive part... ")
	result += prime_pi_naif(y, l)
	#print ("Done!")
	
	#print ("Computing P2...")
	result += -P2(x, y, l)
	#print ("Done!")
	
	#print ("Computing P3...")
	result += -P3(x, y, l)
	#print ("Done!")
	
	#print ("Computing F...")
	result += F(x, y, l)
	#print ("Done!")
	
	return result
	
"""def main(argv):
	global T1, T1C, T3, T3C
	N = 10**9

	time1 = time.time()
	nbp1 = prime_pi(N, 1)
	print ("nb primes modulo 1 up to ", N, " = ", nbp1)
	
	print ("Done in ", time.time()-time1)

if __name__ == "__main__":
	main(sys.argv[1:])"""
