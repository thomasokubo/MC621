#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int i,j,k,aux;
	long long int l,r,x,y;
	bool found = false;
	cin >> l >> r >> x >> y >> k;

	i=x;
	while(i<=y && !found){
		if(k*i>=l && k*i<=r) found = true;
		i++;
	}

	if(found) 
        cout << "YES" << endl;
	else 
        cout << "NO" << endl;

	return 0;
}	