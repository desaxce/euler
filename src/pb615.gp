bidu(n) = 
{
	i = 1;
	cnt = 0;
	while (cnt <= n, 
		if (bigomega(i) > n-1, 
			print1(i);
			print1(" --> ");
			facs = factor(i);
			for (j = 1, matsize(facs)[1], 
				for (k = 1, facs[j,2], 
					print1(facs[j,1]);
					print1(" ");
				);
			);
			print();
			cnt = cnt+1;
		);
		i = i+1;
	);
}
