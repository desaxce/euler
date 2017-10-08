#include "pe.h"

vector<ll> T1;
vector<ll> T3;
ll N;
map<ll, ll> store;

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

ll S1(ll current, ll index, ll contientUnImpair, ll pariteSomme, ll pariteSeul, ll firstTime) {
	if (index == T1.size()) {
		//if ((contientUnImpair != 0 && ((pariteSeul+1)%2==1)) or (pariteSomme+1)%2 == 1) {
			//printf("%lld\n", current);
			//cout << "ON EST PASSE LA: 11111111111" << endl;
			//store[current]++;
			//return 0;
		//} 
		return 0;
		//return (contientUnImpair == 1)? 1: (pariteSomme+1)%2;
	}
	if (contientUnImpair != 0) {
		ll temp = current * pow(T1[index], 2);
		if (temp > N) {
			//if ((pariteSeul+1)%2 == 1) {
				//printf("%lld\n", current);
				//cout << "ON EST PASSE LA: 22222222222" << " and pariteSeul = " << pariteSeul << endl;
				//store[current]++;
				//return 1;
			//}
			//return 0;
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
		//	if ((pariteSomme+1)%2 == 1) {
		//		printf("%lld\n", current);
		//		cout << "ON EST PASSE LA: 33333333333" << endl;
		//		store[current]++;
		//		return 1;
			//} 
			//return 0;
			return (pariteSomme+1)%2;
		}
		if (firstTime == 1) {
			result += S1(temp1, index, T1[index], pariteSomme, pariteSeul, 1);
		}
		ll temp2 = temp1 * T1[index];
		if (temp2 > N) {
			/*if ((pariteSomme+1)%2 == 1) {
				printf("%lld\n", current);
				cout << "ON EST PASSE LA: 44444444444" << endl;
				store[current]++;
				result += 0;
			}*/
			return result + S1(current, index+1, 0, pariteSomme, pariteSeul, 1);
			//return result+(pariteSomme+1)%2;
		}
		//cout << "ON EST PASSE LA: 55555555555" << endl;
		result += S1(temp2, index, 0, (pariteSomme+1)%2, pariteSeul, 0) + S1(current, index+1, 0, pariteSomme, pariteSeul, 1);
		return result;
	}
}

ll S3(ll current, ll index) {
	if (index >= T3.size()) {
		return S1(current, 0, 0, 1, 0, 1);
	}
	ll temp = current * pow(T3[index], 2);
	if (temp > N) {
		return S1(current, 0, 0, 1, 0, 1);
	}
	return S3(temp, index) + S3(current, index+1);
}

ll sol(ll n) {
	ll somme = 0;
	for (ll k = 0; k <= floor(log(n)/log(2)); k++) {
		somme += S3(pow(2, k), 0);
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
	//displayT1();
	//displayT3();
	
	N = n;
	printf("F(%lld) = %lld\n", n, sol(n));
	printf("F_no_duplicate(%lld) = %zu\n", n, store.size());
	return 0;
}

