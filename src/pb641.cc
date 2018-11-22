#include <pe.h>

// ll N = 100000000;
ll N6 = 1000000ll;
ll N4 = 1000000000ll;
vector<ll> primes;
vector<ll> allVals;

ll M;
ll temp;
ll s;

ll mod(ll u) {
  return (u%1000000000ll);
}

void hammingGeneralised(int indexP, bool isEven, int n, long long k) {
  if(k > M) return;
  
  if (isEven) {
    // cout << "Good h = " << k << endl;
    // allVals.push_back(pow(temp, 6)*pow(k, 4));
    s++;
  }

  // n+1 because it's forbidden to reuse the same prime number
  for (int i = n; i < indexP ; i++) {
    hammingGeneralised(indexP, k==1?false:!isEven, i+1, primes[i]*k);
  }
}

int main() {
  ll resultat = 0;
  // N6 = floor(pow(N, 1/6.));
  // N4 = floor(pow(N, 1/4.));
  primesieve::generate_primes(N4, &primes);

  // for (int i = 0; i < primes.size(); i++) printf("%lld, ", primes[i]);
    // cout << endl;
  // cout << "Max k = " << floor(pow(N, 1/6.)) << endl;
  for (ll k = 250; k <= N6; k++) {

    cout << "Processing k = " << k << endl;
    // temp = k;
    // Remove the factors of k from primes
    // vector<ll> factorsk;
    // vector<ll> indicesk;
    // ll j = 0;
    // while (primes[j] <= k) {
    //   if (k%primes[j] == 0) {
    //     factorsk.push_back(primes[j]);
    //     indicesk.push_back(j);
    //     cout << "Retirons " << primes[j] << " de la liste des nombres premiers"<< endl;
    //     primes.erase(primes.begin() + j);
    //     j--;
    //   }
    //   j++;
    // }

    // for (int i = 0; i < primes.size(); i++) printf("%lld, ", primes[i]); cout << endl;
    ll hmax = floor(N4/(1.*pow(k, 3/2.)));
    // if (hmax < 2) continue;
    // cout << "hmax = " << hmax << endl;
    int indexP = (int) (upper_bound(primes.begin(), primes.end(), hmax) - primes.begin());
    if (indexP > 0) {
      indexP--;
    }
    // cout << "indexP = " << indexP << endl;
    // cout << "p = " << primes[indexP] << endl;
    M = hmax;
    s = 0;
    hammingGeneralised(indexP, true, 0, 1);
    resultat += s;
    // cout << "Adding " << s << " to the total" << endl;

    // Reput the factors of k in primes
  //   for (int i = indicesk.size()-1; i >=0; i--) {
  //     ll j = indicesk[i];
  //     ll p = factorsk[i];
  //     primes.insert(primes.begin()+j, p);
  //     cout << "Remettons " << p << " dans la liste des nombres premiers" << endl;
  //   }
  //   for (int i = 0; i < primes.size(); i++) printf("%lld, ", primes[i]); cout << endl << endl;
  }

  cout << resultat << endl;
  // cout << allVals.size() << endl;
  // sort(allVals.begin(), allVals.end());
  // for (int i = 0; i < allVals.size(); i++) cout << allVals[i] << endl;
  return 0;
}
