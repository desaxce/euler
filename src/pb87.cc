#include <iostream>
#include <deque>
#include <math.h>
#include <cmath>
#include <set>

using namespace std;

long N = 50000000L;
long max_p = 100000L;

deque<long> primes(max_p);
set<long> prime_power_triples;

void sieve() {
	primes[0] = 0;
	primes[1] = 0;
	for (long i = 2; i < max_p; ++i) {
		primes[i] = 1;
	}
	for (long i = 2; i <= sqrt(max_p); ++i) {
		if (primes[i] == 1) {
			for (long k = 2*i; k < max_p; k+=i) {
				primes[k] = 0;
			}
		}
	}
}

int main() {
	// Initializing prime numbers with Eratosthene's sieve
	sieve();

	for (long i = 2; pow(i,4) < N; ++i) {
		if (primes[i]==1) {
			for (long k = 2; pow(k, 3)+pow(i,4) < N; ++k) {
				if (primes[k]==1) {
					long r;
					for (long j = 2; (r=pow(j, 2)+pow(k, 3)+pow(i, 4)) < N; ++j) {
						if (primes[j]==1) {
							prime_power_triples.insert(r);
						}
					}
				}
			}
		}
	}
	cout << "There are " << prime_power_triples.size() << " prime power triples below " << N << "." << endl;
	return 0;
}
