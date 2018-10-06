#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> gen;
vector<ll> ind;
int main(){

	ll i,j,k,aux;
	ll n, r,a,b,q, c=1;

	cin >> n;

	while(n){
		for(i=0;i<=n;i++){
			gen.push_back(i);
			ind.push_back(i);
		}
		cin >> r;
		for(i=0;i<r;i++){
			cin >> a >> b;
			k=b;
			for(j=a;j<=(a+b)/2;j++){
				ind[gen[j]] = k;
				ind[gen[k]] = j;
				aux = gen[j];
				gen[j] = gen[k];
				gen[k] = aux;
				k--;
			}
		}

		cout << "Genome " << c++ << endl;
		cin >> q;
		for(i=0;i<q;i++){
			cin >> aux;
			cout << ind[aux] << endl;
		}

		gen.clear();
		ind.clear();
		cin >> n;
	}


	return 0;
}