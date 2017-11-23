f(n) = 
{
	cnt = 0;
	forprime(b = 1, n, 
		b2 = (b+1)^2;
		print(b);
		fordiv(b2, d, 
			b2d = b2/d;
			if (d <=b & b2d-1 <=n  & isprime(d-1) & isprime(b2d-1), 
				/*print(d-1, ", ", b, ", ", (b+1)^2/d-1);*/
				cnt += d-2+b+b2d;
			);
		);
	);
	return (cnt);
}
