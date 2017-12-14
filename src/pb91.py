def gcd(x, y):
	while (y!=0):
		x, y = y, x%y
	return x

def simp(x, y):
	d = gcd(x, y)
	x /= d
	y /= d
	return x, y

def nb(x, y, l):
	slope = simp(y, x)
	if (slope[0] != 0):
		nd = (l-x)/slope[0]
	else:
		nd = 100
	if (slope[1] != 0):
		nr = y/slope[1]
	else:
		return nd
	if (nd > nr):
		return nr
	return nd

x = 500
s = 0
for i in xrange(0, x+1):
	for j in xrange(0, x+1):
		if (i!=0 or j !=0):
			s += nb(i, j, x)
s *= 2
s += x*x
print s
