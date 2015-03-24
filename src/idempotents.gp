maximum(v, n)=
{
	local(i, j, res, resultat);
	resultat = 0;
	for (i=0, 2^(matsize(v)[2])-1,
		res = 0;
		for (j=0, matsize(v)[2]-1,
			res+=v[j+1]*bitand(2^j, i)/(2^j);
		);
		res = res%n;
		if (res > resultat,
			resultat = res;
		);
	);
	return (resultat);
}

M(n)=
{
	local(a, p, ni, nic, i);
	p = factor(n); 
	v = vector(matsize(p)[1]);
	for(i=1, matsize(p)[1],
		ni=(p[i,1])^(p[i,2]);
		nic=n/ni;
		v[i] = nic*lift((Mod(nic, ni))^(-1));
	);
	return (maximum(v, n));
}

sig(n)=
{
	local(result, i);
	result = 0; \\ on compte directement le cas i = 1
	for (i=1, n,
		result+=M(i);
	);
	return (result);
}
