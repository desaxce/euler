from math import sqrt

def is_palindromic(n):
	l = list(str(n))
	return (n==int(''.join(l[::-1])))

N = 1e9
d = dict({})
for s in xrange(2, int(sqrt(N))):
	for c in xrange(2, int(N**(1/3.))):
		n = s*s+c*c*c
		if (is_palindromic(n)):
			if n in d:
				d[n] += 1
			else:
				d[n] = 1

result = 0
for k, v in d.iteritems():
	if v == 4:
		result += k
print result
