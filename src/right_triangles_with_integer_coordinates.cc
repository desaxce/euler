#include <pe.h>

ll N = 500;

int main() {
	ll result = N*N;
	for (ll x1 = 0; x1 <= N; ++x1) {
		for (ll y1 = 0; y1 <= N; ++y1) {
			for (ll x2 = 0; x2 <= N; ++x2) {
				for (ll y2 = 0; y2 <= N; ++y2) if (x1*y2-y1*x2!=0) { // Non trivial triangle
					if (x1*(x2-x1)+y1*(y2-y1)==0) // right angle at (x1, y1)
						result++;
				}
			}
		}
	}
	// Have to remove the cases where (x1, y1)==(x2, y2)
	cout << "Integered right triangles with N = " << N << " : " << result << endl;
	return 0;
}

