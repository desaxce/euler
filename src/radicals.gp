rad(n)=
{
	result = 1;
	f = factor(n);
	for (i=1,
	matsize(f)[1],
		result = result*f[i,1];
	);
	return (result);
}

find()=
{
	v = matrix(100000,2);
	for (i=1,
	100000,
		v[i,1] = rad(i);
		v[i,2] = i;
	);
	u = vecsort(v~,1);
	return (u[2,10000]);
}
