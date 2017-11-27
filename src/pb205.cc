#include <iostream>
#include <deque>
#include <math.h>

using namespace std;

int Nc=6, Np=4;
int Fc=6, Fp=9;
int N;
int F;

long double p(int n, int i) {
	if (i<=0) {
		return 0;
	}
	else if (n==1 and i<=N) {
		return 1.0;
	}
	else if (n>=2 and i>=n) {
		long double result = 0;
		// Made a mistake here: "k < N" instead of "k <= N" ...
		for (int k = 1; k <= N; ++k) {
			result += p(n-1, i-k);
		}
		return n*result;
	}
	else {
		return 0;
	}
}

int main() {
	// Computing Colin's probabilities
	deque<long double> colin(36);
	N = Nc;
	F = Fc;
	long double totalc = 0;
	for (int i = 0; i < colin.size(); ++i) {
		colin[i] = p(F, i+1);
		totalc += colin[i];
	}

	// Computing Peter's probabilities
	deque<long double> peter(36);
	N = Np;
	F = Fp;
	long double totalp = 0;
	for (int i = 0; i < peter.size(); ++i) {
		peter[i] = p(F, i+1);
		totalp += peter[i];
	}
	
	for (int i = 0; i < colin.size(); ++i) {
		colin[i] /= totalc;
		peter[i] /= totalp;
	}
	
	long double result = 0;
	for (int i = 0; i < colin.size(); ++i) {
		// partial_sum stores the probability that Peter scores strictly more than i
		long double partial_sum = 0;
		for (int j = i+1; j < peter.size(); ++j) {
			partial_sum += peter[j];
		}
		result += colin[i]*partial_sum;
	}
	printf("Probability that Peter beats Colin = %0.10Lf\n", result);

	return 0;
}

