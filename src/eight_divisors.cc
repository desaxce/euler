#include <primesieve.hpp>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <inttypes.h>
#include <unordered_map>

using namespace std;

vector<long> l;

// For N = 10e12, requires ~60G swap memory (runs in 20 minutes)
long N = 1000000000000L;

// Returns the number of primes below i (using l and dichotomy)
long get(long i) {
	long a = 0;
	long b = l.size()-1;
	
	while (abs(a-b) >1) {
		long c = floor((a+b)/2);
		if (l[c] <= i)
			a = c;
		else
			b = c;
	}
	return a+1;
}

int main() {
    // store the primes below N/6
    primesieve::generate_primes(N/6L, &l);
	cout << "Done generating" << endl;
	
	long result = 0;
	
	// When only one prime:
	result += get(floor(pow(N,1/7.)));
	//cout << "result = " << result << endl;

	// When two primes:
	long q = l[0];
	long i = 0;
	while (N/pow(q,3.)>=l[0]) {
		result += get(floor(N/pow(q,3.)));
		if (q <= floor(N/pow(q,3.)))
			result--;
		q = l[++i];
	}
	//cout << "result = " << result << endl;

	// When three primes:
	q = l[0];
	i = 0;
	while (q <= pow(N, 1/3.)) {
		long j = i+1;
		long r = l[j];
		while (r <= sqrt(N/q)) {
			result+= get(floor(N/(q*r)))-get(r+1);
			r = l[++j];
		}
		q = l[++i];
	}
	cout << "result = " << result+1 << endl;

    return 0;
}
