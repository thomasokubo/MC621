#include <bits/stdc++.h>

using namespace std;

vector<string> res;
int main(){

	int i,j,k;
	int t, n, lxh, hhb, temp;
	string aux;

	cin >> t;
	while(t--){
		lxh=0;
		hhb=0;
		cin >> n;
		if(n>0) {
			cin >> aux;
			if(aux == "lxh") temp=1;
			else temp = 0;
			k = temp;
		}

		for(i=1;i<n;i++){
			cin >> aux;
			if(aux == "lxh") temp=1;
			else temp = 0;
			k ^= temp;
		}

		if(k) cout << "lxh";
		else cout << "hhb";

		cout << endl;
		
	}
}