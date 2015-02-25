#include <primesieve.hpp>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <inttypes.h>

using namespace std;

vector<long> l;

long N = 100000000L;

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
    // store the primes below N
    primesieve::generate_primes(N, &l);
	cout << "Done generating" << endl;
	
	long result = 0;

	for (int i = 0; i <= get(floor(sqrt(N))); ++i) {
		if (get(N/l[i]) > get(l[i])-1) {
			result += get(N/l[i]) - get(l[i]) + 1;
			//cout << "get(" << N/l[i] << ") = " << get(N/l[i]) << endl;
		}
	}
	
	cout << result << endl;
    return 0;
}
