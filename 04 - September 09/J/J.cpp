#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<bool> visited;
int main(){
	ll i,j,k,aux, n;

	cin >> n;
	while(n){
		visited.assign(100000, false);
		aux = 0;

		while(!visited[n]){
			aux++;
			visited[n] = true;
			n = n*n;
			n %= 1000000;
			n /= 100;
		}
		cout << aux << endl;
		cin >> n;
		visited.clear();
	}

	return 0;
}