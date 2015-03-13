M(n,k)=
{
	local(j, result);
	result = 0;
	for (j=n, n+k-1,
		if (numdiv(j) > result,
			result = numdiv(j);
		);
	);
	return (result);
}

S(u,k)=
{
	local(n, result);
	result = 0;
	for (n=1, u-k+1,
		result+=M(n,k);
	);
	return (result);
}
