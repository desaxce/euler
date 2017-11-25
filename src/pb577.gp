N = 12345;
H = vector(N);
H[3] = 1;

g(n) = 
{
	if (H[n] != 0, 
		return (H[n]);
	);

	nsur3 = floor(n/3);
	H[n] = (nsur3*(nsur3+1)*(n-2*nsur3)/2 + g(n-1));
	return (H[n]);
}

g(N);

sum(i = 3, N, g(i))

