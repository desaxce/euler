#include <pe.h>

ll N;
vector<ll> primes;
vector<ll> admissible;
vector<bool> pr;
set<ll> distinct_fortunate;

ll pseudo_fortunate(ll a) {
	ll i = 3;
	while (!pr[a+i]) { i+=2;}
	//cout << a << " : " << i << endl;
	return i;
}

void next(ll x, ll p) { // x is the potential admissible number and p is its biggest prime factor
	if (x < N) {
		admissible.pb(x);
		next(x*p, p);
		vector<ll>::iterator it = find(primes.begin(), primes.end(), p) +1;
		next(x*(*it), *it);
	}
	return;
}

int main(int argc, char *argv[]) {
	if (argc==2) {
		N = atoi(argv[1]);
	}
	else {
		cout << "Usage: " << argv[0] <<  " <N>" << endl;
		return 1;
	}
	
	primesieve::generate_primes(N+100, &primes); // we add a hundred to be sure that we can find the pseudo fortunate numbers
	for (ll i = 0; i < N+100; ++i) {
		pr.pb(false);
	}
	for (ll p : primes) {
		pr[p] = true;
	}
	cout << "Done generating primes" << endl;
	next(2, 2);
	cout << "Done generating admissible numbers" << endl;

	for (ll adm : admissible) {
		distinct_fortunate.insert(pseudo_fortunate(adm));
	}

	ll result = 0;
	for (ll df : distinct_fortunate) {
		result += df;
	}
	cout << "Sum of all distinct pseudo-Fortunate numbers for admissible numbers N less than " << N << " = " << result << endl;

	return 0;
}

