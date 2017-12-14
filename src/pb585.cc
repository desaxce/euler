#include "pe.h"

ll quadruplet(ll n) {
	ll result = 0;
	primesieve::iterator it3;
	uint64_t p3 = it3.next_prime();

	while (n >= 5*(p3+1)) {
		primesieve::iterator it1;
		uint64_t p1 = it1.next_prime();
		while (p1*(p3+1) <= n) {
			primesieve::iterator it2;
			it2.skipto(p1);
			uint64_t p2 = it2.next_prime();
			while ((p1+p2)*(p3+1) <= n) {
				//cout << "p1 = " << p1 << " and p2 = " << p2 << " and p3 = " << p3 << endl;
				result += 2 * (n / (p3+1) / (p1+p2)); // important to have parentheses around 2nd term
				//cout << "result = " << result << endl;
				p2 = it2.next_prime();
			}
			p1 = it1.next_prime();
		}
		p3 = it3.next_prime();
	}
	return result;
}

ll doubles(ll n) {
	ll result = 0;
	for (ll x = 1; x <= n; x++) {
		for (ll y = x+1; y <=n-x; y++) {
			ll root = sqrt(x*y);
			if (root*root != x*y) {
				result += 1;
			}
		}
	}
	return result;
}

ll F(ll n) {
	cout << "doubles = " <<  doubles(n) << endl;
	cout << "quadruplet = " << quadruplet(n) << endl;
	return doubles(n) + quadruplet(n);
}

int main(int argc, char* argv[]) {
	ll n;
	cin >> n;
	printf("F(%lld) = %lld\n", n, F(n));
	return 0;
}

