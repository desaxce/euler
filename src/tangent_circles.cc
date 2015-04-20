#include <pe.h>

ll N = 1e9;
ll limit = 178;

/* Standard C Function: Greatest Common Divisor */
int gcd (int a, int b) {
	if (a < b) {
		return gcd(b,a);
	}
	int c;
	while ( a != 0 ) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

ll triangle(ll k) {
	return k*(k+1)/2;
}

bool is_multiple(ll a, ll b, ll c) {
	return (gcd(a, gcd(b, c))!=1);
}

int main() {
	ll result = 0;
	// Commented below is the first method I used but it's linear in N
	for (ll a = 1; a <= sqrt(N); ++a) { // a here corresponds to sqrt(a)
		for (ll b = a; b <= sqrt(N); ++b) { // same goes for b there
			ll tmp1 = a*a*b*b;
			ll tmp2 = (a*a+b*b+2*a*b);
			ll c = tmp1/tmp2;
			if (tmp1%tmp2==0 and !is_multiple(a*a, b*b, c)) { // that's the most important part: you need to check that all gcd(a, b, c)=1, not just gcd(a, c)==1
				result += (a*a+b*b+c)*triangle(N/b/b);
			}
		}
	}
	/*ll a, b, c;
	for (ll n = 2; n < limit+1; ++n) { // where does this limit come from ?
		a = n*n; c = (n-1)*(n-1);
		b = (a*c*(c+a)+2*n*n*n*(n-1)*(n-1)*(n-1))/(a-c)/(a-c);
		cout << a << " " << b << " " << c << endl;
		result += (a+b+c)*triangle(N/b);
	}*/
	cout << result << endl;
	return 0;
}

