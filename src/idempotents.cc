#include <iostream>

using namespace std;

long M(long n) {
	long a = n-1;
	while (a*(a-1)%n!=0)
		--a;
	return a;
}

int main() {
	cout << M(6) << endl;
	long long result = 0;
	for (long n = 1; n < 100000; ++n) {
		result += M(n);
	}
	cout << "sigma(M(n)) de 1 à n = " << result << endl;
	return 0;
}
