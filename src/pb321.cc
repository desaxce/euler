#include <pe.h>

// First phasis: put the counters into an alternate position
ll alternate(ll n) {
	/*ll result = 0;
	for (ll i = 1; i < n+1; ++i) {
		result += i/2;
		result += (i+1)/2;
	}*/
	return n*(n+1)/2;
}

// Second phasis: all red counters are moved in unison (and so are the blue ones)
ll move_in_unison(ll n) {
	/*if (n==0)
		return 0;
	else if (n==1)
		return 2;
	else {
		return move_in_unison(n-2)+2*n+1;
	}*/
	ll result = 0;
	if (n%2==1) {
		result += 2;
	}
	result += (2*n+1)*(n/2)-2*(n/2)*(n/2-1);
	return result;
}

ll M(ll n) {
	// First we switch to a position like: |R|B|R|B|R|B|R|B| |
	//ll result = alternate(n);

	// Then we move the counters in unison.
	//result += move_in_unison(n);
	
	// Well, it turned out that after simplifications, M(n) = n*(n+2)
	// And again, after other simplifications, 
	// this all turns out to be the first forty solutions (with n minimal)
	// of the diophantine equation 8*(n+1)^2 - (2*k+1)^2 = 7
	return n*(n+2);
}


// Now we solve the equation 8*(n+1)^2 - (2*k+1)^2 = 7, aka: (2*k+1)^2 - 8*(n+1)^2 = -7
ll solve(ll N) {
	ll result = 0;
	ll count = 0;
	ll t = 3, u = 1; // (3, 1) is the fundamental solution of t^2 - 8*u^2 = 1

	ll tt, uu, x, y, xx, yy;
	while (count < N+1) {
		x = t+8*u; y = u+t; // because (1, 1) is the fundamental solution of x^2 - 8*y^2 = -7 (formula is (x, y) = (rt+suD, ru+st))
							// yeah, but (-1, 1) is also a solution and these two are not equivalent (so I think)
		xx = -t+8*u; yy = -u+t;
		if (xx%2==1) {
			result+= yy-1;
//			cout << "(xx, yy) = (" << xx << ", " << yy << ")" << endl;
//			cout << "(kk, nn) = (" << xx/2 << ", " << yy-1 << ")" << endl;
			count++;
		}

		if (x%2==1) { // first check that x is of the forme 2*k+1
			result+=y-1; // then add y-1=n
//			cout << "(x, y) = (" << x << ", " << y << ")" << endl;
//			cout << "(k, n) = (" << x/2 << ", " << y-1 << ")" << endl;
			count++;
		}
		tt = t; uu = u;
		t = tt*3+8*uu; u = tt+3*uu; // formula is (t_k*t_1 + 8*u_k*u_1, t_k*u_1 + u_k*t_1)
	}
		
	return result;
}
int main(int argc, char* argv[]) {
	// N should be the number of triangle numbers we want (40)
	ll N = atoi(argv[1])-1;

	cout << solve(N) << endl; // the function solve() only gives an even number of solutions

	return 0;
}

