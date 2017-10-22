import sys
from math import factorial

from itertools import combinations, chain

digits = [i for i in range(10)]
allsubsets = lambda n :  list(chain(*[combinations(range(n), ni) for ni in range(n+1)]))

def T(S, k):
	N = 10**k
	s = len(S)
	if 0 not in S:
		if k == 1:
			return s
		else:
			return (10-s) * T(S, k-1) + s*(10**(k-1))
	else:
		if k == 2:
			return s*10 - 1 + (s-1)*(10-s)
		else:
			result = T(S, k-1) + (s-1) * (10**(k-1))
			SS = list(S)
			SS.remove(0)
			SS.append(11)
			result += (10 - s) * T(SS, k-1)
			return result

def Tp(S, k):
	result = 0
	N = 10 ** k
	for p in range(1, N):
		digits = set([int(d) for d in str(p)])
		if len(intersect(digits, set(S))) != 0:
			result += 1
	return result

def Rp(S, k):
	s = len(S)
	if s == 1 and 0 not in S:
		return k
	somme = 0
	while k >= s:
		#print (list(S), k)
		#print (R(list(S), k))
		somme += R(list(S), k)
		k -= 1
	return somme

def R(S, k):
	s = len(S)
	if s == 0:
		return 0
	if s > k:
		return 0
	if s == 1 and 0 in S:
		return 0
	if k == 1:
		return 1
	if 0 in S:
		S.remove(0)
		S.append(11)
		return (s-1) * (R(S, k-1) + R(S[1:], k-1))
	else:
		return (R(S, k-1) + R(S[1:], k-1))*s

def Rpc(S, k):
	N = 10 ** k
	result = 0
	for p in range(1, N):
		digits = [int(d) for d in str(p)]
		if set(digits) == set(S):
			#print (digits)
			#print (S)
			#print (p)
			result += 1
	return result

def f_naif(k):
	N = 10 ** k
	result = 0
	for p in range(1, N):
		for q in range(p+1, N):
			if len(intersect(str(p), str(q))) != 0:
				result += 1
	return result

def intersect(a, b):
	return list(set(a) & set(b))

def F(k):
	result = 0
	for subset in allsubsets(10):
		if len(subset) > 0:
			#if len(subset) == 2:
				#print ("subset = ", subset)
				#print ("T(subset, k) = ", T(list(subset), k))
				#print ("R(subset, k) = ", Rp(list(subset), k))
				#print ()
			result += T(list(subset), k) * Rp(list(subset), k)
	return result

def f(k):
	N = 10**k
	return (F(k) - (N-1))//2

def main(argv):
	k = int(argv[0])
	mod = 1000267129
	print ("Real: ", f(k) % mod)
	#print ("Naif: ", f_naif(k) % mod)
	#print ("Real: ", T([0, 9, 3], 4))
	#print ("Naif: ", Tp([0, 9, 3], 4))


if __name__ == "__main__":
	main(sys.argv[1:])
