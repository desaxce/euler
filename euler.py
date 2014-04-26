from math import *
from itertools import *
from collections import Counter
from decimal import *
import rlcompleter, readline

readline.parse_and_bind('tab:complete')

"""Global variable used to memoize the size of the Collatz sequences"""
global_collatz = [0 for i in xrange(1000001)]
global_collatz[1]=1

"""Global variable used to memoize the computations in lattices"""
global_lattices = [ [0 for i in xrange(21)] for j in xrange(21)]

"""Global variable used to read the pyramid"""
f=open("triangle.txt")
matrix = [[int(x) for x in line.split()] for line in f]
mem = [[0 for i in xrange(len(matrix))] for j in xrange(len(matrix))]
mem[0][0]=matrix[0][0]

global_array_89 = [0 for i in xrange(1000)]

def sum_to(n):
    return n*(n+1)/2

def number_multiples(n):
    return sum_to(n//5)*5 + sum_to(n//3)*3 - sum_to(n//15)*15

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

def pandigital_products():
    from math import log
    numbers=[]
    cnt=0
    for i in xrange(1, 10000):
        for j in xrange(1, 10**(4-int(log(i)/log(10)))):
            k=i*j
            l=list(str(i))
            l.extend(list(str(j)))
            l.extend(list(str(k)))
            if '0' not in l and len(l)==9 and len(set(l))==9 and k not in numbers:
                cnt+=k
                numbers.append(k)
                print i, j, k
    return cnt

def digit_cancelling_fractions():
    array=[]
    for i in xrange(10, 100):
        for j in xrange(i+1, 100):
            l=list(str(i))
            l.extend(list(str(j)))
            common=list(set(list(str(i))) & set(list(str(j))))
            if '0' in common:
                common.remove('0')
            if len(set(l))<=3 and len(common)>=1:
                li=list(str(i))
                lj=list(str(j))
                li.remove(common[0])
                lj.remove(common[0])
                if int(lj[0])!=0 and i*1.0/j==int(li[0])*1.0/int(lj[0]):
                    array.append([i, j])
    return array

global_fac_array=[1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]

def fac(n):
    global global_fac_array
    resultat=0
    for d in list(str(n)):
        resultat+=global_fac_array[int(d)]
    return resultat


def digit_factorials():
    resultat=0
    for i in xrange(100000):
        if i==fac(i):
            resultat+=i
    return resultat-1-2

def rotate(l, n):
    return l[n:]+l[:n]

def circular_primes():
    """On compte le nombre premier 2 des le depart"""
    cnt=1 
    for i in xrange(1000000):
        if is_prime(i):
            l=list(str(i))
            if '0' not in l and '2' not in l and '4' not in l and '6' not in l and '8' not in l:
                is_circular=1
                for j in xrange(len(l)):
                    if not is_prime(int(''.join(rotate(l, j)))):
                        is_circular*=0
                cnt+=is_circular
    return cnt

def is_palindromic_base_ten(j):
    """
    Uncomment if you want to count palindromes with leading zeros
    if j%10==0:
        return is_palindromic_base_ten(j//10)"""
    l=list(str(j))
    for i in xrange(len(l)//2):
        if l[i]!=l[len(l)-i-1]:
            return False
    return True

def is_palindromic_base_two(j):
    """
    Uncomment if you want to count palindromes with leading zeros
    if j%2==0:
        return is_palindromic_base_two(j//2)"""
    l=list(bin(j).lstrip('0b'))
    for i in xrange(len(l)//2):
        if l[i]!=l[len(l)-i-1]:
            return False
    return True

def double_base_palindromes():
    cnt=0
    for i in xrange(1, 1000000):
        if is_palindromic_base_ten(i) and is_palindromic_base_two(i):
            cnt+=i
    return cnt

def is_a_truncatable_prime(n):
    if is_prime(n):
        l=list(str(n))
        for i in xrange(1, len(l)):
            if not is_prime(int("".join(l[i:len(l)]))):
                return False
            if not is_prime(int("".join(l[0:i]))):
                return False
        return True
    else:
        return False

def truncatable_primes():
    i=10
    somme=0
    while len(a)!=11:
        if is_a_truncatable_prime(i):
            somme+=i
        i+=1
    return somme

def pandigital_multiples():
    resultat=0
    for i in xrange(10000):
        l=[]
        j=1
        while len(l)<9 and len(l)==len(set(l)) and not '0' in l:
            l.extend(list(str(i*j)))
            j+=1
        if len(set(l))==9 and not '0' in l:
            resultat+=1
            print i
    return resultat

def integer_right_triangles():
    array=[0 for i in xrange(1001)]
    resultat=0
    index=0
    for p in xrange(1001):
        for a in xrange(p//2+1):
            ac=a**2
            for b in xrange(p-2*a+1):
                c=sqrt(ac+b**2)
                if a+b+c==p:
                    array[p]+=1
        if resultat<array[p]:
            resultat=array[p]
            index=p
    return index

def nth_digit_champernowne(n):
    somme=0
    k=0
    while somme < n:
        somme+=(k+1)*9*10**k
        k+=1
    somme-=k*9*10**(k-1)
    n-=somme
    k-=1
    nombre=10**k+(n//(k+1))
    n-=(n//(k+1))*(k+1)
    return int(list(str(nombre))[n-1])


def champernownes_constant():
    resultat=1
    for i in xrange(1, 7):
        resultat*=nth_digit_champernowne(10**i)
    return resultat

def pandigital_prime():
    resultat=0
    from itertools import permutations
    array=list(permutations(['1', '2', '3', '4', '5', '6', '7'])) 
    for s in array:
        i=int(''.join(s))
        if is_prime(i):
            if i>resultat:
                resultat=i
            print i
    return resultat 

def coded_triangle_numbers():
    cnt=0
    array=[n*(n+1)/2 for n in xrange(200)]
    f=open('words.txt', 'r')
    line=f.readline()
    words=line.split('","')
    words[0]=words[0].lstrip('\"')
    words[len(words)-1]=words[len(words)-1].rstrip('\"')
    for w in words:
        somme=0
        for c in list(w):
            somme+=ord(c)-64
        if somme in array:
            cnt+=1
    return cnt 

def sub_string_divisibility():
    somme=0
    from itertools import permutations
    array=list(permutations(['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'])) 
    liste=[2, 3, 5, 7, 11, 13, 17]
    """0 should not be in first position"""
    """for p in array:
        if p[0]=='0':
            array.remove(p)
    print 'OK'"""
    for p in array:
        b=1
        for j in xrange(2, 9):
            if int(''.join(p[j-1:j+2]))%liste[j-2]!=0:
                b*=0
        if b==1:
            somme+=int(''.join(p))
            print int(''.join(p))
    return somme

def triangular_pentagonal_and_hexagonal():
    triangle=[n*(n+1)/2 for n in xrange(100000)]
    pentagonal=[n*(3*n-1)/2 for n in xrange(57735)]
    hexagonal=[n*(2*n-1) for n in xrange(50000)]
    for i in hexagonal:
        if i in pentagonal and i in triangle:
            print i

def pentagon_numbers():
    pentagonal=[n*(3*n-1)/2 for n in xrange(1, 1000)]

def is_consecutive(i, j):
    l=list(set(factor(i)))
    m=list(set(factor(j)))
    if len(list(set(l) - set(m)))>3 and len(list(set(l)|set(m)))>len(l)+3:
        return True
    return False

def distinct_primes_factors():
    for i in xrange(100000, 1000000):
        if is_consecutive(i, i+1) and is_consecutive(i+1, i+2) and is_consecutive(i+2, i+3):
            print i, i+1, i+2, i+3

def prime_permutations():
    for i in xrange(1000, 10000):
        if is_prime(i):
            for j in xrange(1, (10000-i)/2+1):
                if is_prime(i+j) and is_prime(i+2*j):
                    if set(list(str(i)))==set(list(str(i+j))) and set(list(str(i)))==set(list(str(i+2*j))):
                        print i, i+j, i+2*j

def consecutive_prime_sum():
    primes=[]
    for i in xrange(100000):
        if is_prime(i):
            primes.append(i)
   
    resultat=0
    p=2
    for j in xrange(len(primes)):
        somme=primes[j]
        i=j+1
        while somme<1000000:
            if is_prime(somme) and resultat<i-j:
                resultat=i-j
                p=somme
                print p
            somme+=primes[i]
            i+=1
    return resultat

def find_subsets(s, m):
    return set(combinations(s, m))

def doublons(l):
    resultat=[]
    if len(l)==len(set(l)):
        return resultat
    else:
        s=list(Counter(l).items()) 
        ls=list(s)
        for e in s:
            if e[1]==1:
                ls.remove(e)
        return ls
        

def prime_digit_replacements(n, r):
    for p in xrange(n):
        if is_prime(p): 
            l=list(str(p))
            db=list(Counter(l).items())
            for s in db:
                for j in xrange(1, s[1]+1):
                    for perm in list(find_subsets(set([i for i, x in enumerate(l) if x==s[0]]), j)):
                        if (0) in perm:
                            i=1
                            cnt=1
                        else:
                            cnt=0
                            i=0
                        while i<10 and cnt<r:
                            ls=list(l)
                            for m in perm:
                                ls[m]=str(i)
                            op=int(''.join(ls))
                            if not is_prime(op):
                                cnt+=1
                            i+=1
                        if cnt<r:
                            print p, perm
                            return p
                                
def permuted_multiples():
    for i in xrange(7):
        for j in xrange(10**i, (10**(i+1))/6+1):
            l=list(str(j))
            l2=list(str(2*j))
            l3=list(str(3*j))
            l4=list(str(4*j))
            l5=list(str(5*j))
            l6=list(str(6*j))
            l.sort()
            l2.sort()
            l3.sort()
            l4.sort()
            l5.sort()
            l6.sort()
            if l==l2 and l==l3 and l==l4 and l==l5 and l==l6:
                return j

def combinatoric_selections(n):
    from scipy import misc
    cnt=0
    for i in xrange(101):
        for j in xrange(i+1):
            if misc.comb(i, j)>n:
                cnt+=1
    return cnt

def is_89(n):
    global global_array_89
    if n<len(global_array_89) and global_array_89[n]!=0:
        return (global_array_89[n]==-1)
    else:
        l=list(str(n))
        square=0
        for s in l:
            square+=int(s)**2
        if square==1:
            if n<len(global_array_89):
                global_array_89[n]=1
            return False
        elif square in [89, 145, 42, 20, 4, 16, 37, 58]:
            if n<len(global_array_89):
                global_array_89[n]=-1
            return True
        else:
            f=is_89(square)
            if n<len(global_array_89):  
                if f:
                    global_array_89[n]=-1
                else:
                    global_array_89[n]=1
            return f

def square_digit_chains():
    cnt=0
    global global_array_89
    for i in xrange(1, 1000):
        is_89(i)
    for i in xrange(1, 10000000):
        if i%100000==0:
            print i, cnt
        l=list(str(i))
        square=0
        for s in l:
            square+=int(s)**2
        if global_array_89[square]==-1:
            cnt+=1
    return cnt

ohash=dict({})

def f(n):
    if n==1 or n==3:
        return n
    elif n in ohash:
        return ohash[n]
    elif n%2==0:
        e=f(n/2)
    elif n%4==1:
        k=(n-1)/4
        e=2*f(2*k+1) -f(k)
    elif n%4==3:
        k=(n-3)/4
        e=3*f(2*k+1) -2*f(k)
    ohash[n]=e
    return e

hashmap=dict({})

def S(n):
    global hashmap
    if n==1:
        return 1
    elif n==2:
        return 2
    elif n==3:
        return 5
    elif n in hashmap:
        return hashmap[n]
    else:
        if n%4==0:
            k=n/4
            e=6*S(2*k+1) -8*S(k) -f(4*k+2)-f(4*k+3) -f(4*k+1)-1
        elif n%4==1:
            k=(n-1)/4
            e=6*S(2*k+1) -8*S(k) -f(4*k+2)-f(4*k+3)-1
        elif n%4==2:
            k=(n-2)/4
            e=6*S(2*k+1) -8*S(k) -f(4*k+3)-1
        elif n%4==3:
            k=(n-3)/4
            e=6*S(2*k+1) -8*S(k)-1
        hashmap[n]=e
        return e

def suits(g):
    return list(set([str(s)[1:] for s in g]))

def value(s):
    v=str(s)[:-1]
    if v=='A':
        return 14
    elif v=='K':
        return 13
    elif v=='Q':
        return 12
    elif v=='J':
        return 11
    elif v=='T':
        return 10
    else:
        return int(v)


def high_card(g):
    highest_value=0
    index=0
    for s in g:
        t=value(s)
        if t>highest_value:
            highest_value=t
            index=s
    return index

def is_one_pair(g):
    r=[value(c) for c in g]
    db=doublons(r)
    cnt=0
    for d in db:
        if d[1]==2:
            return True
    return False

def is_two_pairs(g):
    r=[value(c) for c in g]
    db=doublons(r)
    cnt=0
    for d in db:
        if d[1]==2:
            cnt+=1
    return (cnt==2)

def is_three_of_a_kind(g):
    r=[value(c) for c in g]
    db=doublons(r)
    for d in db:
        if d[1]==3:
            return True
    return False
    

def is_straight(g):
    r=[value(c) for c in g]
    for i in xrange(2, 11):
        l=[i+j for j in xrange(5)]
        if set(r)==set(l):
            return True
    return False

def is_flush(g):
    if len(suits(g))==1:
        return True
    return False

def is_full_house(g):
    l=[value(c) for c in g]
    if len(set(l))>2:
        return False
    else:
        if len(doublons(l))==2:
            return True
        return False


def is_four_of_a_kind(g):
    l=[value(c) for c in g]
    if len(set(l))>2:
        return False
    else:
        if len(doublons(l))==1:
            return True
        return False

def is_straight_flush(g):
    if is_flush(g) and is_straight(g):
        return True
    return False

def is_royal_flush(g):
    if not is_flush(g):
        return False
    else:
        r=[value(c) for c in g]
        if set(r)==set([10, 11, 12, 13, 14, 15]):
            return True
        return False

def what_is(g):
    if is_royal_flush(g):
        return 10
    elif is_straight_flush(g):
        return 9
    elif is_four_of_a_kind(g):
        return 8
    elif is_full_house(g):
        return 7
    elif is_flush(g):
        return 6
    elif is_straight(g):
        return 5
    elif is_three_of_a_kind(g):
        return 4
    elif is_two_pairs(g):
        return 3
    elif is_one_pair(g):
        return 2
    else:
        return 1

def is_superior(g, h, n):
    if n==1:
        c_g=high_card(g)
        c_h=high_card(h)
        if value(c_g)>value(c_h):
            return 1
        elif value(c_g)==value(c_h):
            g.remove(c_g)
            h.remove(c_h)
            return is_superior(g, h, 1)
        return 0
    elif n==2:
        l_g=[value(c) for c in g]
        l_h=[value(c) for c in h]
        db_g=doublons(l_g)
        db_h=doublons(l_h)
        if db_g[0][0]>db_h[0][0]:
            return 1
        elif db_g[0][0]==db_h[0][0]:
            gs=list(g)
            for c in g:
                if value(c)==db_g[0][0]:
                    gs.remove(c)
            hs=list(h)
            for c in h:
                if value(c)==db_h[0][0]:
                    hs.remove(c)
            return is_superior(gs, hs, 1)
        return 0
    elif n==3:
        l_g=[value(c) for c in g]
        l_h=[value(c) for c in h]
        db_g=doublons(l_g)
        db_h=doublons(l_h)
        m_g=max(db_g[0][0], db_g[1][0])
        m_h=max(db_h[0][0], db_h[1][0])
        min_g=min(db_g[0][0], db_g[1][0])
        min_h=min(db_h[0][0], db_h[1][0])
        
        if m_g>m_h:
            return 1
        elif m_g<m_h:
            return 0
        elif m_g==m_h:
            if min_g>min_h:
                return 1
            elif min_g<min_h:
                return 0
            elif min_g==min_h:
                gs=list(g)
                for c in g:
                    if value(c)==m_g or value(c)==min_g:
                        gs.remove(c)
                hs=list(h)
                for c in h:
                    if value(c)==m_h or value(c)==min_h:
                        hs.remove(c)
                return is_superior(gs, hs, 1)
    elif n==4:
        l_g=[value(c) for c in g]
        l_h=[value(c) for c in h]
        db_g=doublons(l_g)
        db_h=doublons(l_h)
        if db_g[0][0]>db_h[0][0]:
            return 1
        elif db_g[0][0]==db_h[0][0]:
            gs=list(g)
            for c in g:
                if value(c)==db_g[0][0]:
                    gs.remove(c)
            hs=list(h)
            for c in h:
                if value(c)==db_h[0][0]:
                    hs.remove(c)
            return is_superior(gs, hs, 1)
        return 0
    elif n==5:
        return is_superior(g, h, 1)
    """TODO:Il y a d'autres cas a prendre en compte!!!"""

        

        

def poker_hands():
    f=open('poker.txt', 'r')
    hands=[f.readline()[:-1].split(' ') for i in xrange(1000)]
    hands_1=[[h[i] for i in xrange(5)] for h in hands]
    hands_2=[[h[i] for i in xrange(5, 10)] for h in hands]
    cnt=0
    for i in xrange(len(hands_1)):
        wi_1=what_is(hands_1[i])
        wi_2=what_is(hands_2[i])
        if wi_1>wi_2:
            cnt+=1
        elif wi_1==wi_2:
            cnt+=is_superior(hands_1[i], hands_2[i], wi_1)
    return cnt

def reverse_and_add(n):
    l=list(str(n))
    return n+int(''.join(l[::-1]))

def is_a_lychrel_number(n):
    a=0
    while a<50:
        n=reverse_and_add(n)
        if is_palindromic_base_ten(n):
            return False
        a+=1
    return True

def lychrel_numbers(n):
    cnt=0
    for i in xrange(n):
        if is_a_lychrel_number(i):
            cnt+=1
    return cnt

def digits_sum(n):
    resultat=0
    for s in list(str(n)):
        resultat+=int(s)
    return resultat

def powerful_digit_sum(n):
    resultat=0
    for a in xrange(0, n):
        for b in xrange(0, n):
            c=digits_sum(a**b)
            if c>resultat:
                resultat=c
    return resultat 

def reduce(a, b):
    d=gcd(abs(a), abs(b))[0]
    return [a/d, b/d]

global_array_fractions_development_two=[[] for i in xrange(1000)]
global_array_fractions_development_two[0]=[2, 1]

def fractions_development_two(n):
    global global_array_fractions_development_two
    if len(global_array_fractions_development_two[n])!=0:
        return global_array_fractions_development_two[n]
    else:
        s=fractions_development_two(n-1)
        t=[2*s[0]+s[1], s[0]]
        global_array_fractions_development_two[n]=t
        return t

def square_root_convergents():
    global global_array_fractions_development_two
    cnt=0
    fractions_development_two(999)
    array=[reduce(x[0]+x[1], x[0]) for x in global_array_fractions_development_two]
    for c in array:
        if int(log(c[0])/log(10))>int(log(c[1])/log(10)):
            cnt+=1
    return cnt
    return 0 

def spiral_primes():
    resultat=0
    l=[]
    p=[]
    ls=[]
    index=1
    i=1
    while True:
        ls=[]
        ls.append(index+i+1)
        ls.append(index+2*(i+1))
        ls.append(index+3*(i+1))
        ls.append(index+4*(i+1))

        for x in ls:
            if is_prime(x):
                p.append(x)
            else:
                l.append(x)
        if len(p)*1.0/(len(l)+len(p))<0.1:
            return i
        index+=4*(i+1)
        i+=2

def is_prime_pair(n, m):
    ns=list(n)
    ns.extend(m)
    nm=int(''.join(ns))
    if not is_prime(nm):
        return False
    ms=list(m)
    ms.extend(n)
    mn=int(''.join(ms))
    if not is_prime(mn):
        return False
    return True
    
def prime_pair_sets():
    primes=[]
    cnt=0
    for i in xrange(10000):
        if is_prime(i):
            primes.append(list(str(i)))
    for i in primes:
        print int(''.join(i))
        for j in primes[primes.index(i):]:
            if is_prime_pair(i, j):
                for k in primes[primes.index(j)+1:]:
                    if is_prime_pair(i, k) and is_prime_pair(j, k):
                        for l in primes[primes.index(k)+1:]:
                            if is_prime_pair(i, l) and is_prime_pair(j, l) and is_prime_pair(k, l):
                                for m in primes[primes.index(l)+1:]:
                                    if is_prime_pair(i, m) and is_prime_pair(j, m) and is_prime_pair(k, m) and is_prime_pair(l, m):
                                        print int(''.join(i)), int(''.join(j)), int(''.join(k)),  int(''.join(l)), int(''.join(m))

def cyclical_figurate_numbers():

    triangle=[n*(n+1)/2 for n in xrange(45, 141)]
    square=[n**2 for n in xrange(32, 100)]
    pentagonal=[n*(3*n-1)/2 for n in xrange(26, 82)]
    hexagonal=[n*(2*n-1) for n in xrange(23, 71)]
    heptagonal=[n*(5*n-3)/2 for n in xrange(21, 64)]
    octagonal=[n*(3*n-2) for n in xrange(19, 59)]

    total=[triangle, square, pentagonal, hexagonal, heptagonal, octagonal]
    for tot in list(permutations(total)): 
        for t in tot[0]:
            for s in tot[1]:
                lt=list(str(t))
                ls=list(str(s))
                if lt[2:4]==ls[0:2]:
                    for p in tot[2]:
                        ps=list(str(p))
                        if ls[2:4]==ps[0:2]:
                            for hexa in tot[3]:
                                hexas=list(str(hexa))
                                if ps[2:4]==hexas[0:2]:
                                    for hepta in tot[4]:
                                        heptas=list(str(hepta))
                                        if hexas[2:4]==heptas[0:2]:
                                            for o in tot[5]:
                                                os=list(str(o))
                                                if heptas[2:4]==os[0:2] and os[2:4]==lt[0:2]:
                                                    return t+s+p+hexa+hepta+o

def is_same_digits(a, b):
    db_a=list(Counter(list(str(a))).items())
    db_b=list(Counter(list(str(b))).items())
    db_a.sort()
    db_b.sort()
    return db_a==db_b

def cubic_permutations():
    cubes=[i**3 for i in xrange(1, 100000)]
    for c in cubes:
        db_c=list(Counter(list(str(c))).items())
        db_c.sort()
        for d in cubes[cubes.index(c)+1: int(pow(10**(len(str(c))), 1.0/3))+1]:
            db_d=list(Counter(list(str(d))).items())
            db_d.sort()
            if db_c==db_d: 
                for e in cubes[cubes.index(d)+1: int(pow(10**(len(str(c))), 1.0/3))+1]:
                    db_e=list(Counter(list(str(e))).items())
                    db_e.sort() 
                    if db_e==db_c:
                        for f in cubes[cubes.index(e)+1: int(pow(10**(len(str(c))), 1.0/3))+1]:
                            db_f=list(Counter(list(str(f))).items())
                            db_f.sort() 
                            if db_f==db_c:
                                for g in cubes[cubes.index(f)+1: int(pow(10**(len(str(c))), 1.0/3))+1]:
                                    db_g=list(Counter(list(str(g))).items())
                                    db_g.sort() 
                                    if db_g==db_c:
                                        print c, d, e, f, g

def powerful_digit_counts():
    cnt=0
    for i in xrange(1, 100):
        a=0
        while len(str(a**i))<=i:
            a+=1
            if len(str(a**i))==i:
                print a**i, i
                cnt+=1
    return cnt


def fraction_development_root(n):
    resultat=[0, []]
    l=[]
    first=[[1, 1], [0, 1]]
    current=[[], []]
    current[0]=list(first[0])
    current[1]=list(first[1])
    e=int(sqrt(n)*first[0][0]*1.0/first[0][1]+1.0*first[1][0]/first[1][1])
    current[1][0]-=current[1][1]*e
    resultat[0]=e

    a_1=current[0][0]
    a_2=current[0][1]
    b_1=current[1][0]
    b_2=current[1][1]
    current[0]=reduce(a_1*a_2**2*b_2**2, a_2*(a_1**2*b_2**2*n-a_2**2*b_1**2))
    current[1]=reduce(b_1*a_2**2*b_2**2, -b_2*(a_1**2*b_2**2*n-a_2**2*b_1**2))
    first[0]=list(current[0])
    first[1]=list(current[1])
    e=int(sqrt(n)*current[0][0]*1.0/current[0][1]+1.0*current[1][0]/current[1][1])
    l.append(e)
    current[1][0]-=current[1][1]*e
    a_1=current[0][0]
    a_2=current[0][1]
    b_1=current[1][0]
    b_2=current[1][1]
    current[0]=reduce(a_1*a_2**2*b_2**2, a_2*(a_1**2*b_2**2*n-a_2**2*b_1**2))
    current[1]=reduce(b_1*a_2**2*b_2**2, -b_2*(a_1**2*b_2**2*n-a_2**2*b_1**2))
    while current[0][0]*1.0/current[0][1]!=1.0*first[0][0]/first[0][1] or current[1][0]*1.0/current[1][1]!=1.0*first[1][0]/first[1][1]:
        e=int(sqrt(n)*current[0][0]*1.0/current[0][1]+1.0*current[1][0]/current[1][1])
        l.append(e)
        current[1][0]-=current[1][1]*e
        a_1=current[0][0]
        a_2=current[0][1]
        b_1=current[1][0]
        b_2=current[1][1]
        current[0]=reduce(a_1*a_2**2*b_2**2, a_2*(a_1**2*b_2**2*n-a_2**2*b_1**2))
        current[1]=reduce(b_1*a_2**2*b_2**2, -b_2*(a_1**2*b_2**2*n-a_2**2*b_1**2))

    resultat[1]=l 
    return resultat

def odd_period_square_roots():
    cnt=0
    squares=[n**2 for n in xrange(101)]
    for n in xrange(10001):
        if not n in squares and len(fraction_development_root(n)[1])%2==1:
            cnt+=1
    return cnt

global_array_fraction_development_e=[[] for i in xrange(101)]
global_array_fraction_development_e[0]=[2, 1]
frac_dev_e=[]

def fraction_development_e(n):
    global global_array_fraction_development_e
    global frac_dev_e
    if len(global_array_fraction_development_e[n])!=0:
        return global_array_fraction_development_e[n]
    else:
        s=fraction_development_e(n-1)
        t=[frac_dev_e[n-1]*s[0]+s[1], s[0]]
        global_array_fraction_development_e[n]=t
        return t

def convergents_of_e():
    global frac_dev_e 
    global global_array_fraction_development_e 
    for k in xrange(1, 36):
        frac_dev_e.extend([1, 2*k, 1])
    fraction_development_e(99)
    l=global_array_fraction_development_e[99]
    s=list(str(reduce(l[0], l[1])[0]))
    somme=0
    for x in s:
        somme+=int(x)
    return somme

def convergs_gen(qgen, pgen=repeat(1)):
    Np, Dp, N, D, = 0, 1, 1, 0
    for q, p in izip(qgen, pgen):
        Np, Dp, N, D = N, D, p*Np+q*N, p*Dp+q*D
        yield N, D

def e_gen():
    def e_qgen():
        yield 2
        for k in count(1):
            yield 1
            yield 2*k
            yield 1
    return convergs_gen(e_qgen())

def any_gen(l):
    m=len(l[1])-1
    def any_qgen():
        yield l[0]
        for k in count(1):
            yield l[1][(k-1)%m]
    return convergs_gen(any_qgen())

def p65(n):
    N, D = islice(e_gen(), n-1, n).next()
    return sum(imap(int, str(N)))

def any_p65(l, n):
    N, D = islice(any_gen(l), n-1, n).next()
    return N, D

def diophantine_equation():
    resultat=5
    x=9
    for i in xrange(2, 1001):
        if int(sqrt(i))!=sqrt(i):
            l=fraction_development_root(i)
            m=len(l[1])
            if m%2==1:
                xs=any_p65(l, 2*m-1)
            else:
                xs=any_p65(l, m-1)
            if xs[0]>x:
                resultat=i
                x=xs[0]
    return resultat, x


def max_path(i, j):
    global matrix
    if mem[i][j]!=0:
        return mem[i][j]
    elif j==0:
        mem[i][j]=matrix[i][j]+max_path(i-1, j)
        return mem[i][j]
    elif j==len(matrix[i])-1:
        mem[i][j]=matrix[i][j]+max_path(i-1, j-1)
        return mem[i][j]
    else:
        mem[i][j]=matrix[i][j]+max(max_path(i-1, j-1), max_path(i-1, j))
        return mem[i][j]
        

def maximum_path_sum_2():
    global matrix
    size = len(matrix[len(matrix)-1])
    resultat=0
    for i in xrange(size):
        s=max_path(size-1, i)
        if resultat<s:
            resultat=s
    return resultat

def totient_maximum():
    a=2
    i=2
    resultat=1
    while a<=1000000:
        resultat*=1.0*i/(i-1)
        i+=1
        while not is_prime(i):
            i+=1
        a*=i
    return resultat, a/i

def magic_5_gon_ring():
    l=set([i for i in xrange(1, 11)])
    l.discard(10)
    for a in xrange(13, 17):
        for a1 in xrange(1, 10):
            for a2 in xrange(1, 10):
                if a2!=a1 and a1+a2+10==a:
                    for a3 in xrange(1, 10):
                        if a3 not in [a1, a2]:
                            for a4 in xrange(1, 10):
                                if a4 not in [a1, a2, a3]:
                                    for a5 in xrange(1, 10):
                                        if a5 not in [a1, a2, a3, a4]:
                                            ls=set(l)
                                            ls.discard(a1)
                                            ls.discard(a2)
                                            ls.discard(a3)
                                            ls.discard(a4)
                                            ls.discard(a5)
                                            ls.discard(a-(a2+a3))
                                            ls.discard(a-(a3+a4))
                                            ls.discard(a-(a4+a5))
                                            ls.discard(a-(a5+a1))
                                            if len(ls)==0:
                                                print a, a1, a2, a3, a4, a5
                                                print a, a-(a1+a2), a-(a2+a3), a-(a3+a4), a-(a4+a5), a-(a5+a1)

def totient_function(n):
    factors=factor_concat(n)
    resultat=1
    for f in factors:
        resultat*=f[0]**f[1] -f[0]**(f[1]-1) 
    return resultat

def totient_permutation():
    primes=[]
    l=[i for i in xrange(10000)]
    for p in l:
        if is_prime(p):
            primes.append(p)
    print "done"
    n=1
    ratio=2
    for i in primes:
        for j in primes[primes.index(i):10**7]:
            c=i*j
            if c<10**7:
                phi=totient_function(c)
                if ''.join(sorted(list(str(phi))))==''.join(sorted(list(str(c)))):
                    if i==2609 and j==2693:
                        print c, c*1.0/phi

                    if c*1.0/phi<ratio:
                        n=c
                        ratio=c*1.0/phi
                        print c, ratio
    return n, ratio

def ordered_fractions():
    l=[]
    for d in xrange(2, 1000001):
        print d
        for n in xrange(max(1, int(0.42856*d)), max(1, int(0.42859*d))):
            if gcd(d, n)[0]==1:
                l.append(n*1.0/d)
    l.append(3*1.0/7)
    l.sort()
    i=l.index(3*1.0/7)-1
    print i
    print l[i]
    for d in xrange(2, 1000001):
        for n in xrange(max(1, int(0.42857*d)), max(1, int(0.42858*d))):
            if n*1.0/d==l[i]:
                return n, d

def counting_fractions():
    """Using PARI/GP and taylor!"""
    return 303963552391 

def counting_fractions_in_a_range(s):
    l=[]
    cnt=0
    for d in xrange(2, s+1):
        for n in xrange(max(1, int(d/3)), int(d/2)+1):
            if gcd(d, n)[0]==1 and n*1.0/d<1/2.0 and n*1.0/d>1/3.0:
                cnt+=1
    return cnt 

def is_sixty_factorial_chain(n):
    l=[]
    s=n
    l.append(s)
    while len(l)<=60:
        s=sum(imap(factorial, list(imap(int, list(str(s))))))
        if s in l and len(l)==60:
            return True
        elif s in l and len(l)!=60:
            return False
        l.append(s)
    return False
            


def digit_factorial_chains():
    s=set([i for i in xrange(10**6)])
    cnt=0
    for i in s:
        if is_sixty_factorial_chain(i):
            print i
            cnt+=1
    return cnt  

global_mobius=[2 for i in xrange(20000001)]
global_mobius[1]=1

def fill_mobius(n):
    s=set([i for i in xrange(2, n+1)])
    global global_mobius
    l=[2*i+1 for i in xrange(n/2)]
    primes=[2]
    for p in l:
        if p%100000==0:
            print p
        if is_prime(p):
            primes.append(p)
    print "done priming"

    for i in xrange(2, n+1): 
        if i in s:
            a=0
            while i%primes[a]!=0:
                a+=1
            p=primes[a]

            if (i/p)%p==0:
                global_mobius[i]==0
            else:
                global_mobius[i]=-global_mobius[i/p]

def main():
    somme=0
    for i in xrange(20000000):
        somme+=moebius(i)
    print somme

def build_primes(n):
    a=1
    cnt=0
    result=[]
    while cnt<n:
        a+=1
        while is_prime(a)==False:
            a+=1
        result.append(a)
        cnt+=1
    return result

def build_composites(n):
    a=1
    cnt=0
    result=[]
    while cnt<n:
        a+=1
        while is_prime(a)==True:
            a+=1
        result.append(a)
        cnt+=1
    return result

def digital_roots(n):
    result=0
    for digit in list(str(n)):
        result+=int(digit)
    while result>9:
        result=digital_roots(result)
    return result

def cant_find(l, x):
    if x not in l:
        return True
    return False

def find_when(l, x):
    return l.index(x)+1


def superinteger(n):
    p=build_primes(n)
    c=build_composites(n)
    p=map(digital_roots, p)
    c=map(digital_roots, c)
    print p
    print c

    result=""
    i1=0
    i2=0

    while i1<n and i2<n:
        a=p[i1]
        b=c[i2]

        if a==b:
            i1+=1
            i2+=1
            result+=str(p[i1])
        else:
            if cant_find(c[i2:], a) and cant_find(p[i1:], b):
                if a<b:
                    while i1<n:
                        result+=str(p[i1])
                        i1+=1
                    while i2<n:
                        result+=str(c[i2])
                        i2+=1
                elif a>b:
                    while i2<n:
                        result+=str(c[i2])
                        i2+=1
                    while i1<n:
                        result+=str(p[i1])
                        i1+=1
                    
                return result
            
            if cant_find(c[i2:], a):
                fwb=find_when(p[i1:], b)
                result+=''.join(map(str, p[i1:i1+fwb]))
                i1+=fwb
                i2+=1

            elif cant_find(p[i1:], b):
                fwa=find_when(c[i2:], a)
                result+=''.join(map(str, c[i2:i2+fwa]))
                i2+=fwa
                i1+=1
            else:
                
            
                fwa=find_when(c[i2:], a)
                fwb=find_when(p[i1:], b)
                if fwa<fwb:
                    result+=''.join(map(str, c[i2:i2+fwa]))
                    i2+=fwa
                    i1+=1
                if fwb<fwa:
                    result+=''.join(map(str, p[i1:i1+fwb]))
                    i1+=fwb
                    i2+=1
                if fwa==fwb:
                    if a<b:
                        result+=''.join(map(str, p[i1:i1+fwb]))
                        i1+=fwb
                        i2+=1
                    if b<a:
                        result+=''.join(map(str, c[i2:i2+fwa]))
                        i2+=fwa
                        i1+=1
    print i1
    print i2
    if i2==n:
        while i1<n:
            result+=str(p[i1])
            i1+=1
    if i1==n:
        while i2<n:
            result+=str(c[i2])
            i2+=1

    return result
