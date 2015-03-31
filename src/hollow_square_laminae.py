count = 0
N = 1000000
i = 1

while True:
	nmax = i+int(N/(4*i))
	nmin = 2*i+1
	if (nmax >= nmin):
		count += nmax-nmin+1
	else:
		break
	i+=1

print count
