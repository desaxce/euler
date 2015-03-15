#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

unsigned long long N = 1e15L;
unsigned long long modulo = 1e9;
unsigned long long index = 1;

unsigned long long next1(unsigned long long n, unsigned long long j) {
	while (floor(n/index)==j) {
		index++;
	}
	//cout << "next(" << n << ", " << floor(n/index) << ") = ";
	//cout << index << " " << endl;
	return floor(n/index);
}

unsigned long long next(unsigned long long n, unsigned long long j) {
	unsigned long long increment = 1;
	while (floor(n/index)==j) {
		index += increment;
		if (floor(n/(index-1))<j) {
			index -= increment;
			increment = 1;
		}
		else {
			increment *= 2;
		}
	}
	//cout << "next(" << n << ", " << floor(n/index) << ") = ";
	//cout << index << " " << endl;
	return floor(n/index);
}

unsigned long long sum_square(unsigned long long n) {
	return n*(n+1)*(2*n+1)/6;
}

unsigned long long SIGMA2(unsigned long long n) {
    unsigned long long result = 0;
	unsigned long long j = n;
	
	do {
		unsigned long long up = floor(n/j);
		unsigned long long lo = floor(n/(j+1))+1;
		result += j*(sum_square(up)-sum_square(lo-1));
		j = next(n, j);
    } while (j > 0);

    return result;
}

int main() {
	unsigned long long i = 6;
	for (i = 1; i < 7; ++i) {
		index = 1L;
		printf("SIGMA2(%llu) = %llu\n", i, SIGMA2(i)); 
	}
	i = N;
	printf("SIGMA2(%llu) = %llu\n", i, SIGMA2(i)); 
    return 0;
}

