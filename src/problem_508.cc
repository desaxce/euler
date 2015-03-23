#include <pe.h>

int modulo = 1e9+7;

ll norm(pair<ll, ll> alpha) {
	return alpha.first*alpha.first+alpha.second+alpha.second;
}

// Quotient in the division by (i-1)
pair<ll, ll> quotient(pair<ll, ll> alpha) {
	return make_pair(round((alpha.second-alpha.first)/2.), round(-(alpha.first+alpha.second)/2.));
}

// Remainder in the division by (i-1)
pair<ll, ll> reste(pair<ll, ll> alpha) {
	ll m = round((alpha.second-alpha.first)/2.);
	ll n = round(-(alpha.first+alpha.second)/2.);
	return make_pair(alpha.first+m+n, alpha.second+n-m);
}

deque<ll> euclide(pair<ll, ll> alpha) {
	deque<ll> result;
	pair<ll, ll> quo;
	pair<ll, ll> res;
	int count = 1;
	while (norm(alpha)!=1) {
		quo = quotient(alpha);
		res = reste(alpha);
		result.push_back(res.first);
		cout << "Round " << count++ << endl;
		cout << "Norm = " << norm(alpha) << endl;
		cout << "Quotient = " << quo.first << " + i*" << quo.second << endl;
		cout << "Reste = " << res.first << " + i*" << res.second << endl << endl;
		alpha = quo;
	}
}

int main() {
	pair<ll, ll> gi = make_pair(-5L, 0L);

	deque<ll> representation = euclide(gi);
	for (ll d: representation) {
	//	cout << d << " ";
	}
	cout << endl;
	return 0;
}

