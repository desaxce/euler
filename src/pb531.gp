g(a, n, b, m) = 
{
	pgcd = gcd(n, m);
	
	/* Case there is no solution to the system*/
	if ((b-a) % pgcd != 0, 
		return (0);
	);
	
	mp = m/pgcd;
	np = n/pgcd;
	dp = (b-a)/pgcd;
	

	u = gcdext(np, mp)[1];
	x0 = u*dp;
	xminpos = x0 - floor(x0/mp)*mp;

	return (a+xminpos*n);
}

f(n, m) = 
{
	a = eulerphi(n);
	b = eulerphi(m);
	return (g(a, n, b, m));
}

start = 10^6;
end = start+5000-1;

sum(n = start, end, sum(m = n+1, end, f(n, m););)
