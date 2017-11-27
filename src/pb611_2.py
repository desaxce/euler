from bisect import bisect

def prime_sieve(n):
    """
    Efficient prime sieve, due to Robert William Hanks.
    Source: http://stackoverflow.com/a/2068548
    """
    sieve = [True] * (n/2)
    for i in xrange(3,int(n**0.5)+1,2):
        if sieve[i/2]:
            sieve[i*i/2::i] = [False] * ((n-i*i-1)/(2*i)+1)
    return [2] + [2*i+1 for i in xrange(1,n/2) if sieve[i]]

"""
Limit controls the number of primes that are sieved
to cache small values of pi(x).  Without caching,
runtime will be exponential.
When computing pi(x), limit should be
at least sqrt(x).  A higher value of limit
that caches more values can sometimes improve performance.
"""

limit = 10**6
primes = prime_sieve(limit)

def prime_sieve(n, l):
	result = []
	for p in primes:
		if p%4 == l:
			result.append(p)
	return result

primesmod = [[0], prime_sieve(limit, 1), [0], prime_sieve(limit, 3)]

print 'done with primes'

phi_cache = {}
def phi(x, a):
    """
    Implementation of the partial sieve function, which
    counts the number of integers <= x with no prime factor less
    than or equal to the ath prime.
    """
    # If value is cached, just return it
    if (x, a) in phi_cache: return phi_cache[(x, a)]

    # Base case: phi(x, a) is the number of odd integers <= x
    if a == 1: return (x + 1) / 2

    result = phi(x, a-1) - phi(x / primes[a-1], a-1)
    phi_cache[(x, a)] = result # Memoize
    return result

phi_cachemod = {}
def phimod(x, a, l):
	"""
	Implementation of the partial sieve function, which 
	counts the number of integers n <= x with:
		- no prime factor less than or equal to the ath prime
		- n%4 = l
	"""
	# If value is cached, just return it
	if (x, a, l) in phi_cachemod: return phi_cachemod[(x, a, l)]
	
	#Base case: phi(x, a, l) is computable easily
	if a == 1:
		if l == 1:
			return (x-1)/4+1
		elif l == 3:
			return (x+1)/4
	
	result = phimod(x, a-1, l) - phimod(x / primes[a-1], a-1, (l*primes[a-1])%4)
	phi_cachemod[(x, a, l)] = result # Memoize
	return result


pi_cache = {}
def pi(x):
    """
    Computes pi(x), the number of primes <= x, using
    the Meissel-Lehmer algorithm.
    """
    # If value is cached, return it
    if x in pi_cache: return pi_cache[x]

    # If x < limit, calculate pi(x) using a bisection
    # algorithm over the sieved primes.
    if x < limit:
        result = bisect(primes, x)
        pi_cache[x] = result
        return result

    a = pi(int(x ** (1./4)))
    b = pi(int(x ** (1./2)))
    c = pi(int(x ** (1./3)))

    # This quantity must be integral,
    # so we can just use integer division.
    result = phi(x,a) + (b+a-2) * (b-a+1) / 2

    for i in xrange(a+1, b+1):
        w = x / primes[i-1]
        b_i = pi(w ** (1./2))
        result = result - pi(w)
        if i <= c:
            for j in xrange(i, b_i+1):
                result = result - pi(w / primes[j-1]) + j - 1
    pi_cache[x] = result
    return result

pi_cache_mod = {}
def pimod(x, l):
    """
    Computes pi(x, l), the number of primes n <= x such that
    n = l mod 4, using the Meissel-Lehmer algorithm.
    """
    # If value is cached, return it
    if (x, l) in pi_cache_mod: return pi_cache_mod[(x, l)]

    # If x < limit, calculate pi(x, l) using a bisection
    # algorithm over the sieved primes.
    if x < limit:
        result = bisect(primesmod[l], x)
        pi_cache_mod[(x, l)] = result
        return result

	print "Going there"
    a = pi(int(x ** (1./4)))
    b = pi(int(x ** (1./2)))
    c = pi(int(x ** (1./3)))

    # This quantity must be integral,
    # so we can just use integer division.
    result = phimod(x,a,l) + (b+a-2) * (b-a+1) / 2

    for i in xrange(a+1, b+1):
        w = x / primes[i-1]
        b_i = pimod(w ** (1./2), l)
        result = result - pimod(w, (l*primes[i-1])%4)
        if i <= c:
            for j in xrange(i, b_i+1):
                result = result - pimod(w / primes[j-1], (l*primes[j-1])%4) + j - 1
    pi_cache_mod[x] = result
    return result


# Example
N = 10 ** 12
a = pi(int(N ** (1./4)))
result = phimod(N, a, 1)
print result