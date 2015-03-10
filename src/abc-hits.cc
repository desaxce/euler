#include <iostream>

using namespace std;

int n = 1000;

int gcd (int a, int b) {
	int c;
	while ( a != 0 ) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

int primes_between_them(int a, int b, int c) {
	if (gcd(a, b)==1 and gcd(a, c)==1 and gcd(b, c)==1) {	
		return 1;
	}
	return 0;
}

int main() {
	for (int a = 1; a <	n/2; ++a) {
		for (int b = a+1; a+b < n; ++b) {
			if (primes_between_them(a, b, c)==1 and rad(a*b*c) < c) {
				result += c;
				cout << a << " " << b << " " << c << endl;
			}
		}
	}
	cout << result << endl;
}

