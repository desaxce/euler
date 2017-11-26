M(p, q, N)=
{
	local(ep,eq,result);
	ep=floor(log(N/q)/log(p));
	result = (p^ep)*q;
	for (eq=1, floor(log(N/p)/log(q)),
		ep=floor(log(N/(q^eq))/log(p));
		if (result<(p^ep)*(q^eq),
			result = (p^ep)*(q^eq);
		);
	);
	return (result);
}

S(N)=
{
	local(result, p, i, j);
	result = 0;
	p = primes(N);
	i = 1;
	while(p[i]<sqrt(N),
		j = i+1;
		while (p[j]<=N/p[i],
			result += M(p[i],p[j],N);
			j += 1;
		);
		i += 1;
	);
	return (result);
}
