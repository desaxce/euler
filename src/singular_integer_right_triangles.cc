#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <deque>
#define N_MAX	2000000

using namespace std;
deque<int> d(N_MAX);

void rec(int a, int b, int c, int L) {
	int s = a+b+c;	
	if (s <= L) {
		for (int i = s; i <= L; i+=s) {
			d[i]++;
		}
		int a11 = a-2*b+2*c, a12 = 2*a-b+2*c, a13 = 2*a-2*b+3*c;
		int b11 = a+2*b+2*c, b12 = 2*a+b+2*c, b13 = 2*a+2*b+3*c;
		int c11 = -a+2*b+2*c, c12 = -2*a+b+2*c, c13 = -2*a+2*b+3*c;
		rec(a11, a12, a13, L);
		rec(b11, b12, b13, L);
		rec(c11, c12, c13, L);
	}
}

int main(int argc, char* argv[]) {
	int a = 3;
	int b = 4;
	int c = 5;
	int L = atoi(argv[1]);
	int result = 0;
	rec(a, b, c, L);

	for (int i = 0; i <= L; ++i) {
		if (d[i]==1) {
			result++;
		}
	}
	printf("%d\n", result);
	return 0;
}
