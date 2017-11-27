index = 1

next2(n,j)=
{
	local(increment);
	increment = 1;
	while(floor(n/index)==j,
		index+=increment;
		if(floor(n/(index-1))<j,
			index-=increment;
			increment = 1;
		,
			increment *= 2;
		);
	);
	return (floor(n/index));
}

sum_square(n)=
{
	return (n*(n+1)*(2*n+1)/6);
}

sigma2(n)=
{
	local(result, j, up, lo);
	result = 0;
	j = n;
	while (j>0,
		up = floor(n/j);
		lo = floor(n/(j+1))+1;
		result += j*(sum_square(up)-sum_square(lo-1));
		j = next2(n, j);
	);

	return (result);
}
