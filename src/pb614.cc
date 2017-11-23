#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cmath>
#include <list>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm> // reverse string, next_permutation
#include <numeric> // accumulate (to sum all elements in vector)
#include <bitset>
#include <time.h>
#include <utility> // std::pair
#include <thread>

#define ll long long
#define ld long double
#define pb push_back
#define cl clear;


using namespace std;

ll N = 10000000; // 10^7
ll mod = 1000000007; // 10^9+7

vector<ll> qq(N+1, 0);
vector<ll> pp(N+1, 0);

inline ll modulo(ll n) {
    return n%1000000007;
}

inline ll modu(ll n, ll m) {
    return ((n % m) + m) % m;
}

ll s(ll n) {
    double racine_delta = sqrt(1+24*n);
    ll racine = floor(racine_delta);
    if (abs(racine_delta-racine) < 1e-6) { // we're an integer
        ll j;
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
    ll temp = 0;
    for (int k = sqrt(n); k > 0; k--) {
        if (k%2 == 0) {
            temp = temp - qq[n-k*k];
        } else {
            temp = temp + qq[n-k*k];
        }
    }
    temp = modulo(2*temp +s(n));
	qq[n] = temp;
    return temp;
}

ll temp1 = 0;
ll temp2 = 0;
ll temp3= 0;
ll temp4 = 0;

void p1(ll n, ll top, ll bottom) {
	temp1 = 0;
	ll j = top+1;
    while (--j > bottom) {
        temp1 = modulo(temp1 + qq[j]*(qq[n-4*j]-pp[n-2*j]) - qq[j+n/4]*pp[n-2*(j+(n/4))]);
    }
}

void p2(ll n, ll top, ll bottom) {
	temp2 = 0;
	ll j = top+1;
    while (--j > bottom) {
        temp2 = modulo(temp2 + qq[j]*(qq[n-4*j]-pp[n-2*j]) - qq[j+n/4]*pp[n-2*(j+(n/4))]);
    }
}

void p3(ll n, ll top, ll bottom) {
	temp3 = 0;
	ll j = top+1;
    while (--j > bottom) {
        temp3 = modulo(temp3 + qq[j]*(qq[n-4*j]-pp[n-2*j]) - qq[j+n/4]*pp[n-2*(j+(n/4))]);
    }
}

void p4(ll n, ll top, ll bottom) {
	temp4 = 0;
	ll j = top+1;
    while (--j > bottom) {
        temp4 = modulo(temp4 + qq[j]*(qq[n-4*j]-pp[n-2*j]) - qq[j+n/4]*pp[n-2*(j+(n/4))]);
    }
}

ll p(ll n) {
    ll temp = q(n);
    if (((n%4)+4)%4 - 1 > 0) {
        temp = modulo(temp - qq[n/2]*pp[n-2*(n/2)]);
    }

	//thread t1(p1, n, n/4, 3*n/16);
	thread t2(p2, n, 3*n/16, n/8);
	thread t3(p3, n, n/8, n/16);
	thread t4(p4, n, n/16, 0);
    ll k = n/4+1;
    while (--k > 3*n/16) {
        temp = modulo(temp + qq[k]*(qq[n-4*k]-pp[n-2*k]) - qq[k+n/4]*pp[n-2*(k+(n/4))]);
    }

	//t1.join();
	t2.join();
	t3.join();
	t4.join();
    pp[n] = modulo(temp+temp2+temp3+temp4);
    return pp[n];
}

int main(int argc, char* argv[]) {
    ll n = atol(argv[1]);
    //cin >> n;
    pp[0] = 1; pp[1] = 1;
    qq[0] = 1; qq[1] = 1;
	ll somme = pp[1];
	for (ll i = 2; i <= n; i++) {
        if (i%1000 == 0)
            printf("%llu\n", i);
		somme = modulo(somme+p(i));
	}
	printf("P(%llu) = %llu\n", n, modu(pp[n], mod));
	printf("sigma(P(%llu)) = %llu\n", n, modu(somme, mod));
    return 0;
}

