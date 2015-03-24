#include <pe.h>

#define ll long long

using namespace std;

ll M(ll n) {
	ll a = n-1;
	while (a>0) {
		if ((a*(a -1))%n==0)
			return a;
		--a;
	}
	return 1;
}

int main(int argc, char* argv[]) {
	ll N = atoi(argv[1]);
	/*ll result = 0;
	for (ll n = 1; n <= N; ++n) {
		result += M(n);
	}*/
	cout << "M(" << N << ") = " << M(N) << endl;
	//cout << "sigma(M(n)) de 1 à " << N << " = " << result << endl;
	return 0;
}
