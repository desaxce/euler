N=500;
seq = ["P", "P", "P", "P", "N", "N", "P", "P", "P", "N", "P", "P", "N", "P", "N"];

nb(i, r)=
{
	local (x);
	if (r==16,
		return (1);
	,
		if (i==1,
			if (seq[r]=="P", \\ 1 n'est pas premier
				x = 1/3;
			,
				x = 2/3;
			);
			return (x*nb(i+1, r+1));
		,
			if (i==N,
				if (seq[r]=="P", \\ N n'est pas premier
					x = 1/3;
				,
					x = 2/3;
				);
				return (x*nb(i-1, r+1));
			,
				if (isprime(i)==0, \\ i n'est pas premier
					if (seq[r]=="P",
						x = 1/3;
					,
						x = 2/3;
					);
				, \\ sinon i est premier
					if (seq[r]=="P",
						x = 2/3;
					,
						x = 1/3;
					);
				);
				return (x*(nb(i-1, r+1)+nb(i+1, r+1))/2); \\ un pas sur la gauche ou un pas sur la droite
			);
		);
	);
			
}

main()=
{
	local(result, i);
	result = 0;
	for (i=1, N, 
		result += nb(i, 1); \\ position i, rang 1
	);
	return (result/N);
}
