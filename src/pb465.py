from math import sqrt
from sympy.ntheory import totient

def mod(k):
	return k%1000000007

def sumtot(j):
	result = 0
	for k in range(n//(j+1)+1, n//j +1):
		#result = mod(result+totient(k))
		result = result+totient(k)
	return result

n = 10000

L = 1
for j in range(1, n//2+1):
	L = mod(L*int(pow(j+1, sumtot(j))))
L = mod(L*(n+1))

L8 = mod(int(pow(L, 8)))
L4 = mod(int(pow(L, 4)))

T  = 0
for j in range(1, n//2+1):
	T = mod(T+sumtot(j)*(2*j*L4 - j*j))
T = mod(T+2*n*L4-n*n)

print(mod(L8 - 4*T -1))

