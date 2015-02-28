M(n)=
{
	local(a, result);
	result = 1;
	for(a=n/2-1,n-1,
		if (Mod(a^2,n)==Mod(a,n),
			result = a;
		);
	);
	return (result);
}
