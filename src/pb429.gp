S(n)=
{
	local(p, i, result);
	p = primes(5761455);
	result = Mod(1, 1000000009);
	for(i=1, 5761455, \\ this value only works for n = 100000000
		e = sum(k=1, log(n)/log(p[i]), floor(n/(p[i]^k)));
		result *= (1+modexp(p[i], 2*e, 1000000009));
	);
	return (result);
}

/* Modular exponentiation using repeated squaring. */
/* That is, we want to compute a^b mod n. */
modexp(a, b, n) = { \
    local(d, bin); \
    d = 1; \
    bin = binary(b); \
    for (i = 1, length(bin), \
        d = Mod(d*d, n); \
        if (bin[i] == 1, \
            d = Mod(d*a, n); \
        ); \
    ); \
    return(d); \
}
