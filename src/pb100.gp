arranged(n)=
{
	i = floor(n/4.);
	j = 4*i;
	x = 1/2+sqrt(1/4+j*(j-1)/2);
	if(frac(x)==0,
		return ([j, x]);
	);

	j = 4*i + 1;
	x = 1/2+sqrt(1/4+j*(j-1)/2);

	while(frac(x)!=0,
		i = i+1;
		j = 4*i;
		x = 1/2+sqrt(1/4+j*(j-1)/2);
		if(frac(x)==0,
			return ([j, x]);
		);
		j = 4*i+1;
		x = 1/2+sqrt(1/4+j*(j-1)/2);
	);
	return ([j, x]);
}
