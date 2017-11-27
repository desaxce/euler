nb_dioph_sol_naif(n, chift) = {
	facs = factor(n);
	ss = matsize(facs)[1];

	m = 1;
	for (i = 1, ss, 
		if (facs[i, 1]%4==3, 
			if (facs[i, 2]%2 != 0, 
				return (0);
			);
		);
		if (facs[i, 1]%4==1, 
			m *= (facs[i, 2]+1);
		);
	);
	if (m%2 == 0, 
		if ((m/2)%2 == 1, 
			return ((chift+1)%2);, 
			return (chift%2);
		);, 
		if (((m+1)/2)%2 == 1, 
			return ((chift+1)%2);, 
			return (chift%2);
		);
	);
}

sol_naif(N) = {
	somme = 0;
	for (i = 1, N, 
		israc = 0;
		israc2 = 0;
		rac = floor(sqrt(i));
		rac2 = floor(sqrt(i/2.));
		if (rac*rac == i, 
			israc = 1;
		);
		if (rac2*rac2 == i/2, 
			israc2 = 1;
		);
		temp = nb_dioph_sol_naif(i, israc+israc2);
		somme += temp;
	);
	return (somme);
}
