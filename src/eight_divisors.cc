#include <primesieve.hpp>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <inttypes.h>
#include <unordered_map>

using namespace std;

unordered_map<uint64_t, uint64_t> p;

int N = 1000000;

// Special structure to avoid storing the value for every integer
uint64_t get(uint64_t i) {
	while (p.find(i)==p.end()) {
		--i;
	}
	return p[i];
}

int main()
{
    // store the primes below 1000000
    std::vector<int> l;
    primesieve::generate_primes(N, &l);

    primesieve::iterator pi;
    uint64_t prime;
	uint64_t count = 0;
	int result = 0;

    // iterate over the primes below 10^9
    while ((prime = pi.next_prime()) < 1000000) {
		p[prime] = ++count;
	}
	
	//printf("%" PRIu64 "\n", l[0]);

	// When only one prime:
	result += get(floor(pow(N,1/7.)));

	// When two primes:
	int q = l[0];
	int i = 0;
	while (N/pow(q,3.)>=2) {
		result += get(floor(N/pow(q,3.)));
		q = l[++i];
	}

	// When three primes:
	q = l[0];
	i = 0;
	while (q < pow(N, 1/2.)) {
		int j = i+1;
		int r = l[j];
		while (r < pow(N, 1/2)) {
			result += get(floor(N/(q*r)));
			r = l[++j];
		}
		q = l[++i];
	}

	printf("%d\n", result);
    return 0;
}
