#include <iostream>
#include <bitset>

using namespace std;

const int n;

void display_bits(int c) {
	cout << bitset<n>(c) << endl;;
}

int main() {
	// Lists all subsets of k elements from the set of n elements.
	// Nice little hack (Gosper's hack)
	int k = 4;

	int c = (1<<k)-1;
	while (c < (1<<n)) {
		display_bits(c);
		int a = c&-c, b = c+a;
		c = (c^b)/4/a|b;
	}
	return 0;
}

