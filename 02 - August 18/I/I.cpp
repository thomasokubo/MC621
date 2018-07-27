#include <bits/stdc++.h>
using namespace std;

int main(){

	int i,j,k,aux;
	long long int soma;
	string line;

	cin >> aux;
	getline(cin, line);
	for(i=0;i<aux;i++){
		line.clear();
		getline(cin, line);
		soma = 0;
		k=0;
		for(j=0;j<line.size();j++){
			if(line[j]=='O'){
				k++;
				soma+=k;
			} else {
				k=0;
			}
		}
		cout << soma << endl;
	}

	return 0;
}