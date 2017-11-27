#include <pe.h>

ll N = 1e9;
ll x = 100;

vector<bool> primes(N+1);
vector<ll> p;

int main() {
	// Generate the primes greater than x
	primesieve::generate_primes(x+1, N, &p);

	for (ll i = 2; i < N+1; ++i) {
		primes[i] = true;
	}
	primes[0] = false; primes[1] = true; // Normally primes[1] = 0 in a classic sieve, but here we need to count one.

	for (ll q : p) { // Kind of a sieve which eliminates all bad primes
		for (ll k=q; k < N+1; k+=q) {
			primes[k] = false;
		}
	}

	ll result = 0; // Sum all the remaining elements
	for (ll i = 0; i < N+1; ++i) {
		if (primes[i])
			result++;
	}
	cout << result << endl;
	return 0;
}
