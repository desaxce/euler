P(f, r)=
{
	local (result);
	\\ I had forgotten the first line which must be initialized separately!
	if (f==1,
		return (r*(r+1)\2);
	);
	if (r==1,
		return ((f^2)\2);
	,
		if (r==2,
			if (f%2==1,
				return (P(f, 1)+1);
			,
				return (2*(f\2+1)^2-1);
			);
		, 
			if (r%2==0,
				if (f%2==1,
					return (P(f+2*(r\2-1), 2)+r\2-1);
				,
					return (P(f+2*(r\2-1), 2)-r\2+1);
				)
			,
				if (f%2==0,
					return (P(f+2*(r\2), 1)+r\2);
				,
					return (P(f+2*(r\2), 1)-r\2);
				);
			);
		);
	);

	return (result);
}

pb_359()=
{
	local(N, listdiv, i, f, r, result, modulo);
	modulo = 10^8;
	result = Mod(0, modulo);
	N = 71328803586048;
	listdiv = divisors(N);
	for (i=1, matsize(listdiv)[2],
		f = listdiv[i];
		r = N/f;
		result = Mod(result+P(f, r), modulo);
	);
	return (result);
}
