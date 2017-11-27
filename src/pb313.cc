#include <pe.h>

ll N;
vector<ll> primes;

ll S(ll m, ll n) {
	if (m==n)
		return 8*m-11; // return 6*(m-2)+4+n+m-3;
	else
		return 2*n+6*m-13; // return 6*(n-1)+5*(m-n-1)+1+n+m-3;
}

int main(int argc, char* argv[]) {
	N = atoi(argv[1]);
	primesieve::generate_primes(N-1, &primes);
	ll result = 0;

	for (ll p : primes) {
		ld tmp = (p*p+11)/8.;
		if (tmp==floor(tmp)) {
			result++;
		}
		
		ll t = p*p+13;
		if (t%2==0) {
			result += max((ll)0L, (ll) (floor((t/2-2)/3.) - 1));
		}
	}

	cout << result/2+1 << endl;

	return 0;
}

