#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <gmpxx.h>

using namespace std;

int main() {
    int passed = 0;
    long double square = 10203040506070809L;
    for (int b = 0; b <= 9; ++b) {
        square += 10L*b;
        for (int c = 0; c <= 9; ++c) {
            square += 1000L*c;
            for (int d = 0; d <= 9; ++d) {
                square += 100000L*d;
                for (int e = 0; e <= 9; ++e) {
                    square += 10000000L*e;
                    for (int f = 0; f <= 9; ++f) {
                        square += 1000000000L*f;
                        for (int g = 0; g <= 9; ++g) {
                            square += 100000000000L*g;
                            for (int h = 0; h <= 9; ++h) {
                                square += 10000000000000L*h;
                                for (int i = 0; i <= 9; ++i) {
                                    square += 1000000000000000L*i;
                                    if (floorl(sqrtl(square)) == sqrtl(square)) {
                                        printf("%Lf\n", sqrtl(square)*10);
                                        return 0;
                                    }
                                    square -= 1000000000000000L*i;
                                }
                                square -= 10000000000000L*h;
                            }
                            square -= 100000000000L*g;
                        }
                        square -= 1000000000L*f;
                    }
                    square -= 10000000L*e;
                }
                square -= 100000L*d;
            }
            square -= 1000L*c;
        }
        square -= 10L*b;
    }
    return 0;
}


