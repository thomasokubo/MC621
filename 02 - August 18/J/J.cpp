#include <bits/stdc++.h>
using namespace std;

int gcd(long long int a, long long int b){
	return b==0? a:gcd(b, a%b);
}

int lcm(long long int a, long long int b){
	int temp = gcd(a, b);
	return temp? (a/temp*b):0;
}

int main(){

	long long int i,j,k,x,y,a,b,aux;
	cin >> x>> y >> a >>b;

	if(x>y) swap(x,y);
	aux = lcm(y ,x);

	if(a%aux == 0){
		cout << (b/aux)-(a/aux) +1<< endl;
	} else {
		cout << (b/aux)-(a/aux) << endl;
	}

	return 0;
}