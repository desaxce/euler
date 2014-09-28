#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N   1000
using namespace std;


double L(double a, double b, double c) {
    double p = a+b+c;
    double ia = sqrt(2*b*b*c*c+b*c*(b*b+c*c-a*a))/p;
    double ib = sqrt(2*a*a*c*c+a*c*(a*a+c*c-b*b))/p;
    double ic = sqrt(2*a*a*b*b+a*b*(a*a+b*b-c*c))/p;
    if (ia!=floor(ia) or ib!=floor(ib) or ic!=floor(ic)) {
        return 0;
    }
    printf("%lf %lf %lf\n", a, b, c);
    return p+ia+ib+ic; 
}

double L(double p) {
    double result = 0;
     
    return result;
}

int main() {
    double result = 0;
    result = L(N);
    //for (int i = 1; i <= N; ++i) {
    //    for (int j = 1; j <= i; ++j) {
    //        for (int k = 1; k <= j; ++k) {
    //            result += L(i, j, k);
    //        }
    //    }
    //}
    printf("%lf\n", result);

    return 0;
}


