#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;

ll _sieve_size;
bitset<10000005> bs;
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

set<int> primeFactors(int n) {
    set<int> factors;
    ll pf_idx = 0;
    ll pf = primes[pf_idx];
    while (n != 1 && (pf * pf <= n)) {
        while (n % pf == 0) {
            n /= pf;
            factors.insert(pf);
        }
        pf = primes[++pf_idx];
    }

    if (n != 1) {
        factors.insert(n);
    }

    return factors;
}

int pai[1000006];

void modifyPai(int node, int dad) {
    if (pai[node] != node) modifyPai(pai[node], dad);

    pai[node] = dad;
}

int main() {
    int t;
    scanf ("%d", &t);

    sieve((long)1e6+5);

    for (int i = 1; i <= t; i++) {
        int n, aux, cont = 0;
        scanf ("%d", &n);

        set<int> values;

        for (int j = 0; j < (int) 1e6+3; j++) {
            pai[j] = j;
        }

        bitset<1000006> visit;
        visit.set();
        for (int j = 0; j < n; j++) {
          scanf ("%d", &aux);

          if (aux == 1) cont++;
          else {
              visit[aux] = 0;
              values.insert(aux);
          }
        }

        for (set<int>::iterator it = values.begin(); it != values.end(); it++) {
            set<int> vi = primeFactors(*it);
            for (set<int>::iterator it2 = vi.begin(); it2 != vi.end(); it2++) {
                modifyPai(*it2, *it);
            }
        }

        for (int i = 0; i < (int) 1e6+3; i++) {
            if (visit[i] == 0 && pai[i] == i) cont++;
        }

        printf("Case %lld: %lld\n", i, cont);
    }

    return 0;
}
