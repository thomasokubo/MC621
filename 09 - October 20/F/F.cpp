#include <bits/stdc++.h>
using namespace std;

int n,m,x,y,k,counter=0;
vector<vector<int>> g;

void path(int a, int b){
	if(a<1 || b<1 || a>n || b>m) return;
	if(g[a][b]) return;
	g[a][b] = 1;
	counter++;
	path(a+1, b);
	path(a-1, b);
	path(a, b+1);
	path(a, b-1);
	path(a+1, b+1);
	path(a+1, b-1);
	path(a-1, b+1);
	path(a-1, b-1);
}


int main(){

	cin >> n >> m >> x >> y >> k;
	g.resize(n+1);
	for(int i=0;i<=n;i++)
		g[i].assign(m+1, 0);
	
	for(int i=0;i<k;i++){
		int a, b;
		cin >> a >> b;
		g[a][b] = 1;
	}

	path(x, y);
	cout << counter << endl;


	return 0;
}