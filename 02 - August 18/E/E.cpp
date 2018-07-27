#include <bits/stdc++.h>
using namespace std;

vector<long long int> x;
vector<long long int> y;
int main(){

	long long int i,j,k,p,aux;

	x.push_back(0);
	x.push_back(1);
	x.push_back(1);
	x.push_back(2);
	y.push_back(0);
	y.push_back(0);
	y.push_back(2);
	y.push_back(6);

	p=6;

	for(i=4;i<13;i++){
		x.push_back((i-1)*(x[i-1]+x[i-2]));
		y.push_back(p*i);
		p *= i;
	}

	cin >> aux;
	for(i=0;i<aux;i++){
		cin >> k;
		cout << x[k] << '/' << y[k] << endl;
	}

	return 0;
}