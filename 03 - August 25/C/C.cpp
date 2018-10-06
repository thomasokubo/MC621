#include <bits/stdc++.h>
using namespace std;
vector<long long int> primes;
bitset<10000010> bs;
long long int tam = 10001000;

void sieve() {
  long long int i,j;
  bs.set();
  bs[0]=0;
  bs[1]=0;
  for(i=2; i<tam;i++){
    if(bs[i]){
      for(j=i*i;j<tam;j+=i)
        bs[j]=0;
    }
  }
  for(i=2;i<tam;i++)
    if(bs[i]) primes.push_back(i);
}


vector<long long int> primes_factor(long long int n){
  vector<long long int> factors;
  long long int index=0, pf = primes[index];

  while(n!=1 && pf*pf<=n){
    while(n%pf==0){
      n /= pf;
      factors.push_back(pf);
    }
    pf = primes[++index];
  }

  if(n!=1) factors.push_back(n);
  return factors;
}

long long int digit_sum(long long int n){
  int t = 1;
  long long soma = 0;
  while(n != 0){
    soma += n%10;
    n /= 10;
  }
  return soma;
}


int main(){

  long long int i,j,k,aux, n;
  vector<long long int> fac;
  cin >> n;

  sieve();

  for(i=0;i<n;i++){
    cin >> aux;
    bool found = false;
    long long soma1, soma2 = 0;

    while(!found){
      aux++;
      soma1 = digit_sum(aux);
      soma2 = 0;
      fac = primes_factor(aux);

      if (fac.size() == 1) continue;

      for(j=0;j<fac.size();j++){
        soma2 += digit_sum(fac[j]);
      }
      if(soma1 == soma2){
        found = true;
        cout << aux << endl;
      }
      fac.clear();
    }
  }

  return 0;
}
