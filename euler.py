from math import sqrt
import rlcompleter, readline
readline.parse_and_bind('tab:complete')

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

def factor(n):
    primes=[]
    for i in xrange(2, int(sqrt(n)+1)):
        while n%i==0:
            primes.extend([i])
            n/=i
    if n!=1:
        primes.append(n)
    return primes

def palindrome():
    a=0
    for i in xrange(9, 0, -1):
        for j in xrange(9, -1, -1):
            for k in xrange(9, -1, -1):
                a=i*(10**5+1)+j*(10**4+10)+k*1100
                primes=factor(a)
                div=primes[len(primes)-1]
                if div<1000:
                    for index in xrange(len(primes)-1, -1, -1):
                        while (div*primes[index]<1000):
                            div=div*primes[index]
                    if a/div<1000:
                        return a

def gcd(a, b):
    r=a
    u=1
    v=0
    rp=b
    up=0
    vp=1
    while rp!=0:
        q=r//rp
        r, u, v, rp, up, vp = rp, up, vp, r-q*rp, u-q*up, v-q*vp
    return [r, u, v]

def lcm(a, b):
    return a*b/gcd(a, b)[0]

def smallest_multiple(n):
    result=1
    for i in xrange(1, n+1):
        result=lcm(result, i)
    return result

def sum_square_difference(n):
    return ((n**2)*((n+1)**2))/4-n*(n+1)*(2*n+1)/6

def is_prime(n):
    if n==1:
        return False
    if n==2:
        return True
    elif n%2==0:
        return False
    i=3
    range = int(sqrt(n))+1
    while i<range:
        if n%i==0:
            return False
        i+=1
    return True

def prime(n):
    i, j = 1, 3
    while i < n:
        if is_prime(j):
            i+=1
        j+=2
    return j-2

def largest_product():
    f=open('digits', 'r')
    chaine=""
    for line in f:
        chaine+=line
        chaine=chaine.rstrip('\n')
    l=list(chaine)
    cnt=5
    a, b, c, d, e = int(l[0]), int(l[1]), int(l[2]), int(l[3]), int(l[4])
    max_digits=[a, b, c, d, e]
    resultat=a*b*c*d*e
    while cnt<len(l):
        a, b, c, d, e = b, c, d, e, int(l[cnt])
        if a*b*c*d*e > resultat:
            max_digits = [a, b, c, d, e] 
            resultat=a*b*c*d*e
        cnt+=1
    return resultat, max_digits

def pythagorean_triplet():
    for a in xrange(1, 1000):
        for b in xrange(a+1, 1000):
            if sqrt(a**2+b**2)==int(sqrt(a**2+b**2)):
                if a+b+int(sqrt(a**2+b**2))==1000:
                    return a, b, int(sqrt(a**2+b**2))

def sum_primes(n):
    resultat=2
    i=3
    while i<n:
        if is_prime(i):
            resultat+=i
        i+=2
    return resultat
