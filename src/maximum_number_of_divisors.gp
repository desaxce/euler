N = 1000000;
v = vector(N);

M(n,k)=
{
	local(j, result);
	result = 0;
	for (j=n, n+k-1,
		if (v[j] > result,
			result = v[j];
		);
	);
	return (result);
}

S(u,k)=
{
	local(n, result, i);
	for (i = 1, N, 
		v[i] = numdiv(i);
	);
	result = 0;
	for (n=1, u-k+1,
		result+=M(n,k);
	);
	return (result);
}
