from math import sqrt
from sympy.ntheory import totient
from pb643 import totientsum
from pb643 import totientsuma
import pickle

def mod(k):
	return k%1000000007

def sumtot(j):
	result = 0
	for k in range(n//(j+1)+1, n//j +1):
		#result = modf(result+totient(k))
		result = result+totient(k)
	return result

n = 7**13

#print("Preparing totient summatory function")
#PSI = totientsuma(n)
#j = len(PSI)+1
#while j < int(sqrt(n))+2:
#	if j%100==0:
#		print("Processing j = ", j)
#	PSI.append(totientsum(n//j))
#	j+=1
#print("Done with totient sums")

#with open('sumstot.txt', 'wb') as f:
	#pickle.dump(PSI, f)

with open('sumstot.txt', 'rb') as f:
	PSI = pickle.load(f)

#print("Computing L")
L = 1
for j in range(2, int(sqrt(n))+1):
	L = mod(L*mod(int(pow(n//j+1, totient(j), 1000000007))))
#print("L - Part 1 complete")
for j in range(1, int(sqrt(n))+1): # sometimes up to sqrt(n), sometimes just below
	L = mod(L*mod(int(pow(j+1, PSI[j-1]-PSI[j], 1000000007))))
	#L = mod(L*mod(int(pow(j+1, sumtot(j)))))
L = mod(L*(n+1))
#print("L - Part 2 complete")
#print("Done with L")

L8 = mod(int(pow(L, 8)))
L4 = mod(int(pow(L, 4)))

#print("Computing T")
T  = 0
for j in range(2, int(sqrt(n))+1):
	T = mod(T+(2*(n//j)*L4 - (n//j)*(n//j))*totient(j))
for j in range(1, int(sqrt(n))+1): # sometimes up to sqrt(n), sometimes just below
	T = mod(T+(2*j*L4 - j*j)*(PSI[j-1]-PSI[j]))
	#T = mod(T+(2*j*L4 - j*j)*sumtot(j))
T = mod(T+2*n*L4-n*n)
#print("Done with T")

print(mod(L8 - 4*T -1))

