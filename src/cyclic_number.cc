#include <pe.h>

#define b 10

vector<ll> primes;
ll N = 1e9L;

// Returns a^(-1) modulo b
ll modinv(ll a, ll n) {
	ll r = a, rp = n, q;
	ll u = 1, up = 0;
	ll rs, us;
	while (rp!=0) {
		q = r/rp;
		rs = r; us = u;
		r = rp; u = up;
		rp = rs-q*rp; up = us-q*up;
	}
	return (u<0) ? u+n: u;
}

ll is_cyclic(ll p) { // check the beginning "00000000137"
	ll t = 0, r = 1, n = 0, x, d;
	ll total = 0;
	do {
		if (t==11 and n!=137)
			break;
		t = t+1;
		x = r*b;
		d = x/p;
		r = x%p;
		n = (b*n+d)%100000000000L;
		total += d;
	} while (r!=1);
	
	if (t==p-1) {
		return total;
	}
	return 0;
}

ll disp_last_digit_ok(ll p) { // Multiplication a trous pour trouver les derniers digits de 1/p
	ll mp, al, rlm1, alm1, alm2, alm3, alm4, retenue;
	mp = p%10;
	mp = (mp<0)? mp+10: mp;
	al = (9*modinv(mp, 10))%10;
	al = (al<0)? al+10: al;
	cout << al << " ";
	
	rlm1 = (al*p+1)/10;

	alm1 = (rlm1*al)%10;
	retenue = (rlm1*al)/10;
	cout << alm1 << " ";

	alm2 = (rlm1*alm1+retenue)%10;
	retenue = (rlm1*alm1+retenue)/10;
	cout << alm2 << " ";

	alm3 = (rlm1*alm2+retenue)%10;
	retenue = (rlm1*alm2+retenue)/10;
	cout << alm3 << " ";

	alm4 = (rlm1*alm3+retenue)%10;
	retenue = (rlm1*alm3+retenue)/10;
	cout << alm4 << " " << endl;
	if (al!=9)
		return 0;
	if (alm1!=8)
		return 0;
	if (alm2!=7)
		return 0;
	if (alm3!=6)
		return 0;
	if (alm4!=5)
		return 0;
	
	return 1;
}
ll last_digit_ok(ll p) { // Multiplication a trous pour trouver les derniers digits de 1/p
	ll mp, al, rlm1, alm1, alm2, alm3, alm4, retenue;
	mp = p%10;
	mp = (mp<0)? mp+10: mp;
	al = (9*modinv(mp, 10))%10;
	al = (al<0)? al+10: al;
	
	rlm1 = (al*p+1)/10;

	alm1 = (rlm1*al)%10;
	retenue = (rlm1*al)/10;

	alm2 = (rlm1*alm1+retenue)%10;
	retenue = (rlm1*alm1+retenue)/10;

	alm3 = (rlm1*alm2+retenue)%10;
	retenue = (rlm1*alm2+retenue)/10;

	alm4 = (rlm1*alm3+retenue)%10;
	retenue = (rlm1*alm3+retenue)/10;

	if (al!=9)
		return 0;
	if (alm1!=8)
		return 0;
	if (alm2!=7)
		return 0;
	if (alm3!=6)
		return 0;
	if (alm4!=5)
		return 0;
	
	return 1;
}

int main() {
    primesieve::generate_primes(7, N, &primes); // on commence a 7
	ll tmp;
	//cout << last_digit_ok(724637687L) << endl;
	for (ll p : primes) {
		if (last_digit_ok(p)==1) {
			//cout << disp_last_digit_ok(p) << endl << endl;
			//cout << p << endl;
			if ((tmp=is_cyclic(p))!=0) {
				cout << p << " : " << tmp << endl;
			}
		}
		//cout << endl;
	}

	return 0;
}

