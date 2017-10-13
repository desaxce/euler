import sys

from math import floor
from math import log
from math import sqrt

T1 = []
T3 = []
N = 5

s3 = []
s1 = []

class Bidule:
	current = 0
	index = 0
	contientUnImpair = 0
	pariteSomme = 0
	pariteSeul = 0
	firstTime = 0

	def __init__(self, current, index, contientUnImpair, pariteSomme, pariteSeul, firstTime):
		self.current = current
		self.index = index
		self.contientUnImpair = contientUnImpair
		self.pariteSomme = pariteSomme
		self.pariteSeul = pariteSeul
		self.firstTime = firstTime

	def display(self):
		print ("current = ", self.current)
		print ("index = ", self.index)
		print ("contientUnImpair = ", self.contientUnImpair)
		print ("pariteSomme = ", self.pariteSomme)
		print ("pariteSeul = ", self.pariteSeul)
		print ("firstTime = ", self.firstTime)
		print ("\n")

def initialize(n):
	nn = floor(sqrt(n))+1
	out = list()
	sieve = [True] * (nn+1)
	for p in range(2, nn+1):
		if sieve[p]:
			out.append(p)
			for i in range(p, nn+1, p):
				sieve[i] = False
	for p in out:
		if p%4==1:
			T1.append(p)
		elif p%4 == 3:
			T3.append(p)
 
def count_p(a, b):
	result = 0
	nn = N
	out = list()
	sieve = [True] * (nn+1)
	for p in range(2, nn+1):
		if sieve[p]:
			out.append(p)
			for i in range(p, nn+1, p):
				sieve[i] = False
	for p in out:
		if p%4 == 1 and p>=a and p<=b:
			print("a = ", a, ", b = ", b, ", p = ", p)
			result+=1
	return result

def S1():
	result = 0
	while len(s1) != 0:
		bid = s1.pop()
		current = bid.current
		index = bid.index
		contientUnImpair = bid.contientUnImpair
		pariteSomme = bid.pariteSomme
		pariteSeul = bid.pariteSeul
		firstTime = bid.firstTime

		if index < len(T1):
			#bid.display()
			if contientUnImpair != 0:
				temp = current * (T1[index]**2)
				if temp > N:
					if (pariteSeul+1)%2 == 1:
						print(current)
					result += (pariteSeul +1)%2
				else:
					s1.append(Bidule(current, index+1, contientUnImpair, pariteSomme, pariteSeul, 0))
					if contientUnImpair == T1[index]:
						pariteSeul = (pariteSeul+1)%2
					s1.append(Bidule(temp, index, contientUnImpair, pariteSomme, pariteSeul, 0))
			else:
				temp1 = current * T1[index]
				if temp1 > N:
					if (pariteSomme+1)%2 == 1:
						print(current)
					result += (pariteSomme+1)%2
				else:
					if firstTime == 1:
						#print("index = ", index)
						#print ("T1[index] = ", T1[index])
						#print (len(s1))
						s1.append(Bidule(temp1, index, T1[index], pariteSomme, pariteSeul, 0))
						#print (len(s1))
						#s1[0].display()
					temp2 = temp1 * T1[index]
					if temp2 > N:
						s1.append(Bidule(current, index+1, 0, pariteSomme, pariteSeul, 1))
					else:
						s1.append(Bidule(temp2, index, 0, (pariteSomme+1)%2, pariteSeul, 0))
						s1.append(Bidule(current, index+1, 0, pariteSomme, pariteSeul, 1))
	return result

def S3():
	result = 0
	while len(s3) != 0:
		current, index = s3.pop()

		if index >= len(T3):
			s1.append(Bidule(current, 0, 0, 1, 0, 1))
			result += S1()
		else:
			temp = current * (T3[index] **2)
			if temp > N:
				s1.append(Bidule(current, 0, 0, 1, 0, 1))
				result += S1()
			else:
				s3.append([temp, index])
				s3.append([current, index+1])
	return result

def sol():
	somme = 0
	for k in range(floor(log(N)/log(2))+1):
		#print(k)
		s3.append([2**k, 0])
		somme += S3()
	return somme

		
def main(argv):
	global N, T1, T3
	N = int(argv[0])
	initialize(N)
	#print (T1)
	#print (T3)
	result = sol()
	print("sans les gros nombres premiers = ", result)
	for ss in [1, 2, 4, 8]:
		result += count_p(floor(sqrt(N)), floor(N/ss));
	print ("avec les gros nombres premiers = ", result)
	

if __name__ == "__main__":
	main(sys.argv[1:])
