#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main() {
    long long n = 1000000000000L;
    long double x;

    do {
        n++;
        long double y = 2.0*n*(n-1);
        x = (double) 1/2. + (double) sqrt(y+1.0)/2.;
    } while(x*1.0/n*((x-1)*1.0/(n-1))!=0.5);
    printf("n = %Ld and x = %Lf\n", n, x);

    return 0;
}
