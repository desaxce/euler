#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

/* Standard C Function: Greatest Common Divisor */
int gcd (int a, int b) {
	if (a < b) {
		return gcd(b,a);
	}
	int c;
	while ( a != 0 ) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

int number_of_squares_in(int a, int b, int c, int d) {
	int result = 0;
	result += ((a+1)*(b+1)-(gcd(a,b)+1))/2 - b;
	result += ((b+1)*(c+1)-(gcd(b,c)+1))/2 - c;
	result += ((c+1)*(d+1)-(gcd(c,d)+1))/2 - d;
	result += ((d+1)*(a+1)-(gcd(d,a)+1))/2 - a;
	return result+1;
}

int main() {
	int m = 100;
	int nb;
	int result = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int k = 1; k <= m; ++k) {
				for (int l = 1; l <= m; ++l) {
					nb = number_of_squares_in(i, j, k, l);
					if (floor(sqrt(nb))==sqrt(nb)) {
						result++;
					}
				}
			}
		}
	}
	printf("result = %d\n", result);
	return 0;
}
