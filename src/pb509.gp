nb(n, a)=
{
	return (floor(n/(2^a))-floor(n/(2^(a+1))));
}

f(n)=
{
	local(result, limit, a, b, c);
	result = 0;
	limit = floor(log(n)/log(2));
	for (a=0, limit, 
		for(b=0, limit, 
			for(c=0, limit, 
				if (bitxor(a, bitxor(b, c))!=0, 
					result += nb(n, a)*nb(n, b)*nb(n, c);
				);
			);
		);
	);
	return (result);
}
