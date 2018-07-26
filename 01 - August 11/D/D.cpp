#include <bits/stdc++.h>
using namespace std;

string line;
vector<char> a;
vector<char> b;
int main(){

	int i,j,k,aux;
	char x;

	getline(cin ,line);
	while(line[0]!='*'){
		i=0;
		for(i=0; i<line.size()/2; i++){
			a.push_back(line[i]);
		}

		for(i=(line.size()/2)+1; i<line.size();i++) {
			b.push_back(line[i]);
		}

		k=0;
		aux=0;
		for(i=0;i<a.size();i++){

			if(k==0 && a[i] != b[i]) {

				k=1;
				aux++;
			} else if(a[i] == b[i]){
				k=0;
			}
		}

		cout << aux << endl;
		a.clear();
		b.clear();


		getline(cin ,line);
	}

	return 0;

}