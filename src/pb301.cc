#include <iostream>
#include <math.h>

using namespace std;

int main() {
	long result = 0;
	for (long i = 1; i <= pow(2, 30); ++i) {
		if (((i^(2*i))^(3*i))==0) {
			result++;
		}
	}
	cout << result << endl;
	return 0;
}
