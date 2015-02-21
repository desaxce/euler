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
