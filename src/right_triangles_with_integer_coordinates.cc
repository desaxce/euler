#include <pe.h>

ll N = 50;

int main() {
	ll result = 0;
	for (ll x1 = 0; x1 <= N; ++x1) {
		for (ll y1 = 0; y1 <= N; ++y1) if (x1!=0 or y1!=0) {
			for (ll x2 = 0; x2 <= N; ++x2) {
				for (ll y2 = 0; y2 <= N; ++y2) if (x2!=0 or y2!=0) {
					if (x1==0 and y2==0) // right angle at (0, 0) 
						result++;
					if (x1*(x2-x1)+y1*(y2-y1)==0) // right angle at (x1, y1)
						result++;
				}
			}
		}
	}
	// Have to remove the cases where (x1, y1)==(x2, y2)
	cout << "Integered right triangles with N = " << N << " : " << result -(N+1)*(N+1)+ 1 << endl;
	return 0;
}

