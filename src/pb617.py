from math import log
from math import pow
from math import sqrt

import sys

def nsqrt(x, n):
	return x**(1/float(n))


def d(a0, e):
	cnt = 0
	eroot = nsqrt(a0, e)
	while eroot == int(eroot):
		cnt+=1
		eroot = nsqrt(eroot, e)
	return cnt


def subd(a0, e, N):
	k = d(a0, e)
	candidat = int(nsqrt(a0, e))
	while pow(a0, e)+candidat > N and k >= 0:
		candidat = int(nsqrt(candidat, e))
		k -= 1
	
	return k

def main(argv):
	N = int(argv[0])
	resultat = 0
	emax = int(log(N)/log(2))
	print ("emax = ", emax)
	for e in range(2, emax+1):
		a0 = 2
		while pow(a0, e)+a0 <= N:
			k = d(a0, e)+1
			resultat += k*k
			a0+=1
		if d(a0, e) > 0: # Border case  where the condition a0^e+a0 <= N might not hold anymore.
			print (a0, e)
			l = subd(a0, e, N) # If a0 = x^(e*k), we find the highest l s.t. a0^e+x^(e*l) <= N.
			if l >= 0:
				resultat += (l+1)**2

	print (resultat)

if __name__ == "__main__":
	main(sys.argv[1:])
