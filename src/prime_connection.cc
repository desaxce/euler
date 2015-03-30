#include <pe.h>

ll N = 1e7;
vector<ll> primes;
vector<ll> use;
vector<ll> dont_use;

ll distance(ll p, ll q) { // Base 10 Hamming distance
	if (p==q) {
		return 0;
	}
	else if (p<q) {
		return distance(q, p);
	}

	ll plen = floor(log10(p))+1;
	ll qlen = floor(log10(q))+1;
	if (plen==qlen) {
		ll result = 0;
		while (p!=0) {
			result += (p%10!=q%10);
			p/=10; q/=10;
		}
		return (result==1)? 1: 2;
	}
	else if (plen-qlen==1) {
		ll mod = p%((ll) pow(10, plen-1));
		mod = (mod < 0) ? mod+pow(10, plen-1): mod;
		if (mod==q) { 
			return 1;
		}
		return 2;
	}
	else {
		return 2;
	}

}

void add_and_remove(ll p) {
	vector<ll> to_remove;
	for (ll q : dont_use) {
		if (distance(p, q) == 1) {
			to_remove.pb(q);
		}
	}
	for (ll q : to_remove) {
		vector<ll>::iterator it = find(dont_use.begin(), dont_use.end(), q);
		dont_use.erase(it);
	}
	for (ll q : to_remove) {
		add_and_remove(q);
	}
	use.pb(p);
}

int main() {
	primesieve::generate_primes(3, N, &primes);
	ll result = 0;
	use.pb(2);
	for (ll p : primes) {
		ll i = use.size()-1;;
		while (i>-1 and distance(p, use[i])!=1) { --i;}
		if (i==-1) { // p is not a 2's relative
			dont_use.pb(p); result += p;
		}
		else { // p is a 2's relative
			add_and_remove(p);
		}
	}
	
	cout << "Result = " << result << endl;
	return 0;

}

