first(n)=
{
	local(i, N, p);
	N = 100000;
	p = primes(N);
	i = 1;
	while ((2*i*p[i])%(p[i]^2) < n,
		i += 2;
	);
	return (i);
}

