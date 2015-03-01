#include <iostream>
#include <stdint.h> // uint64_t
#include <math.h> // std:floor
#include <algorithm> // std:max
#include <unordered_map>

using namespace std;

uint64_t N = pow(2,60);

unordered_map<uint64_t, uint64_t> xmap;
unordered_map<uint64_t, uint64_t> ymap;
unordered_map<uint64_t, uint64_t>::iterator it;

uint64_t x(uint64_t k) {
	if ((it=xmap.find(k)) != xmap.end()) {
		return it->second;
	}
	else {
		uint64_t h = k/2;
		if(k%2==0) {
			xmap[k] = (3*x(h)+2*x(floor(h/2)))%N;
		}
		else {
			xmap[k] = (2*x(h)+3*x(floor(h/2)))%N;
		}
		return xmap[k];
	}
}

uint64_t y(uint64_t n, uint64_t k) {
	if ((it=ymap.find(k)) != ymap.end()) {
		return it->second;
	}
	else if (k>=n) {
		return x(k);
	}
	else {
		ymap[k] = N-1-max(y(n,2*k), y(n,2*k+1));
		return ymap[k];
	}
}

uint64_t A(uint64_t n) {
	return y(n, 1);
}

void examples() {
	uint64_t k;
	uint64_t n;
	k = 2;
	cout << "x(" << k << ") = " << x(k) << endl;
	k = 3;
	cout << "x(" << k << ") = " << x(k) << endl;
	k = 4;
	cout << "x(" << k << ") = " << x(k) << endl;

	n = 4;
	k = 4;
	cout << "y(" << n << ", " << k << ") = " << y(n, k) << endl;
	k = 3;
	cout << "y(" << n << ", " << k << ") = " << y(n, k) << endl;
	k = 2;
	cout << "y(" << n << ", " << k << ") = " << y(n, k) << endl;
	k = 1;
	cout << "y(" << n << ", " << k << ") = " << y(n, k) << endl;

	n = 10;
	cout << "A(" << n << ") = " << A(n) << endl;
	n = 1000;
	cout << "A(" << n << ") = " << A(n) << endl;
}

int main() {
	uint64_t n = 1000000;
	xmap[0] = 0;
	xmap[1] = 1;
	cout << "A(" << n << ") = " << A(n) << endl;
	return 0;
}
