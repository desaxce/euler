#include <pe.h>
#include <time.h>

const ll M = 201820182018ll;
// const ll M = 10000ll;

// We use k to separate in 3 blocks:
// - 1 --> k
// - k --> sqrt(M)
// - sqrt(M) --> M
// with 500 -> 631499044 (second run with ll s)
const ll k = 250ll;
// const ll k = 10ll;

vector<ll> primes;

ll s;

ll mod(ll u) {
  return (u%1000000000ll);
}

void hammingGeneralised(int indexP, int n, long long k) {
  if(k > M) return;
  
  s = mod(s+1);
  
  for (int i = n; i <= indexP ; i++) {
    hammingGeneralised(indexP, i, primes[i]*k);
  }
}

// Returns sum of arr[0..index]. This function assumes 
// that the array is preprocessed and partial sums of 
// array elements are stored in BITree[]. 
int getSum(int BITree[], int index) 
{ 

    int sum = 0; // Initialize result 
  
    // index in BITree[] is 1 more than the index in arr[] 
    index = index + 1; 
  
    // Traverse ancestors of BITree[index] 
    while (index>0) 
    { 
      // cout << "index = " << index << endl;
        // Add current element of BITree to sum 
      // cout << "size of BITree = " << sizeof(BITree) / sizeof(BITree[0]) << endl ;
        sum += BITree[index]; 
      // cout << "done with index "  << index << endl;
        // Move index to parent node in getSum View 
        index -= index & (-index); 
    } 
    return sum; 
} 

// Updates a node in Binary Index Tree (BITree) at given index 
// in BITree. The given value 'val' is added to BITree[i] and  
// all of its ancestors in tree. 
void updateBIT(int BITree[], int n, int index, int val) 
{ 
    // index in BITree[] is 1 more than the index in arr[] 
    index = index + 1; 
  
    // Traverse all ancestors and add 'val' 
    while (index <= n) 
    { 
    // Add 'val' to current node of BI Tree 
    BITree[index] += val; 
  
    // Update index to that of parent in update View 
    index += index & (-index); 
    } 
} 

// Constructs and returns a Binary Indexed Tree for given 
// array of size n. 
int *constructBITree(int arr[], int n) 
{ 
    // Create and initialize BITree[] as 0 
    int *BITree = new int[n+1]; 
    for (int i=1; i<=n; i++) 
        BITree[i] = 0; 
  
    // Store the actual values in BITree[] using update() 
    for (int i=0; i<n; i++) 
        updateBIT(BITree, n, i, arr[i]); 
  
    // Uncomment below lines to see contents of BITree[] 
    //for (int i=1; i<=n; i++) 
    //     cout << BITree[i] << " "; 
  
    return BITree; 
}   

int main() {
  ll resultat = 0;

  // **********
  // * PART 1 *
  // **********

  cout << "Starting PART 1..." << endl;
  // Store primes up to sqrt(M)
  primesieve::generate_primes(k-1, &primes);

  // cout << "Done Sieving" << endl;
  for (ll i = 0; i < primes.size(); i++) {
    cout << "P1 p = " << primes[i] << endl;
    s = 0;
    hammingGeneralised(i, 0, primes[i]);
    // cout << "\t s = " << s*primes[i] << endl;
    resultat = mod(resultat + mod(s*primes[i]));
  }

  // **********
  // * PART 2 *
  // **********

  cout << "Starting PART 2..." << endl;
  int* sieve = new int[M/k+1];
  for (int i = 0; i < M/k+1; i++) sieve[i] = 0;
  sieve[0] = 1;

  primesieve::iterator it;
  it.skipto(floor(sqrt(M)));
  ll prime;
  prime = it.next_prime();
  for (; prime < M/k+1; prime = it.next_prime()) {
    ll j = prime;
    while (j < M/k+1) {
      sieve[j] = 1;
      j += prime;
    }
  }

  // int nn = sizeof(sieve)/sizeof(sieve[0]);
  int nn = M/k+1;
  cout << "nn = " << nn << endl;
  int *BITree = constructBITree(sieve, nn);

  primes.clear();
  primesieve::generate_primes(k, floor(sqrt(M)), &primes);

  for (ll i = primes.size()-1; i >= 0; i--) {
    cout << "P2 p = " << primes[i] << endl;
    // for (int i = 0; i < M/k+1; i++) printf("%d ", sieve[i]);
    // cout << "Sum up to " << M/primes[i] << " = " << getSum(BITree, M/primes[i]) << endl;
    ll cnt = mod((M/primes[i]+1) - getSum(BITree, M/primes[i]));
    resultat = mod(resultat + mod(cnt*primes[i]));
    // cout << "Done getting sum" << endl;
    // cout << "\t cnt = " << cnt << endl;
    // cout << "\t s = " << cnt*primes[i] << endl;

    ll j = primes[i];
    while (j < M/k+1) {
      // cout << "Updating bit number " << j << endl;
      // cout << "j = " << j << " ";
      if (sieve[j] == 0) {
        sieve[j] = 1;
        updateBIT(BITree, nn, j, 1);
      }
      j+=primes[i];
    }
  }

  // **********
  // * PART 3 *
  // **********

  cout << "Starting PART 3..." << endl;
  it.skipto(floor(sqrt(M)));
  prime = it.next_prime();

  for (; prime < M; prime = it.next_prime()) {
    // cout << "P3 p = " << prime;
    resultat = mod(resultat + mod(prime*(M/prime)));
    // cout << "\t s = " << prime*(M/prime) << endl;
  }

  cout << resultat << endl;
  return 0;
}
