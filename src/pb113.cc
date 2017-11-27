#include <pe.h>

ll N = 100;
map<ll, ll> increasing;
map<ll, ll> decreasing;

ll nb_dec(ll n) {
	decreasing.clear();
	ll result = 0;
	for (ll i = 0; i < 10; ++i) {
		decreasing[i] = 1;
	}
	for (ll i = 1; i < n; ++i) {
		for (ll j = 9; j > -1; --j) {
			ll tmp = 0;
			for (ll k = 0; k < j+1; ++k) {
				tmp += decreasing[k];
			}
			decreasing[j] = tmp;
		}
	}
	for (ll i = 0; i < 10; ++i) {
		result += decreasing[i];
	}
	return result-10; // minus 10 comes from the fact that we always have to remove the digits 0 -> 9 which are already accounted for
}

int main() {
	/*for (ll i = 1; i < 10; ++i) {
		cout <<  "nb_dec(" << i << ") = " << nb_dec(i) << endl;
	}*/
	ll result = 0;

	for (ll i = 0; i < 10; ++i) {
		increasing[i] = 1;
	}

	for (ll i = 1; i < N; ++i) {
		for (ll j = 0; j < 10; ++j) {
			ll tmp = 0;
			for (ll k = j; k < 10; ++k) {
				tmp += increasing[k];
			}
			increasing[j] = tmp;
		}

	}
	
	for (ll i = 0; i < 10; ++i) {
		result += increasing[i];
	}
	//cout << result << endl;
	for (ll i = 1; i < N+1; ++i) {
		result += nb_dec(i); // number of decreasing numbers with exactly i+1 digits
	}

	cout << "Number of non-bouncy numbers below 1e" << N << " : "<<  result-1 << endl; // minus 1 because we count the '0' twice
	return 0;
}

