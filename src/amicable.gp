sumdi(m)=
{
	local(d, result);
	result = 0;
	d = divisors(m);
	for (i=1,matsize(d)[2],
		result += d[i];
	);
	return (result-m);
}

lenami(n)=
{
	local(m, result);
	m = n;
	result = 0;
	m = sumdi(m);
	while (result < 100 & m<=1000000 & m!=n,
		result = result+1;
		m = sumdi(m);
	);
	if(result==100 | m > 1000000,
		return (-1);
	);
	return (result+1);
}

find(n)=
{
	local(index, result);
	result = 0;
	index = 0;
	for (i=2, n,
		if (result < lenami(i),
			result = lenami(i);
			index = i;
		);
	);
	return (index);
}

