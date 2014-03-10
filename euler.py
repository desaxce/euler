from math import sqrt
from math import log
import rlcompleter, readline
readline.parse_and_bind('tab:complete')

"""Global variable used to memoize the size of the Collatz sequences"""
global_collatz = [0 for i in xrange(1000001)]
global_collatz[1]=1

"""Global variable used to memoize the computations in lattices"""
global_lattices = [ [0 for i in xrange(21)] for j in xrange(21)]

"""Global variable used to read the pyramid"""
f=open("pyramid.txt")
matrix = [[int(x) for x in line.split()] for line in f]
mem = [[0 for i in xrange(len(matrix))] for j in xrange(len(matrix))]
mem[0][0]=matrix[0][0]

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
    if n>1:
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
    if n<=0:
        return False
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
    f=open('digits.txt', 'r')
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

def largest_product_in_a_grid():
    f=open('matrix.txt', 'r')
    matrix = [[int(x) for x in line.split()] for line in f]
    resultat=0
    for i in xrange(20):
        a, b, c, d = matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][3]
        if a*b*c*d>resultat:
            resultat=a*b*c*d
        for j in xrange(4, 20):
            a, b, c, d = b, c, d, matrix[i][j]
            if a*b*c*d>resultat:
                resultat=a*b*c*d
        a, b, c, d = matrix[0][i], matrix[1][i], matrix[2][i], matrix[3][i]
        if a*b*c*d> resultat: 
            resultat=a*b*c*d
        for j in xrange(4, 20):
            a, b, c, d = b, c, d, matrix[j][i]
            if a*b*c*d>resultat:
                resultat=a*b*c*d

    for i in xrange(17):
        a, b, c, d = matrix[0][i], matrix[1][i+1], matrix[2][i+2], matrix[3][i+3]
        if a*b*c*d>resultat:
            resultat=a*b*c*d
        for j in xrange(4, 20-i):
            a, b, c, d = b, c, d, matrix[j][i+j]
            if a*b*c*d>resultat:
                resultat=a*b*c*d
        a, b, c, d = matrix[i][0], matrix[i+1][1], matrix[i+2][2], matrix[i+3][3]
        if a*b*c*d>resultat:
            resultat=a*b*c*d
        for j in xrange(4, 20-i):
            a, b, c, d = b, c, d, matrix[i+j][j]
            if a*b*c*d>resultat:
                resultat=a*b*c*d

    nmatrix=zip(*matrix[::-1])
    for i in xrange(17):
        a, b, c, d = nmatrix[0][i], nmatrix[1][i+1], nmatrix[2][i+2], nmatrix[3][i+3]
        if a*b*c*d>resultat:
            resultat=a*b*c*d
        for j in xrange(4, 20-i):
            a, b, c, d = b, c, d, nmatrix[j][i+j]
            if a*b*c*d>resultat:
                resultat=a*b*c*d
        a, b, c, d = nmatrix[i][0], nmatrix[i+1][1], nmatrix[i+2][2], nmatrix[i+3][3]
        if a*b*c*d>resultat:
            resultat=a*b*c*d
        for j in xrange(4, 20-i):
            a, b, c, d = b, c, d, nmatrix[i+j][j]
            if a*b*c*d>resultat:
                resultat=a*b*c*d

    return resultat

def factor_concat(n):
    factors=factor(n)
    factors_concat=[]
    size=0
    while size<len(factors):
        a=factors[size]
        cnt=0
        while size<len(factors) and factors[size]==a:
            cnt+=1
            size+=1
        factors_concat.append([a, cnt])
    return factors_concat

def number_of_divisors(n):
    if n==1:
        return 1
    factors=factor_concat(n)
    resultat=1
    for l in factors:
        resultat*=(l[1]+1)
    return resultat

def highly_divisible_triangular_number(n):
    i=1
    while True:
        if number_of_divisors(i*(i+1)/2)>n:
            return i*(i+1)/2
        i+=1

def large_sum():
    f=open('hundred.txt', 'r')
    resultat=0
    for line in f:
       resultat+=int(line) 
    return resultat

def size_collatz_sequence(n):
    global global_collatz
    if n==1:
        return 1

    if n<1000000:
        if global_collatz[n]!=0:
            return global_collatz[n]
        if n%2==0:
            global_collatz[n]=1+size_collatz_sequence(n>>1)
            return global_collatz[n]
        else:
            global_collatz[n]=1+size_collatz_sequence(3*n+1)
            return global_collatz[n]
    else:
        if n%2==0:
            return 1+size_collatz_sequence(n>>1) 
        else:
            return 1+size_collatz_sequence(3*n+1)
        

def longest_collatz_sequence(n):
    maximum=1
    resultat=1
    for i in xrange(1, n):
        l=size_collatz_sequence(i)
        if l>maximum:
            maximum=l
            resultat=i
    return resultat

def lattice_paths(n, m):
    if n==1:
        return m+1
    elif m==1:
        return n+1
    elif global_lattices[n][m]!=0:
        return global_lattices[n][m]
    else:
        global_lattices[n-1][m]=lattice_paths(n-1, m)
        global_lattices[n][m-1]=lattice_paths(n, m-1)
        return global_lattices[n-1][m]+global_lattices[n][m-1]

def word_count():
    t=len("onetwothreefourfivesixseveneightnine")
    s=t+49+67+8*t+9*(49-len("and"))
    return s+(t+9*len("hundred"))+len("onethousand")+9*s+99*9*len("and")+99*(t+63)


