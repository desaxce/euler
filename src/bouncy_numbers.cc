#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <deque>

using namespace std;

int is_a_decreasing_or_increasing_number(int n) {
    bool increasing = 0;
    bool decreasing = 0;
    deque<int> decimals;
    do {
        decimals.push_back(n%10);
        n/=10;
    } while (n);

    int current = decimals[0];
    if (decimals.size() == 1) {
        return 1;
    }
    for (int i = 1; i < decimals.size(); ++i) {
        if (decimals[i] > current) {
            if (increasing) {
                return 0;
            }
            else {
                decreasing = 1;    
                current = decimals[i];
            }
        }
        else if (decimals[i] < current) {
            if (decreasing) {
                return 0;
            }
            else {
                increasing = 1;
                current = decimals[i];
            }
        }
    }
    return 1;
}

int is_a_bouncy_number(int n) {
    return !is_a_decreasing_or_increasing_number(n);
}

int main() {
    int result = 0;
    double proportion;
    int n = 1; 
    while (proportion < 0.99) {
        result += is_a_bouncy_number(n);
        proportion = result*1.0/n;
//        printf("proportion = %lf\n", proportion);
//        printf("n = %d\n", n);
        n++;
    }

    printf("n = %d\n", n-1);

    return 0;
}


