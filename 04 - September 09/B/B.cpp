#include <bits/stdc++.h>
#define ll long long int
using namespace std;


vector<char> a, b;
vector< vector<ll> >dp;
int main(){

	ll i,j,k, m,n;
	char aux;

	cin >> n >> m;
	for(i=0; i< n;i++){
		cin >> aux;
		a.push_back(aux);
	}

	for(i=0; i< m;i++){
		cin >> aux;
		b.push_back(aux);
	}

	dp.resize(n+1);
	for(i=0;i<=n;i++){
		dp[i].assign(m+1, 0);
	}

	for(i=1;i<=n;i++){
		for(j=i;j<=m;j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
		}
	}

	ll min = 10001000;
	for(i=n; i<=m; i++){
		if(dp[n][i]<min ){
			min = dp[n][i];
			k = i;
		}
	}

	vector<ll> res;
	for(i=n; i>0; i--){
		if(a[i-1]!= b[k-1]){
			res.push_back(i);
		}
		k--;
	}

	cout << res.size() << endl;
	if(res.size()>0){
		for(i=res.size()-1;i>=0;i--){
			cout << res[i] << " ";
		}

		cout << endl;
	}
	return 0;
}