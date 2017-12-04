import sys
from math import factorial
import numpy
from itertools import combinations, chain

primes = [1]


def primesfrom2to(n):
    """ Input n>=6, Returns a array of primes, 2 <= p < n """
    sieve = numpy.ones(n/3 + (n%6==2), dtype=numpy.bool)
    for i in xrange(1,int(n**0.5)/3+1):
        if sieve[i]:
            k=3*i+1|1
            sieve[       k*k/3     ::2*k] = False
            sieve[k*(k-2*(i&1)+4)/3::2*k] = False
    return numpy.r_[2,3,((3*numpy.nonzero(sieve)[0][1:]+1)|1)]

def calcule(possib):
	resultat = primes[possib[0]] * possib[2]
	#print (possib, resultat)
	return resultat
	""""primeidx = possib[0]
	if possib[2] != 0:
		print(possib, possib[2])
		return possib[2] * primes[primeidx]
	arr = possib[1]
	resultat = 1
	for i in range(0, len(arr)):
		resultat *= primes[i+1]**arr[i]

	resultat *= primes[primeidx]
	print(possib, resultat)
	return resultat"""

def find_minimum(possi):
	index = 0
	minimum = calcule(possi[0])
	for i in range(0, len(possi)):
		if calcule(possi[i]) <  minimum:
			index = i
			minimum = calcule(possi[i])
	return index

def f(n):
	possi = [[0, [1], 2, 0]]
	cnt = 0
	times_to_mul = n-1

	while cnt < n:
		if cnt % 100 == 0:
			print (cnt, len(possi))
		cnt += 1
		index = find_minimum(possi)
		last_one = calcule(possi[index])
		if possi[index][0] > 0:
			#print ("going thru")
			possi[index][0] += 1
			#print(possi[index], (2**times_to_mul)*last_one)	
		else:
			#print ("NOT")
			#print(possi[index], (2**times_to_mul)*last_one)	
			minarr = possi[index][1]
			
			#possi[index][3] = 0
			if minarr[0] == 1:
				times_to_mul -= 1
				for i in range(0, len(possi)):
					possi[i][1][0] += 1
					possi[i][2] *= 2

			#minarr = possi[index][1]
			possi[index][0] = len(minarr)
		
			newarr1 = list(minarr[:-1])
			newarr1.extend([minarr[len(minarr)-1]-1, 1])
			newval1 = possi[index][2] / primes[len(minarr)] * primes[len(minarr)+1]
			possi.append([0, newarr1, newval1, len(minarr)-1])
			for i in range(possi[index][3], len(minarr) - 1):
				if minarr[i] != 0:# and minarr[i+1] != 0:
					newarr = list(minarr)
					newarr[i] -= 1
					newarr[i+1] += 1
					newval = possi[index][2] / primes[i+1] * primes[i+2]
					possi.append([0, newarr, newval, i])

	for x in possi:
		print (x[1])
	return last_one * (2**times_to_mul)

def main(argv):
	n = int(argv[0])
	primes.extend(primesfrom2to(100000000))
	print f(n) 
	#print ("Real: ", f(n) % 123454321)


if __name__ == "__main__":
	main(sys.argv[1:])
