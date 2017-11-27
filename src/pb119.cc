#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <set>

using namespace std;

long long digit_sum(long long n) {
	long long result = 0;
	while(n!=0) {
		result += n%10;
		n /= 10;
	}
	return result;
}

int main() {
	set<long double> powers;
	for (int e = 2; e < 1000; ++e) {
		for (int i = 1; i < 1000; ++i) {
			long double a = pow(e, i);
			if (e==digit_sum(a)) {
				powers.insert(a);
			}
		}
	}
	int count = 0;
	for (set<long double>::const_iterator it=powers.begin(); it != powers.end(); ++it) {
		printf("%d\t %0Lf\n", ++count, *it);
	}
	return 0;
}

