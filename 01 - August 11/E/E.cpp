#include <bits/stdc++.h>
using namespace std;

vector<long long int> res;
int main(){

	long long int i,j,k,aux;
	long long int n, m, soma;

	cin >> n >> m;
	while(n!=-1 || m!=-1){
		int x = m;	
		soma = 0;
		for(i=0;i<n;i++){
			cin >> aux;
			soma += aux*(n-i);
		}
		
		res.push_back(soma*x);

		cin >> n >> m;
	}
	for(i=0;i<res.size();i++)
		cout << res[i]<< endl;

	return 0;
}