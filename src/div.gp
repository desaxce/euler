ppp = 10000;
expo = 30;
dicho = matrix(ppp, expo);

initialize() = {
	for (ii = 2, ppp, 
		if (isprime(ii), 
			for (j = 1, log(100000000)/log(ii)+1,  
				dicho[ii, j] = sss(ii, j);
			);
		);
	);
}

v(p, n) = {
	return (sum(i = 1, floor(log(n)/log(p))+1, floor(n/(p^i))));
}

better_s(p, alpha) = {
	return (dicho[p, alpha]);
}

sss(p, alpha) = {
	a = p;
	b = p^alpha;
	m = floor((a+b)/2.);
	while (a!=b, 
		valu = v(p, m);
		if (valu < alpha, 
			a = m+1;, 
			b = m;
		);
		m = floor((a+b)/2.);
	);
	return (b);
}

sa(n) = {
	result = 0;
	facs = factorint(n);
	ss = matsize(facs)[1];
	if (facs[ss, 1] > 10000, 
		return (facs[ss, 1]);
	);
	for (i = 1, ss, 
		if (result < dicho[facs[i, 1], facs[i, 2]], 
			result = dicho[facs[i, 1], facs[i, 2]];
		);
	);
	return (result);
}

S(n) = {
	somme = 0;
	for (i = 2, n, 
		somme =somme+ sa(i);
	);
	return(somme);
}
