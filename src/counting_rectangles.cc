#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MILLION 1000000
using namespace std;

int rectangular_grid_content(int n, int m) {
    int result = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            result += (m-j+1)*(n-i+1); 
        }
    }
    return result;
}

int main() {
    int n = 100;
    int minimum = 2*MILLION;
    int ii = 0, jj = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < i+1; ++j) {
            if (abs(2*MILLION-rectangular_grid_content(i, j)) < minimum) {
                minimum = abs(2*MILLION-rectangular_grid_content(i,j));
                ii = i;
                jj = j;
            }
        }
    }

    printf("area = %d\n", ii*jj);
    printf("number of rectangles = %d\n", rectangular_grid_content(ii, jj));

    return 0;
}
