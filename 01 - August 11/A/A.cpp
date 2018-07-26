#include <bits/stdc++.h>
using namespace std;

vector<int> jump;
int mdc(int a, int b){
	return b==0?a:mdc(b, a%b);
}
int main(){

	int i,j,k,aux;
	int n,x;

	cin >> n >> x;
	for(i=0;i<n;i++){
		cin >> aux;
		jump.push_back(aux);
	}

	int m = mdc(jump[0], jump[0]);
	for(i=1;i<n;i++){
		m = mdc(m, jump[i]);
	}
	if(x%m == 0){
		cout << "YES" << endl;
	} else{
		cout << "NO" << endl;
	}

	return 0;
}