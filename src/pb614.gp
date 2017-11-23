/* Modular exponentiation using repeated squaring. */
/* That is, we want to compute a^b mod n. */
modexp(a, b, n)=
{
	local(d, bin);
	d = 1;
	bin = binary(b);
	for (i = 1, length(bin),
		d = Mod(d*d, n);
		if (bin[i]==1,
			d = Mod(d*a, n);
		);
	);
	return (d);
}

pb()=
{
	\\ Initialization
	N = 500500;
	modulo = 500500507;
	result = Mod(1, modulo);
	p = primes(N);

	\\ First start with a number which possess 2^N divisors
	for (i=1,
	N,
		result = result * Mod(p[i], modulo);
	);
	\\print(result);
	j = N;
	q = floor(sqrt(p[j]));
	\\print(q);
	\\print();
	while (q > 0,
		if (isprime(q)==1,
			k = floor(log(log(p[j])/log(q))/log(2));
			\\print(q);
			\\print(k);
			\\print();
			while (k > 0,
				result /= p[j];
				result *= modexp(q, 2^k, modulo);
				j = j-1;
				k = k-1;
			);
		);
		q = q-1;
	);
	return (lift(result));
}

nn = 10000000;
qq = vector(nn+1);

modu = 1000000007;

compute_q_up_to_naif(n) = {
	qq = vector(n+1);
	se = prod(i = 1, n, (1+x^i));
	for (i = 0, n, 
		qq[i+1] = polcoeff(se, i);
	);
}

q(n) = 
{
	if (n <= 1, 
		return (1);
	);

	if (qq[n] != 0, 
		return (qq[n]);
	);

	qq[n] = sum(k = 1, n, Mod(q(n-k)*sum_odd(k), modu))/Mod(n, modu);
	return (qq[n]);
}

/*compute_q_up_to(400);*/
q_naif(n) = 
{
	return (qq[n+1]);
}

s(n) = 
{
	return (polcoeff(prod(k = 0, n, (1+x^(2*k+1))), n));
}

q_tres_naif(n) = 
{
	return (polcoeff(prod(i = 1, n, (1+x^i)), n));
}

p_naif(n) = 
{
	return (polcoeff(prod(i = 0, floor(n/2), (1+x^(2*i+1)))*prod(i=1, floor(n/4), (1+x^(4*i))), n));
}

sumodd = vector(nn+1);
sum_odd(n) = 
{
	if (sumodd[n] != 0, 
		return (sumodd[n]);
	);

	resultat = 0;
	fordiv(n, i, 
		if (i%2 == 1, 
			resultat = Mod(resultat+i, modu);
		);
	);
	sumodd[n] = resultat;
	return (sumodd[n]);
}

pp = vector(nn+1);

/*p_mod(n) = 
{
	return (p(n)%(10^9+7));
}*/

p(n) = 
{
	if (n <= 1, 
		return (1);
	);

	if (pp[n] != 0, 
		return (pp[n]);
	);

	pp[n] = sum(k = 0, floor(n/4), Mod(q(k)*q(n-4*k), modu)) - sum(k = 1, floor(n/2), Mod(q(k)*p(n-2*k), modu));

	/*pp[n] = q(0)*q(n)+sum(k=1, floor(n/4), q(k)*(q(n-4*k)-p(n-2*k)))-sum(k = floor(n/4)+1, floor(n/2), q(k)*p(n-2*k));*/

	return (pp[n]);
}
