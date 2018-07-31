#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > g;
vector<int> danger;
int n, m, counter=0;

void path(int a, int b){
	if(a==n && b==m){
		counter++;
	} 
	if(a<n && g[a+1][b] != -1){
		path(a+1,b);
	} 
	if(b<m && g[a][b+1] != -1){
		path(a,b+1);	
	}
}

int main(){
	int i,j,k,aux, t;
	int a,b, ncases;
	string line;

	cin >> ncases;
	for(k=0; k<ncases;k++){
		getline(cin, line);
		cin >> n >> m;
		g.resize(n+1);
		for(i=0;i<=n;i++){
			g[i].assign(m+1, 0);
		}

		getline(cin, line);
		for(i=0;i<n;i++){
			j=0;
			
			danger.assign(10001000, 0);

			line.clear();
			getline(cin, line);

			stringstream in(line);
			while(in >> danger[j++]);
			aux = danger[0];
			for(t=1; t<j; t++){
				g[aux][danger[t]] = -1;
			}
		}

		counter = 0;
		path(1,1);
		cout << counter << endl;
		if(k<ncases-1) cout << endl;
		g.clear();
		danger.clear();

	}

	return 0;
}