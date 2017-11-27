from itertools import combinations
from math import factorial
count = 0L

arr = [0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9]
bigsum = sum(arr)
mylist = []
for perm in combinations(arr, 10):
	a = sum(perm)
	b = bigsum - a
	if (a - b) % 11 == 0 and sorted(perm) not in mylist:
		mylist.append(sorted(perm))
		count +=  len([x for x in perm if x != 0]) * factorial(len(perm)-1) * factorial(len(perm)) / 2**(2*(len(perm)-len(set(perm))))

print count 
