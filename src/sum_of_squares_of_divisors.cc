#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int SIGMA2(int n) {
    int result = 0;
    // Assuming here that n is even
    // Encore la fonction phi d'Euler qui intervient!!!
    for (int i = 1; i <= n/2; ++i) {
        result += (n/i)*i*i;
    }
    // the stuff below is zero mod 10**9 if n = 10**15
    // result += n*(n+1)*(2*n+1)/6;
    // result -= n/2*(n/2+1)*(n+1)/6;

    return result;
}

int main() {
    for (int i = 1; i < 10; ++i) {
        printf("SIGMA2(%d) = %d\n", 2*i, SIGMA2(2*i)); 
    }
    return 0;
}

