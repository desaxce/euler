#include "pe.h"

ll N = 10000000; // 10^7
ll mod = 1000000007; // 10^9+7

vector<ll> pp(N+1, 0);

inline ll modu(ll n, ll m) {
    return ((n % m) + m) % m;
}

inline ll modulo(ll n) {
    return n%1000000007;
}

ll s(ll n) {
    double racine_delta = sqrt(1+4*n);
    ll racine = floor(racine_delta);
    if (abs(racine_delta-racine) < 1e-6) { // we're an integer
		ll m = (-1 + racine)/2;
        return (m%4 == 1 or m%4 == 2)? -1: 1;
    }
    return 0;
}

ll p(ll n) {
    ll temp = s(n);
	for (ll i = 1; 0 <= n-(i*(i+1))/2; i++) {
		if (i%4 == 1 or i%4 == 2) {
			temp = temp + pp[n-(i*(i+1))/2];
		} else {
			temp = temp - pp[n-(i*(i+1))/2];
		}
	}
    pp[n] = modulo(temp);
    return pp[n];
}

int main(int argc, char* argv[]) {
    ll n = atol(argv[1]);
    pp[0] = 1; pp[1] = 1;
	ll somme = pp[1];
	for (ll i = 2; i <= n; i++) {
		if (i%100000 == 0) {
			cout << i << endl;
		}
		somme = modulo(somme+p(i));
	}
	printf("P(%llu) = %llu\n", n, modu(pp[n], mod));
	printf("sigma(P(%llu)) = %llu\n", n, modu(somme, mod));
    return 0;
}

