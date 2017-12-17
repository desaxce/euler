import sys

from math import *
from sympy.ntheory.primetest import *

res = set({})

def solve(n):
	# First part: composite number at a power more than (or equal to) 2.
	for i in range(5, int(sqrt(n)+1)):
		if not isprime(i):
			exposant = 2
			while int(pow(i, exposant)) <= n:
				res.add(int(pow(i, exposant)))
				exposant += 1

	# Second part: prime number > 2 at any power (exponent has to be composite).
	for i in range(3, int(sqrt(n)+1)):
		if isprime(i):
			exposant = 4
			while int(pow(i, exposant)) <= n:
				if not isprime(exposant):
					res.add(int(pow(i, exposant)))
				exposant += 1

	# Third part: power of 2 with exponent > 4 and composite.
	exposant = 6
	while int(pow(2, exposant)) <= n:
		if not isprime(exposant):
			res.add(int(pow(2, exposant)))
		exposant += 1

def main(argv):
	n = int(argv[0])
	solve(n)
	print (res)

	resultat = 0
	for c in res:
		resultat+=c
	print (resultat)

if __name__ == "__main__":
	main(sys.argv[1:])
