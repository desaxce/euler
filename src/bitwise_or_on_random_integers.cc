#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

long long N = 100;
int nb_bits = 32;

int main() {
	long double result = 0;
	long double current = 0;

	for (long long n = 1; n < N; ++n) {
		long double r = pow(1-1.0/pow(2, n), nb_bits);
		result += n*(r-current);
		current = r;
	} 
	printf("Expected value of N = %0.11Lf\n", result);
	return 0;
}

