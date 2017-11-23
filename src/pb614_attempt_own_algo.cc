#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <cmath>
#include <list>
#include <vector>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm> // reverse string, next_permutation
#include <numeric> // accumulate (to sum all elements in vector)
#include <bitset>
#include <time.h>
#include <utility> // std::pair

#define ll long long
#define ld long double
#define pb push_back
#define cl clear;

using namespace std;

ll N = 10000000; // 10^7
ll mod = 1000000007; // 10^9+7

vector<ll> qq(N+1, 0);
vector<ll> ss(N+1, 0);
vector<unordered_map<ll, ll> > Qeq(N+1);

inline ll modulo(ll n) {
	return n%1000000007;
}

inline ll modu(ll n, ll m) {
    return ((n % m) + m) % m;
}

ll r(ll n) {
    double racine_delta = sqrt(1+24*n);
    ll racine = floor(racine_delta);
    if (abs(racine_delta-racine) < 1e-6) { // we're an integer
        ll j = 0;
        if ((racine+1)%6 == 0) {
            j = (racine+1)/6;
        } else if ((racine-1)%6 == 0) {
            j = (racine-1)/6;
        }
        return (j%2 == 0)? 1: -1;
    }
    return 0;
}

ll q(ll n) {
    /*if (qq[n] != 0) {
        return qq[n];
    }*/
    ll temp = 0;
    for (int k = sqrt(n); k > 0; k--) {
        if (k%2 == 0) {
            temp = temp - qq[n-k*k];
        } else {
            temp = temp + qq[n-k*k];
        }
    }
    qq[n] = modulo(2*temp +r(n));
    return qq[n];
}

// Number of partitions of n into k parts
/* ll P_equal(ll n, ll k) {
    if (n < k) {
        return 0;
    }
    if (n == k) {
        return 1;
    }

    if (k == 1) {
        return 1;
    }
    return P_equal(n-k, k) + P_equal(n-1, k-1);
}*/

// Number of partitions of n into k distinct parts
ll Q_equal(ll n, ll k) {
	if (k-n > 0 or k == 0) {
		return 0;
	}
	unordered_map<ll, ll>::const_iterator it = Qeq[n].find(k);
	if (it != Qeq[n].end()) {
		return it->second;
	}
	ll temp = modulo(Qeq[n-k][k] + Qeq[n-k][k-1]);
	Qeq[n][k] = temp;
	return temp;
}


// Below method not used (only by some commented out attempt inside method s)
/*ll Q_upto(ll n, ll k) {
    //return P_equal(n+k, k);
    if (k > n) {
        return 0;
    }
    ll result = 0;
    for (ll i = 1; i <= k; i++) {
        result += Q_equal(n, i);
    }
    return result;
}*/

// List of first 70 values of method s below (for debugging)
//ll ss[70] = {1, 1, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 5, 5, 5, 6, 7, 8, 8, 9, 11, 12, 12, 14, 16, 17, 18, 20, 23, 25, 26, 29, 33, 35, 37, 41, 46, 49, 52, 57, 63, 68, 72, 78, 87, 93, 98, 107, 117, 125, 133, 144, 157, 168, 178, 192, 209, 223, 236, 255, 276, 294, 312, 335, 361, 385};

// Number of partitions of n into distinct odd parts.
ll s(ll n) {
	/*if (ss[n]!= 0) {
		return ss[n];
	}*/

    ll result = 0;

	// Algorithm worked out on my own to count the number of partitions of n into distinct odd parts.
	// not sure it's very good though
    // n can be partitioned in at most sqrt(n) distinct odd parts;
	double racine = sqrt(n);
	if (n%2 == 0) {
		for (ll r = 2; r <= racine; r+=2) {
			result = result + Q_equal((n-r)/2, r)+Q_equal((n-r)/2, r-1);
		}
	} else {
        result += Q_equal((n-1)/2, 1);
		for (ll r = 3; r <= racine; r+=2) {
			result = result + Q_equal((n-r)/2, r)+Q_equal((n-r)/2, r-1);
		}
	}
	ss[n] = modulo(result);
    return ss[n];

    /*for (ll r = 1; r <= sqrt(n); r++) {
        if ((n-r)%2 == 0) {
            result += Q_equal((n-r)/2, r);
			if (r > 1) {
			result += Q_equal((n-r)/2, r-1);
			}
        }
    }*/

	// Wrong information on https://oeis.org/A000700 (at least didn't manage to code it properly):
	// For n even: the sum over all even nonnegative integers, k, such that k^2<n, of the number of partitions of (n-k^2)/2 into parts of size at most k. For n odd: the sum over all odd nonnegative integers, j, such that j^2<n, of the number of partitions of (n-j^2)/2 into parts of size at most j. - Graham H. Hawkes, Oct 18 2013
    /*if (n%2 == 0) {
        ll result = 0;
        for (ll k = 2; k < sqrt(n); k+=2) {
            result += Q_upto((n-k*k)/2, k); // adding the number of partitions of (n-k^2)/2 into parts of size at most k.
        }
        return result;
    } else {
        ll result = 0;
        for (ll j = 1; j < sqrt(n); j+=2) {
            result += Q_upto((n-j*j)/2, j); // adding the number of partitions of (n-j^2)/2 into parts of size at most j.
        }
        return result;
    }*/

}


ll p(ll n) {
    ll result = modulo(s(n) + q(n/4)*ss[n-4*(n/4)]);
    //for (ll k = n/4-1; k > 0; --k) {
	for (ll k = 1; k <= n/4-1; k++) {
        result = modulo(result + qq[k] * ss[n-4*k]);
    }
	return result;
}

// Slow version to compute the number of partitions of n into distinct parts with even ==> divisible by 4
/*ll p_slow(ll n) {
    if (pp[n] != 0) {
        return pp[n];
    }
    ll temp = q(n);
    if (modu(n, 4) - 1 > 0) {
        temp = modulo(temp - q(n/2)*p(n-2*(n/2)));
    }

    ll k = n/4+1;
    while (--k > 0) {
        temp = modulo(temp + q(k)*(q(n-4*k)-p(n-2*k)) - q(k+n/4)*p(n-2*(k+(n/4))));
    }
    pp[n] = temp;
    return pp[n];
}*/

int main(int argc, char* argv[]) {
    ll n, k;
	n = atol(argv[1]);
	//k = atol(argv[2]);
    qq[0] = 1; qq[1] = 1;
    ss[0] = 1; ss[1] = 1;
	Qeq[1][1] = 1;
	ll somme = 0;
	for (ll i = 2; i <= n; i++) {
        if (i%1000 == 0)
            printf("%llu\n", i);
		somme = modulo(somme+p(i));
	}
	//100for (ll i = 0)
	//printf("q(%llu) = %llu\n", n, q(n));
	//printf("s(%llu) = %llu\n", n, s(n));
	printf("somme(%llu) = %llu\n", n, modu(somme, mod));
	//printf("p(%llu) = %llu\n", n, modu(pp[n], mod));
    //printf("Q_equal(%llu, %llu) = %llu\n", n, k, Q_equal(n, k));
    //printf("Q_upto(%llu, %llu) = %llu\n", n, k, Q_upto(n, k));
    //printf("P_equal(%llu, %llu) = %llu\n", n, k, P_equal(n, k));

    return 0;
}

