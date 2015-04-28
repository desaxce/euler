main(n, k)=
{
	local(result, a, b, c, d);
	result = 0;
	for (a=0, n, 
		for (b=0, n/11, 
			for (c=0, n/101, 
				for (d = 0, n/1111, 
					if ((n+a+11*b+101*c+1111*d) % k==0,
						result += 1;
					);
				);
			);
		);
	);
	return (result);
}

