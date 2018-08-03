#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000100010001000
int main(){

	long long int i,j,k,aux, n,a ,b;
	vector<long long int> primes;
	bitset<10000010> bs;

	bs.set();
	bs[0] = 0;
	bs[1] = 0;

	for(i=2;i<1000001; i++){
		if(bs[i]){
			for(j=i*i; j<MAXN; j*=i)
				primes.push_back(j);
			
			for(j=i*i; j<1000001;j+=i)
				bs[j] = 0;
		}
	}

	cin >> n;
	sort(primes.begin(), primes.end());
	for(i=0;i<n;i++){
		cin >> a >> b;
		long long int low = lower_bound(primes.begin(), primes.end(), a)-primes.begin();
		long long int high = lower_bound(primes.begin(), primes.end(), b)-primes.begin();
		if(high==primes.size() || primes[high]!=b)
			high--;
		
		cout << high - low +1 << endl;
	}

	return 0;
}