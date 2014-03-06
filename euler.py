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

    chaine = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450"

    a=chaine[[[[




