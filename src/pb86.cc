#include <pe.h>

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);
	int cnt = 0;
	for (int a = 1; a < n+1; a++) {
		for (int b = 1; b < a+1; b++) {
			for (int c = 1; c < b+1; c++) {
				double d = sqrt(a*a + (b+c)*(b+c));
				if (abs(floor(d)-d) < 1e-10) {
					cnt+=1;
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}

