#include <iostream>
#include <math.h>

using namespace std;

int is_palindromic(int n) {
	int nn = n;
	int result = 0;
	int digit;
	while (nn > 0) {
		digit = nn % 10;
		result = 10*result + digit;
		nn /= 10;
	}
	if (result==n) {
		return 1;
	}
	return 0;
}

int is_square_sum_starting_from(int i, int n) {
	int result = 0;
	int j = i;
	while (result < n) {
		result += j*j;
		++j;
	}
	if (result==n) {
		return 1;
	}
	return 0;
}

int is_square_sum(int n) {
	int nn = n;
	int root = floor(sqrt(nn));
	int i = 1;
	while (i < root and is_square_sum_starting_from(i, n)==0) {
		++i;
	}
	if (i < root) {
		return 1;
	}
	return 0;
}

int main() {
	long result = 0;
	for (int i = 2; i < 100000000; ++i) {
		if (is_palindromic(i)==1 and is_square_sum(i)==1) {
			result += i;
		}
	}
	cout << result << endl;
	return 0;
}
