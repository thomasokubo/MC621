#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll counter =0;
ll gcd(ll a, ll b){
	if(b)counter += (ll)((ll)a/(ll)b);
	return (b==0?a:(gcd(b, a%b)));
}

int main(){

	ll i,j,k,aux, a,b;

	cin >> a >> b;
	gcd(a, b);

	cout << counter << endl;

	return 0;
}