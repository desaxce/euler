n_max=1000
memoizer = [[0 for i in xrange(n_max)] for j in xrange(n_max)]

def p_rec(limit, n):
    global memoizer
    if limit==0:
        return 1
    if memoizer[limit][n]!=0:
        return memoizer[limit][n]
    for i in xrange(limit, 0, -1):
        memoizer[limit][n]+=p_rec(limit-i, n-1)
    return memoizer[limit][n]

def p(n):
    # On peut simplifier le probleme de la maniere suivante:
    # il faut trouver toutes les manieres dont on peut ecrire le nombre n
    # en sommant au maximum 5 nombres a1, a2, a3, a4 et a5 avec la regle 
    # a1>=a2>=...>=a1
    return p_rec(n, n)
        
def coin_partitions():
    # Problem 78
    print p(5)
    
