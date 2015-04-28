g(n)=
{
	local(tmp);
	if (n==4,
		return (13);
	);
	tmp = g(n-1);
	return (tmp+gcd(n, tmp));
}
