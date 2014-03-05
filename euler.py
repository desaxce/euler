from math import sqrt

def sum(n):
    return n*(n+1)/2

def number_multiples(n):
    return sum(n//5)*5 + sum(n//3)*3 - sum(n//15)*15

def even_sum_fibonacci(n):
    resultat=2
    a=1
    b=2
    c=a+b
    while c<n:
        if c%2==0:
            resultat+=c
        a=b
        b=c
        c=a+b
    return resultat

def biggest_prime_factor(n):
    primes=[]
    for i in xrange(2, int(sqrt(n)+1)):
        while n%i==0:
            if n==i:
                return i
            primes.extend([i])
            n/=i
    return n
