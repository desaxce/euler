#include <pe.h>

ll N = 10000000LL; // 10^7
ll mod = 1000000007LL; // 10^9+7

vector<ll> qq(N+1, 0);
vector<ll> pp(N+1, 0);
vector<ll> sumodd(N+1, 0);

ll modulo(ll n) {
    ll resultat = n%mod;
    return resultat < 0 ? mod+resultat: resultat;
}

// Returns modulo inverse of a with respect to m using
// extended Euclid Algorithm
// Assumption: a and m are coprimes, i.e., gcd(a, m) = 1
ll modInverse(ll a, ll m)
{
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return modulo(x1);
}

ll sum_odd(ll n) {
    if (sumodd[n] == 0) {
        ll temp = 0;
        for (ll i = 1; i <= sqrt(n); i++) {
            if (n%i == 0) {
				if (i%2!=0) {
					temp = modulo(temp+i);
				}
				ll d = n/i;
				if (d!=i and d%2!=0) {
					temp = modulo(temp+d);
				}
            }
        }
        sumodd[n] = temp;
    }
    return sumodd[n];
}

ll q(ll n) {
    if (n <= 1) {
        return 1LL;
    }
    if (qq[n] != 0) {
        return qq[n];
    }

    ll temp = 0;
    for (ll k = 1; k <= n; k++) {
        temp = modulo(temp+modulo(q(n-k)*sum_odd(k)));
    }
    //if (temp%n != 0) {
    //cout << "gros bug" << endl;
    //}
    qq[n] = modulo(temp*modInverse(n, mod));
    return qq[n];
}

ll p(ll n) {
    if (n <= 1) {
        return 1LL;
    }

    if (pp[n] != 0) {
        return pp[n];
    }

    ll temp = q(n);
    for (ll k = 1; k <= n/4; k++) {
        temp = modulo(temp+modulo(q(k)*(modulo(q(n-4LL*k)-p(n-2LL*k)))));
    }
    for (ll k = n/4+1; k <= n/2; k++) {
        temp = modulo(temp-modulo(q(k)*p(n-2LL*k)));
    }
    pp[n] = temp;
    return pp[n];
}
int main(int argc, char* argv[]) {
	//pari_init(1000000000L, 2);
    ll n = atol(argv[1]);
    //cout << "sumodd(" << n << ") = " << sum_odd(n) << endl;
	//printf("q(%llu) = %llu\n", n, q(n));
    //cout << "(10^9+6)^2 = " << modulo((mod-1)*(mod-1)) << endl;
	ll somme = 0;
	for (ll i = 1; i <= n; i++) {
		cout << i << endl;
		somme = modulo(somme+p(i));
	}
	printf("P(%llu) = %llu\n", n, somme);
    return 0;
}