def max_path(i, j):
    global matrix
    if mem[i][j]!=0:
        return mem[i][j]
    elif j==0:
        return matrix[i][j]+max_path(i-1, j)
    elif j==len(matrix[i])-1:
        return matrix[i][j]+max_path(i-1, j-1)
    else:
        return matrix[i][j]+max(max_path(i-1, j-1), max_path(i-1, j))
        

def maximum_path_sum_1():
    global matrix
    size = len(matrix[len(matrix)-1])
    resultat=0
    for i in xrange(size):
        s=max_path(size-1, i)
        if resultat<s:
            resultat=s
    return resultat

def thousand_digit_fibonacci_number():
    a = 1
    b = 1
    cnt=2
    while True:
        c = a
        a = b
        b = c+b
        cnt+=1
        if log(b, 10)>=999:
            return cnt

def counting_sundays():
    l=[1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335]
    l_leap=[1, 32, 61, 92, 122, 153, 183, 214, 245, 275, 306, 336]
    resultat=0
    """ 1st of January 1901 is a Tuesday"""
    start=1 
    for i in xrange(1901, 2001):
        if i%4==0:
            s=l_leap
            new=(start+2)%7
        else:
            s=l
            new=(start+1)%7
        for day in s:
            if day%7==(start+2)%7:
                resultat+=1
        start=new
    return resultat

def counting_sundays_2():
    import datetime
    count=0
    for y in range(1901, 2001):
        for m in range(1, 13):
            if datetime.datetime(y, m, 1).weekday()==6:
                count+=1
    return count

def factorial_digit_sum(n):
    from math import factorial
    resultat=0
    a=factorial(n)
    while a!=0:
        resultat+=a%10
        a/=10
    return resultat

def sum_of_divisors(n):
    resultat=0
    for i in xrange(1, n/2+1):
        if n%i==0:
            resultat+=i
    return resultat

def is_amicable(n):
    div_sum=sum_of_divisors(n)
    if div_sum==n:
        return False
    else:
        if sum_of_divisors(div_sum)==n:
            return True
        return False


def amicable_numbers(n):
    resultat=0
    a=2
    while a<n:
        if is_amicable(a):
            resultat+=a
        a+=1
    return resultat

def name_score(s):
    liste=list(s)
    resultat=0
    for letter in liste:
        resultat+=ord(letter)-64
    return resultat

def names_scores():
    f=open('names.txt', 'r')
    line=f.readline()
    names=line.split('","')
    names[0]=names[0].lstrip('\"')
    names[len(names)-1]=names[len(names)-1].rstrip('\"')
    names.sort()
    resultat=0
    cnt=1
    for s in names:
        if s=='COLIN':
            print cnt*name_score(s)
        resultat+=cnt*name_score(s)
        cnt+=1
    return resultat

def is_abundant(n):
    if sum_of_divisors(n)>n:
        return True
    else:
        return False

def non_abundant_sums():
    abundant_numbers=[]
    for i in xrange(1, 28123):
        if is_abundant(i):
            abundant_numbers.append(i)
    resultat=28123*(28123+1)/2
    liste=[0 for i in xrange(28124)]
    for i in abundant_numbers:
        for j in abundant_numbers:
            if i+j<28124 and liste[i+j]==0:
                liste[i+j]=1
                resultat-=i+j
    return resultat

"""TODO:"""
def lexicographic_permutations():
    perms=[]
    perms.sort()
    return perm

def cycle_size(n):
    array=[1]
    start=1
    while len(array)==len(set(array)):
        start=start*10%n
        if start==0:
            return 0
        array.append(start)
    
    doublon=array[len(array)-1]
    for i in xrange(len(array)-1):
        if array[i]==doublon:
            return len(array)-1-i
    return 0

def reciprocal_cycles(n):
    resultat=0
    index=2
    for i in xrange(1, n):
        s=cycle_size(i)
        if s>resultat:
            resultat=s
            index=i
    return index, resultat

def number_of_quadratic_primes(a, b):
    n=0
    while is_prime(n**2+a*n+b):
        n+=1
    return n

def quadratic_primes(n):
    product=0
    k=0
    for a in xrange(-999, 1000):
        for b in xrange(-999, 1000):
            s=number_of_quadratic_primes(a, b)
            if s>k:
                k=s
                product=a*b
    return product

def number_spiral_diagonals():
    resultat=1
    index=1
    for i in xrange(1, 501):
        resultat+=4*index+2*i*10
        index=index+2*i*4
    return resultat

def distinct_powers(n):
    powers=[]
    for a in xrange(2, n+1):
        for b in xrange(2, n+1):
            powers.append(a**b)
    return len(set(powers))

def digit_fifth_powers():
    resultat=0
    for i in xrange(2, 1000000):
        s=list(str(i))
        somme=0
        for digits in s:
            somme+=int(digits)**5
        if somme==i:
            resultat+=i
            print i
    return resultat

global_counter=0

def coin_sums(x, l):
    global global_counter
    if x==0:
        global_counter+=1
    elif len(l)!=0:
        m=max(l)
        lpop=list(l)
        lpop.remove(m)
        for i in xrange(x//m, -1, -1):
            coin_sums(x-i*m, lpop)

def coin_sums_pound():
    global global_counter
    l=[1, 2, 5, 10, 20, 50, 100, 200]
    coin_sums(200, l)
    return global_counter


