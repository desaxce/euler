#include <pe.h>

ll nb(ll N) {
	ll result = 0;
	for (ll x = N+1; x < 2*N+1; ++x) {
		ld y = N*x*1.0/(x-N);
		if (y==floor(y)) {
			result++;
		}
	}
	return result;
}

int main() {
	ll i = 4, tmp;
	while ((tmp=nb(i))<1000) {
		cout << "nb(" << i << ") = " << tmp << endl;
		++i;
	}
	cout << "Result = " << i << endl;
	return 0;
}
