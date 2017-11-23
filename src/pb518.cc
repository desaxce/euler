#include <stdio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>

int gcd(int a, int b) {
	return b == 0? a: gcd(b, a%b);
}

int main(int argc, char **argv)
{
    int N = argc > 1 ? atoi(argv[1]) : 100000000;
    long long i, j, k, d, n, ndd, nd;
    long long total = 0;
    char *s = calloc(N, 1);

    for(i = 2; i * i < N; i++)
        if (s[i] == 0)
            for(j = 2 * i; j < N; j += i)
                s[j] = 1;

    s[0] = s[1] = 1;

    for(d = 1; d < N; d++) {
        for(n = d * d; n < N; n += d * d)
            if (s[n - 1] == 0) {
                nd = n / d;
                ndd = n / d / d;
                for(k = d + 1; ndd * k * k <= N; k++)
                    if (s[nd * k - 1] == 0 && s[ndd * k * k - 1] == 0 && gcd(d, k) == 1)
                        total += n + nd * k + ndd * k * k - 3;
            }
    }

    printf("%lld\n", total);

    return 0;
}
