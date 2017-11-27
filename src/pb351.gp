hidden_points(n)=
{
	local (result);
	result = sum(k=2, n, k-eulerphi(k));
	result *= 6;

	return (result);
}

