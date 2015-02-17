#include <iostream>
#define N 1000000000

using namespace std;

int reverse(int n) {
	int result = 0;
	while (n!=0) {
		result *= 10;
		result += n%10;
		n/=10;
	}
	return result;
}

int is_entirely_odd(int n) {
	while (n and (n%10)%2==1) {
		n /= 10;
	}
	if (n==0) {
		return 1;
	}
	else {
		return 0;
	}
}

int is_reversible(int n) {
	if (n%10==0) {
		return 0;
	}
	
	return is_entirely_odd(n+reverse(n));
}

int main() {
	int result = 0;
	for (int i = 0; i < N; ++i) {
		result += is_reversible(i);
	}
	cout << "Number of reversible numbers below " << N << ": " << result << endl;
	return 0;
}
