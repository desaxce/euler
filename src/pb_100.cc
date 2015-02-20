#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
	long double i = 1000000000000L;
	long double r;
	while ((r=(1/2+sqrt(i*(i-1)/2+1/4))!=floor(r)) {
		++i;
	}
	printf("i = %Lf and number of blue discs = %Lf\n", i, r);
	return 0;
}
