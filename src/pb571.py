from gmpy2 import *
import itertools
import string

def ispandigital(x, b):
	s = digits(x, b)
	for i in range(0, b):
		if str(i) not in s:
			return False
	return True

def isnsuperpandigital(x, n):
	for b in range(n, 1, -1):
		if not ispandigital(x, b):
			return False
	return True

def findsmallest10superpandigital():
	chiffres = list('1023456789')

	permut = itertools.permutations(chiffres)
	result = 0
	cnt = 0
	for perm in permut:
		x = int(''.join(list(perm)), 10)
		if isnsuperpandigital(x, 10):
			print (x)
			result += x
			cnt += 1
			if cnt == 10:
				break

	print(result)

def findsmallest11superpandigital():
	chiffres = list('1023456789a')

	permut = itertools.permutations(chiffres)
	result = 0
	cnt = 0
	for perm in permut:
		#print (perm)
		x = int(''.join(list(perm)), 11)
		if isnsuperpandigital(x, 11):
			print (perm)
			print (x)
			result += x
			cnt += 1
			if cnt == 10:
				break
	print (result)

def findsmallest12superpandigital():
	chiffres = list('0123456789ab')

	permut = itertools.permutations(chiffres)
	result = 0
	cnt = 0
	for perm in permut:
		print (perm)
		x = int(''.join(list(perm)), 12)
		if isnsuperpandigital(x, 12):
			print (x)
			result += x
			cnt += 1
			if cnt == 10:
				break
	print (result)

findsmallest10superpandigital()
#findsmallest11superpandigital()
#findsmallest12superpandigital()

