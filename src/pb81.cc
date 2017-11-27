#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <deque>

#define MIN(a, b)   ((a) < (b) ? (a): (b))
#define N  80

using namespace std;

deque<deque<int> > matrix(N);
deque<deque<int> > memoizer(N);

int rec(int n, int m) {
    if (memoizer[n][m] != 0) {
        return memoizer[n][m];
    }
    if (n == N-1) {
        memoizer[n][m] = 0;
        for (int i = m; i < N; ++i) {
            memoizer[n][m] += matrix[N-1][i];
        }
        return memoizer[n][m];
    }
    if (m == N-1) {
        memoizer[n][m] = 0;
        for (int i = n; i < N; ++i) {
            memoizer[n][m] += matrix[i][N-1];
        }
        return memoizer[n][m];
    }
    memoizer[n][m] = matrix[n][m]+MIN(rec(n+1, m), rec(n, m+1));
    return memoizer[n][m];
}

int main() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("%d\n", rec(0, 0));
    return 0;
}

