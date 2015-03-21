#include <primesieve.hpp>
#include <iostream>
#include <vector>
#include <deque>
#include <cmath> // equivalent to include <math.h>

using namespace std;

int m = 1e7, M = 2e7;

// _primes_ will store the prime number from m to M
vector<int> primes;

// Number of segments in each digit from 0 to 9
int segments[10] = {6, 2, 5, 5, 4, 5, 6, 4, 7, 6};

// cost_matrix[i][j] represents the  cost to switch from i to j
int cost_matrix[10][10] = {
{0, 4, 3, 3, 4, 3, 2, 2, 1, 2},
{0, 0, 5, 3, 2, 5, 6, 2, 5, 4},
{0, 0, 0, 2, 5, 4, 3, 5, 2, 3},
{0, 0, 0, 0, 3, 2, 3, 3, 2, 1},
{0, 0, 0, 0, 0, 3, 4, 2, 3, 2},
{0, 0, 0, 0, 0, 0, 1, 3, 2, 1},
{0, 0, 0, 0, 0, 0, 0, 4, 1, 2},
{0, 0, 0, 0, 0, 0, 0, 0, 3, 2},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

// Was to lazy to fill the entire matrix manually
void sym_cost_matrix() {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < i; ++j) {
			cost_matrix[i][j] = cost_matrix[j][i];
		}
	}
}

int digital_root(int n) {
	int result = 0;
	while (n!=0) {
		result += n%10;
		n /= 10;
	}
	return result;
}

// A priori, sam_cost(0) should never be called
// Else it's a problem, because right now it returns 0, instead of 6.
int sam_cost(int n) { 
	int result = 0;
	while (n!=0) {
		result += segments[n%10];
		n /= 10;
	}
	return result;
}

int sam(int n) {
	int result = 0;
	while (n>9) {
		result+=2*sam_cost(n); // Times 2 because you have to turn on, and then turn off
		n = digital_root(n);
	}
	result += 2*sam_cost(n);
	return result;
}

int max_cost(int debut, int fin) {
	int result = 0;

	// The lists below will store the digits of _debut_ and _fin_
	deque<int> d, f;

	// Obviously, we have nb_digit_d >= nb_digit_f
	int nb_digit_d = floor(log10(debut)) +1;
	int nb_digit_f = floor(log10(fin)) +1;

	while (debut!=0) {
		d.push_back(debut%10);
		debut /= 10;
	}
	while (fin!=0) {
		f.push_back(fin%10);
		fin /= 10;
	}

	for (int i = 0; i < nb_digit_f; ++i) {
		result += cost_matrix[d[i]][f[i]];
	}
	for (int i = nb_digit_f; i < nb_digit_d; ++i) {
		result += segments[d[i]];
	}
	return result;
}

int max(int n) {
	int result = sam_cost(n); // cost to light _n_ only
	int current = n;
	while (n>9) {
		n = digital_root(n);
		// cost to switch from _current_ to _n_
		result += max_cost(current, n);
		current = n;
	} 
	result += sam_cost(n); // cost to turn off _n_ only
	return result;
}

int main() {
	// Generate prime numbers between m and M
    primesieve::generate_primes(m, M, &primes);

	// Initialize cost_matrix
	sym_cost_matrix();

	int cost_s = 0, cost_m = 0;

	for (vector<int>::const_iterator it = primes.begin(); it!=primes.end(); ++it) {
		cost_s += sam(*it);
		cost_m += max(*it);
	}
	cout << "Sam minus Max = " << cost_s-cost_m << endl;
	return 0;
}

