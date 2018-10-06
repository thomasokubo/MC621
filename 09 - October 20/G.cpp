#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, b;
	vector<int> balls;

	cin >> n >> b;
	while(n || b) {
		for(int i=0;i<b; i++){
			int aux;
			cin >> aux;
			balls.push_back(aux);
		}
		bool ok = true;
		int k;
		for(k=0; k<=n && ok;k++){
			ok=false;
			for(int i=0;i<b;i++){
				for(int j=i;j<b;j++){
					if(abs(balls[i]-balls[j]) == k) ok = true;
				}
			}
		}
		if(ok) cout << "Y" << endl;
		else cout << "N" << endl;
		balls.clear();
		cin >> n >> b;
	}


	return 0;
}

