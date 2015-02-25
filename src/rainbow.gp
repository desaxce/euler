nombre(k, n)=
{
	if (k==0,
		return (2);
	);
	result = 0;
	for(i1=1, n1,
		n2 = min(10, n1-i1+1);
		result += (binomial(10,i1)*nombre(k-1, n2));
	);
	return (result);
}

rainbow()=
{
	\\ expected number of colors
	result = 0;

	for (k=2,
	7,
		result = result+k*binomial(7, k)*nombre(k,20);
	);
	return (result/binomial(70,20));
}
