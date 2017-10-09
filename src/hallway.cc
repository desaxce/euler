#include "pe.h"

vector<ll> T1;
vector<ll> T3;
ll N;

deque<pair<ll, ll> > s3;

struct Bidule {
	ll current;
	ll index;
	ll contientUnImpair; 
	ll pariteSomme;
	ll pariteSeul;
	ll firstTime;

	Bidule(ll acurrent, ll anindex, ll acontientUnImpair, ll apariteSomme, ll apariteSeul, ll afirstTime) : current(acurrent), index(anindex), contientUnImpair(acontientUnImpair), pariteSomme(apariteSomme), pariteSeul(apariteSeul), firstTime(afirstTime) {}
};

deque<Bidule> s1;

void initialize(ll n) {
	vector<ll> primes;
	primesieve::generate_primes(n, &primes);
	for (ll i = 1; i < primes.size(); i++) {
		if (primes[i]%4 == 1) {
			T1.pb(primes[i]);
		} else {
			T3.pb(primes[i]);
		}
	}
}

void display(Bidule bid) {
	cout << "current = " << bid.current << endl;
	cout << "index = " << bid.index << endl;
	cout << "contientUnImpair = " << bid.contientUnImpair << endl;
	cout << "pariteSomme = " << bid.pariteSomme << endl;
	cout << "pariteSeul = " << bid.pariteSeul << endl;
	cout << "firstTime = " << bid.firstTime << endl;
}

ll S1() {
	ll result = 0;
	while (!s1.empty()) {
		//cout << result << endl;
		Bidule bid = s1.front();
		s1.pop_front();
		ll current = bid.current;
		ll index = bid.index;
		ll contientUnImpair = bid.contientUnImpair;
		ll pariteSomme = bid.pariteSomme;
		ll pariteSeul = bid.pariteSeul;
		ll firstTime = bid.firstTime;
	
		cout << s1.size() << endl;
		if (index < T1.size() and current > 0) {
			if (contientUnImpair != 0) {
				ll temp = current * pow(T1[index], 2);
				cout << temp << endl;
				if (abs(temp) > N) {
					result += (pariteSeul+1)%2;
				} else {
					cout << "through herer 1111111111" << endl;
					display(bid);
					s1.pb(Bidule(current, index+1, contientUnImpair, pariteSomme, pariteSeul, 0));
					if (contientUnImpair == T1[index]) {
						pariteSeul = (pariteSeul+1)%2;
					}
					s1.pb(Bidule(temp, index, contientUnImpair, pariteSomme, pariteSeul, 0));
				}
			} else {
				ll temp1 = current * T1[index];
				if (abs(temp1) > N) {
					result += (pariteSomme+1)%2;
				} else {
					if (firstTime == 1) {
						cout << "through herer 2222222222" << endl;
						s1.pb(Bidule(temp1, index, T1[index], pariteSomme, pariteSeul, 1));
					}
					ll temp2 = temp1 * T1[index];
					if (abs(temp2) > N) {
						cout << "through herer 3333333333" << endl;
						s1.pb(Bidule(current, index+1, 0, pariteSomme, pariteSeul, 1));
					} else {
						cout << "through herer 4444444444" << endl;
						s1.pb(Bidule(temp2, index, 0, (pariteSomme+1)%2, pariteSeul, 0));
						s1.pb(Bidule(current, index+1, 0, pariteSomme, pariteSeul, 1));
					}
				}
			}
		}

	}
	return result;

/*	if (contientUnImpair != 0) {
		ll temp = current * pow(T1[index], 2);
		if (temp > N) {
			return (pariteSeul+1)%2;
		}
		ll result = S1(current, index+1, contientUnImpair, pariteSomme, pariteSeul, 1);
		if (contientUnImpair == T1[index]) {
			pariteSeul = (pariteSeul+1)%2;
		}
		result += S1(temp, index, contientUnImpair, pariteSomme, pariteSeul, 1);
		return result;
	} else {
		ll result = 0;
		ll temp1 = current * T1[index];
		if (temp1 > N) {
			return (pariteSomme+1)%2;
		}
		if (firstTime == 1) {
			result += S1(temp1, index, T1[index], pariteSomme, pariteSeul, 1);
		}
		ll temp2 = temp1 * T1[index];
		if (temp2 > N) {
			return result + S1(current, index+1, 0, pariteSomme, pariteSeul, 1);
		}
		result += S1(temp2, index, 0, (pariteSomme+1)%2, pariteSeul, 0) + S1(current, index+1, 0, pariteSomme, pariteSeul, 1);
		return result;
	}*/
}

ll S3() {
	ll result = 0;
	while (!s3.empty()) {
		cout << " s3 size = " << s3.size() << endl;
		pair<ll, ll> p = s3.front();
		s3.pop_front();
		ll current = p.first;
		ll index = p.second;


		ll temp = current * pow(T3[index], 2);
		if (index >= T3.size() or temp > N) {
			s1.pb(Bidule(current, 0, 0, 1, 0, 1));
			result += S1();
		} else {
			s3.pb(make_pair(temp, index));
			s3.pb(make_pair(current, index+1));
		}
	}
	return result;
}

ll sol(ll n) {
	ll somme = 0;
	for (ll k = floor(log(n)/log(2)); k > -1 ; k--) {
		cout << k << endl;
		s3.pb(make_pair(pow(2, k), 0));
		somme += S3();
	}
	return somme;
}

void displayT1() {
	cout << "T1 = [";
	for (ll i = 0; i < T1.size()-1; i++) {
		cout << T1[i] << ", ";
	}
	cout << T1[T1.size() -1] <<  "]" << endl;
}

void displayT3() {
	cout << "T3 = [";
	for (ll i = 0; i < T3.size()-1; i++) {
		cout << T3[i] << ", ";
	}
	cout << T3[T3.size() -1] << "]" << endl;
}

int main(int argc, char* argv[]) {
	ll n = atoi(argv[1]);
	initialize(n);
	N = n;
	printf("F(%lld) = %lld\n", n, sol(n));
	return 0;
}

