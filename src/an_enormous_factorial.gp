q = 10^7;
t = vector(q+1);
petit_modulo = 50515093;
p = 61;
grand_modulo = p^10;

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

tn()=
{
	local(s, i);
	s = Mod(290797, petit_modulo);
	t[1] = lift(Mod(lift(s), p));
	for (i=2, q+1,
		s *= s;
		t[i] = lift(Mod(lift(s), p));
	);
}

salve()=
{
	local(result);
	result = Mod(0, grand_modulo);
	tn();
	print ("Done tn()");
	for (k=2, q+1,
		result += t[k]*(modexp(p, k-1, grand_modulo)-1)*(Mod(p-1, grand_modulo)^(-1));
	);
	return (result);
}

