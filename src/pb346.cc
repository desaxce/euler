#include <iostream>
#include <map>
#include <math.h>
#define ll long long

using namespace std;

ll N = 1e12L;

int main() {
	ll result = 0;
	map<ll, ll> repunits;

	for (int b = 2; b < floor(sqrt(N)); ++b) {
		ll a = 1;
		do {
			repunits[a]++;
			a = a*b+1;
		} while(a<N);
	}
	for (map<ll, ll>::const_iterator it = repunits.begin(); it!=repunits.end(); ++it) {
		if (it->first <= floor(sqrt(N))) {
			if (it->second >= 2)
				result += it->first;
		}
		else {
			if (it->second >= 1) 
				result += it->first;
		}
	}
	printf("Sum of all strong repunits below %Ld : %Ld\n", N, result);
	return 0;
}
