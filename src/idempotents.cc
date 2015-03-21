#include <iostream>
#include <cmath>

using namespace std;

long long N = 1e5L;

long M(long n) {
	long a = n-1;
/bin/bash: q: command not found
		if (a*(a-1)%n==0)
			return a;
	}
	return 1;
}

int main() {
	cout << "M(6) = " << M(6) << endl;
	long long result = 0;
	for (long n = 1; n < N; ++n) {
		result += M(n);
	}
	cout << "sigma(M(n)) de 1 à " << N << " = " << result << endl;
	return 0;
}
