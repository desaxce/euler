#include <iostream>
#include <stdio.h>
#include <stdlib.h>

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
    int result = rectangular_grid_content(2, 3);
    printf("%d\n", result);
    return 0;
}
