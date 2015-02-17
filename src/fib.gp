dsum(n)=
{
	s = 0;
	while(n,
		s+=n%10;
		n\=10;
	);
	return (s);
}
check(n)=
{
	x = vector(9);
	for(i=1,
	9,
		x[i] = n%10;
		n\= 10;
	);
	if(vecsort(x)==[1,2,3,4,5,6,7,8,9],
		return (1);
	);
	return (0);
}

find()=
{
	i = 1;
	while(1,
		n = fibonacci(i);
		high = floor(n/(10^(floor(log(n)/log(10))-8)));
		low = n%1000000000;
		if(check(high)==1 && check(low)==1,
			return(i);
		);
		i = i+1;
	);
}
