#include <pe.h>

// On generalise la notion de nombre pandigitaux: on autorise des zeros
// au debut. On introduit egalement la notion de nombre quasi-pandigital:
// c'est un nombre pandigital ne contenant qu'un seul zero.

// Count the number of repetitions in vector v
ll repetitions(vector<ll> v) {
	set<ll> s(v.begin(), v.end()); // no duplicates in set
	return v.size()-s.size();
}

// Computes n!
ll factorial(ll n) {
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

// Returns floor(n) if n is not an integer, and n-1 otherwise
ll right_below(ld x) {
	ll result;
	if (floor(x)==x) {
		result = floor(x)-1;
	}
	else {
		result = floor(x);
	}
	return result;
}

// Somehow I think this function does exactly the same as STL ceil()
ll right_uptop(ld x) {
	ll result;
	if (floor(x)==x) {
		result = floor(x);
	}
	else {
		result = floor(x)+1;
	}
	return result;
}
vector<ll> integer_to_vector(ll n, ll c) {
	vector<ll> result;

	for (ll k = 0; k < right_below(n/2.); ++k) {
		if ((c & (1 << (2*k))) != 0) {
			result.pb(ceil(n/2.)-k-1);
		}
		if ((c & (1 << (2*k+1))) != 0) {
			result.pb(ceil(n/2.)-k-1);
		}
	}

	if (n%2!=0) { // si on est dans le cas n = 19, on ne peut rajouter qu'un seul 0
		if ((c & (1 << (n-1))) != 0) {
			result.pb(0L);
		}
	}
	else { // sinon on est dans le cas n = 20, et il est possible d'en avoir 2
		if ((c & (1 << (n-2))) != 0) {
			result.pb(0L);
		}
		if ((c & (1 << (n-1))) != 0) {
			result.pb(0L);
		}
	}
	return result;
}

map<ll, ll> integer_to_map(ll n, ll c) {
	map<ll, ll> result;
	for (ll k = 0; k < n/2; ++k) {
		if ((c & (1 << (2*k))) != 0) {
			result[n/2-k-1]++;
		}
		if ((c & (1 << (2*k+1))) != 0) {
			result[n/2-k-1]++;
		}
	}

	if (n%2!=0) { // si on est dans le cas n = 19, on ne peut rajouter qu'un seul 0
		if ((c & (1 << (n-1))) != 0) {
			result[0]++;
		}
	}
	else { // sinon on est dans le cas n = 20, et il est possible d'en avoir 2
		if ((c & (1 << (n-2))) != 0) {
			result[0]++;
		}
		if ((c & (1 << (n-1))) != 0) {
			result[0]++;
		}
	}
	return result;
}
// Dans cette fonction, n represente le nombre de digits (dans notre cas
// c'est soit 20 (double pandigital), soit 19 (quand on retire un zero).
ll number_of_pandigital_number_divisible_by_11(ll n) {
	ll result = 0;

	// On veut que le cardinal de _aplus_ soit de taille 9 quand on
	// calcule le nombre de nombre quasi-pandigitaux (ceci est du au fait
	// que l'on considere que les ensembles _aplus_ et _amoins_ contiennent le
	// meme nombre de repetitions, et que la fonction qui compte le nombre de
	// repetitions n'est plus entierement adaptee).
	ll k = n/2;

	// Gosper's hack to loop over all subsets of size k.
	ll c = (1<<k)-1;
	vector<map<ll, ll> > pan;

	while (c < (1<<n)) {
		// It's easier to use a list of numbers.
		vector<ll> aplus = integer_to_vector(n, c); // _n_ indicates whether we are looking for
													// pandigital of quasi-pandigital numbers.
		//cout << aplus.size() << " " << n-aplus.size() << endl;
		map<ll, ll> cur = integer_to_map(n, c);

		// 90 comes from the sum of all elements (0->9) times 2.
		// include <numeric> to use accumulate
		ll tmp = 90 - 2*accumulate(aplus.begin(), aplus.end(), 0);
		if (tmp%11==0 and find(pan.begin(), pan.end(), cur) == pan.end()) { // critere de divisibilite par 11
			//const int cn = 20;
			//cout << "c = " << bitset<cn>(c) << endl;
			//for (ll tmp : aplus)
				//cout << tmp << " ";
			//cout << endl << endl;

			ll nplus = repetitions(aplus);
			ll nmoins = nplus;
			if (n%2==1 and find(aplus.begin(), aplus.end(), 0)!=aplus.end()) {
				nmoins++;	// Il ne faut rajouter 1 que si aplus contient le zero.
							// Sinon de maniere generale, il y a autant de repetitions
							// aplus que dans amoins.
			}
		
			result += factorial(aplus.size())*factorial(n-aplus.size())/pow(2, (nplus+nmoins));
			pan.pb(cur);
		}

		// The two lines below find the next _c_ containing k 1's.
		ll a = c&-c, b = c+a;
		c = (c^b)/4/a|b;
	}
	//cout << pan.size() << endl;
	return result;
}

int main() {
	ll result = 0;
	result += number_of_pandigital_number_divisible_by_11(20);	// we allow leading zeros
	result -= number_of_pandigital_number_divisible_by_11(19);	// so we have to remove the quasi-pandigital numbers
	cout << "Number of pandigital number divisible by 11: " << result << endl;
}

