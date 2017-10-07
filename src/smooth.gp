/*toto = vector(81);
cnt1 = 1;*/

initialize(n) = {
	cnt = 0;

	for (i = 0, floor(log(n-1)/log(2)), for (j = 0, floor(log((n-1)/(2^i))/log(3)), for (k = 0, floor(log((n-1)/(2^i*3^j))/log(5)), if (isprime(2^i*3^j*5^k + 1), cnt+=1;););););

	v = vector(cnt);
	cnt = 0;

	for (i = 0, floor(log(n-1)/log(2)), for (j = 0, floor(log((n-1)/(2^i))/log(3)), for (k = 0, floor(log((n-1)/(2^i*3^j))/log(5)), if (isprime(2^i*3^j*5^k + 1), cnt+=1; v[cnt] = 2^i*3^j*5^k+1;););););

	v = vecsort(v);
}

S2(current, index, n) = {
	if (index > cnt, 
		return (current);
	);
	if (current*v[index] <= n, 
		return (S2(current*v[index], index+1, n)+ S2(current, index+1, n)), 
		/*toto[cnt1] = current;
		cnt1 += 1;*/
		return (current);
	);
}

S(n) = {
	initialize(n);
	somme = 0;
	for (i = 0, floor(log(n)/log(2)), for (j = 0, floor(log(n/(2^i))/log(3)), for (k = 0, floor(log(n/(2^i*3^j))/log(5)), 
		somme = somme+S2(2^i*3^j*5^k, 4, n);
	);););
	return (somme % (2^32));
}

