#include <pe.h>

#define ll long long
#define pb push_back

using namespace std;

vector<ll> primes;

vector<ll> factor(ll n) {
	vector<ll> result;
	ll index = 0;
	while (n!=1) {
		if (n%primes[index]==0) {
			ll tmp = 1;
			while (n%primes[index]==0) {
				tmp*=primes[index];
				n/=primes[index];
			}
			result.pb(tmp);
		}
		++index;
	}
	return result;
}

ll modinv(ll a, ll b) {
	ll r = a, rp = b, q;
	ll u = 1, up = 0;
	ll rs, us;
	while (rp!=0) {
		q = r/rp;
		rs = r; us = u;
		r = rp; u = up;
		rp = rs-q*rp; up = us-q*up;
	}
	return (u<0) ? u+b: u;
}

ll maximum(vector<ll> v, ll n) {
	ll result = 0;
	for (ll i = 0; i < pow(2, v.size()); ++i) {
		ll tmp = 0;
		for (ll j = 0; j < v.size(); ++j) {
			tmp += v[j]*(((1<<j) & i)>>j);
		}
		tmp = tmp%n;
		tmp = (tmp < 0) ? tmp+n: tmp;
		if (tmp > result) {
			result = tmp;
		}
	}
	return result;
}

ll M(ll n) {
	vector<ll> p = factor(n);
	vector<ll> v;

	for (ll ni : p) {
		ll nic = n/ni;
		v.pb(nic*modinv(nic, ni));
	}
	return maximum(v, n);
}

int main(int argc, char* argv[]) {
	ll N = atoi(argv[1]);
	ll result = 0;
	
	// Generate all primes up to _N_
    primesieve::generate_primes(N, &primes);

	for (ll n = 1; n <= N; ++n) {
		result += M(n);
	}
	cout << "sigma(M(n)) de 1 à " << N << " = " << result << endl;
	return 0;
}
