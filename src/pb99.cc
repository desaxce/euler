#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <deque>

#define N   1000

using namespace std;

int main() {
    int a, b;
    double result = 1, m = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        cin >> b;
        if (b*log((double) a) > m) {
            m = b*log((double) a);
            result = i+1;
        }
    }
    printf("%f\n", result);
    return 0;
}
