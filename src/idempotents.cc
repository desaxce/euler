#include <iostream>

using namespace std;

long M(long n) {
	long a, result = 1;
	for (a=n/2-1; a < n; ++a) {
		if (a*(a-1)%n==0)
			result = a;
	}
	return result;
}

int main() {
	long long result = 0;
	for (long n = 1; n < 100000; ++n) {
		result += M(n);
	}
	cout << "sigma(M(n)) de 1 à 10e7 = " << result << endl;
	return 0;
}
