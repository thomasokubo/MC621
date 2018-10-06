#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;

ll _sieve_size;
bitset<10000000> bs;
vi primes;

void sieve(ll upperbound) {
  _sieve_size = upperbound +1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i <= _sieve_size; i++)
    if (bs[i]) {
      for (ll j = i * i; j<= _sieve_size; j+=i) bs[j] = 0;
      primes.push_back((int) i);
    }
}


ll eulerPhi(ll n) {
    ll pf_idx = 0, pf = primes[pf_idx], ans = n;
    while (n != 1 && (pf * pf <= n)) {
        if (n % pf == 0) ans -= ans / pf;
        while (n % pf == 0) n /= pf;
        pf = primes[++pf_idx];
    }

    if (n != 1) ans -= ans / n;
    return ans;
}

int main(){
  int cont;
  long long int n;

  sieve(5000000);

  while(scanf("%lld", &n) != EOF){
    cont = 1;

    cont += eulerPhi(n) / 2 - 1;

    cout << cont << endl;
  }
  return 0;
}
