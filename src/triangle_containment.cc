#include <iostream>

using namespace std;

long product(long a, long b, long c, long d) {
	return a*d - b*c;
}

int is_ith_triangle_ok() {
	// Modified input file (p102_triangles.txt): replaced commas with spaces, easier to parse :)
	long ax, ay, bx, by, cx, cy;
	cin >> ax;
	cin >> ay;
	cin >> bx;
	cin >> by;
	cin >> cx;
	cin >> cy;
	if (product(ax, ay, bx, by)*product(ax, ay, cx, cy) <= 0 and product(bx, by, ax, ay)*product(bx, by, cx, cy) <= 0 and product(cx, cy, ax, ay)*product(cx, cy, bx, by) <= 0) {
		return 1;
	}
	return 0;
}

int main() {
	int result = 0;
	for (int i = 1; i <= 1000; ++i) {
		result += is_ith_triangle_ok();
	}
	cout << "Number of triangles containing the origin: " << result << endl;
	return result;
}
