dsum(n)=
{
	s = 0;
	while(n,
		s+=n%10;
		n\=10;
	);
	return (s);
}

is_a_harshad_number(n)=
{
	d = dsum(n);
	if (n%d==0,
		return (1);
	);
	return (0);
}

is_a_right_truncatable_harshad_number(n)=
{
	while(n!=0 & is_a_harshad_number(n),
		n\=10;
	);
	if (n==0,
		return (1);
	);
	return (0);
}

is_a_strong_harshad_number(n)=
{
	d = dsum(n);
	if (n!=0 & n%d==0 & isprime(n/d)==1,
		return (1);
	);
	return (0);
}

is_a_strong_right_truncatable_harshad_prime(n)=
{
	if (isprime(n)==1,
		n\=10;
		if (is_a_strong_harshad_number(n)==1 & is_a_right_truncatable_harshad_number(n)==1,
			return (1);
		);
	);
	return (0);
}

sum_harshad(n)=
{
	result = 0;
	for(i=1,
	n,
		if(is_a_strong_right_truncatable_harshad_prime(i)==1,
			result = result + i;
		);
	);
	return (result);
}
