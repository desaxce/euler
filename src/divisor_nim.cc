#include <pe.h>

ll g(ll k) { // grundy number is the 2-adic valuation of k
	ll result = 0;
	while (k%2==0) {
		++result;
		k/=2;
	}
	return result;
}

ll first_idea(ll n) { // using grundy O(n^3)
	ll result = 0;
	for (ll a = 1; a < n+1; ++a) {
		for (ll b = 1; b < n+1; ++b) {
			for (ll c = 1; c < n+1; ++c) {
				if (((g(a)^g(b))^g(c))!=0) {
					result++;
				}
			}
		}
	}
	return result;
}

ll f(ll n, ll a) {
	return (ll) (floor(n/pow(2., a))-floor(n/pow(2., a+1)));
}

// the function below works well, but I don't want to use C to compute 
// big numbers. Too difficult to get through the modulo issues (use PARI/GP instead).
ll second_idea(ll n) { // complexity O(log(n)^3)
	ll result = 0;
	ll limit = (ll) floor(log(n)/log(2.));
	for (ll a = 0; a < limit+1; ++a) {
		for (ll b = 0; b < limit+1; ++b) {
			for (ll c = 0; c < limit+1; ++c) {
				if (((a^b)^c)!=0) {
					result += f(n, a)*f(n, b)*f(n, c);
				}
			}
		}
	}
	return result;
}

int main(int argc, char* argv[]) {
	ll n = atoi(argv[1]);
	//cout << first_idea(n) << endl;
	cout << second_idea(n) << endl;
	return 0;
}
