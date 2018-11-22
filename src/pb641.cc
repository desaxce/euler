#include <pe.h>

// ll N = 100;
// ll N4;
// ll N6;
ll N6 = 1000000ll;
ll N4 = 1000000000ll;
vector<ll> primes;
vector<ll> allVals;

ll s;

ll coutner = 0;
bool hammingGeneralised(int indexP, bool isEven, int n, long long k) {
  if(k > N4) return false;
  
  if (isEven) {
    // if (coutner++%100000 == 0) {
    //   printf("%lld\n", s);
    // }
    s += floor(N6/pow(k, 2/3.));
  }

  bool continuer = true;
  // n+1 because it's forbidden to reuse the same prime number
  for (int i = n; i < indexP && continuer ; i++) {
    continuer = hammingGeneralised(indexP, k==1?false:!isEven, i+1, primes[i]*k);
  }
  return true;
}

int main() {
  // N6 = floor(pow(N, 1/6.));
  // N4 = floor(pow(N, 1/4.));

  primesieve::generate_primes(N4, &primes);

  s = 1;

  hammingGeneralised(primes.size()-1, true, 0, 1);

  // In case of 10**8 you have to add one to the result
  // check the problems at the limits
  cout << s << endl;
  return 0;
}
