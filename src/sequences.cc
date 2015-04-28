#include <pe.h>

int main() {
	ll n = 1111;
	ll k = 24;
	ll result = 0;
	for (ll a = 0; a < n+1; ++a) {
		for (ll b = 0; b < n/11+1; ++b) {
			for (ll c = 0; c < n/101+1; ++c) {
				for (ll d = 0; d < n/1111+1; ++c) {
					if (n+a+11*b+101*c+1111*d==k) {
						result += 
					}
				}
			}
		}
	}

	return 0;
}

