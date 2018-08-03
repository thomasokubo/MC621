#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > bus;
int main(){
	int i,j,k,aux, p;
	int n;

	bus.resize(3);
	for(i=0;i<3;i++)
		bus[i].assign(11, 0);
	
	cin >> n;
	p=n;
	if(n>2)
		n--;
	for(j=0; j<11;j++){
		for(i=0;i<3;i++){
			if(n-->0)
				bus[i][j] = 1;

		}
	}

	cout << "+------------------------+" << endl;

	cout <<'|';
	for(i=0;i<11;i++){
		if(bus[0][i]) cout << "O.";
		else cout << "#.";
	}
	cout << "|D|)" << endl;

	cout <<'|';
	for(i=0;i<11;i++){
		if(bus[1][i]) cout << "O.";
			else cout << "#.";	
	}
	cout << "|.|" << endl;

	if(p>=3)
		cout << "|O.......................|" << endl;
	else 
		cout << "|#.......................|" << endl;

	cout <<'|';
	for(i=0;i<11;i++){
		if(bus[2][i]) cout << "O.";
		else cout << "#.";	
	}
	cout << "|.|)" << endl;
	cout << "+------------------------+";
	return 0;
}