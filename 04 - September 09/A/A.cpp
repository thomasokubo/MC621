#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ll i,j,k,aux, a,b;

	cin >> a >> b;

	aux=1;
	for(i=2;i<=min(a,b);i++){
		aux *= i;
	}

	cout << aux << endl;
	return 0;
}
