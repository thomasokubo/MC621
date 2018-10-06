#include <bits/stdc++.h>
using namespace std;


vector< vector<char> > mat;
vector<string> w;
string line;
int p, q;


bool buscaUp(int i,int j, int n){
	if(n==0)
		p = i, q = j;

	if(i<0 || n>=line.size())
		return false;
	
	
	if(mat[i][j]==line[n]){
		if(n == line.size()-1){		
			return true;
		} else {
			return buscaUp(i-1, j, n+1);
		}
	} else {
		return false;
	}

}

bool buscaDown(int i,int j, int n){
	if(n==0)
		p = i, q = j;
	if(i>=mat.size() ||n>=line.size())
		return false;
	

	if(mat[i][j]==line[n]){
		if(n == line.size()-1){
		
			return true;
		} else {
			return buscaDown(i+1, j, n+1);
		}
	} else {
		return false;
	}

}

bool buscaRight(int i,int j, int n){
	if(n==0)
		p = i, q = j;
	if(j>=mat[i].size()||n>=line.size())
		return false;
	
	if(mat[i][j]==line[n]){
		if(n == line.size()-1){
			
			return true;
		} else {
			return buscaRight(i, j+1, n+1);
		}
	} else {
		return false;
	}

}

bool buscaLeft(int i,int j, int n){
	if(n==0)
		p = i, q = j;
	if(j<0||n>=line.size())
		return false;
	
	if(mat[i][j]==line[n]){
		if(n == line.size()-1){
			return true;
		} else {
			return buscaLeft(i, j-1, n+1);
		}
	} else {
		return false;
	}

}

bool buscaUR(int i,int j, int n){
	if(n==0)
		p = i, q = j;
	if(i<0 || i>=mat.size() || j<0 || j>=mat[i].size()|| n>=line.size())
		return false;
	
	if(mat[i][j]==line[n]){
		if(n == line.size()-1){

			return true;
		} else {
			return buscaUR(i-1, j+1, n+1);
		}
	} else {
		return false;
	}

}

bool buscaUL(int i,int j, int n){
	if(n==0)
		p = i, q = j;
	if(i<0 || i>=mat.size() || j<0 || j>=mat[i].size()||n>=line.size())
		return false;
	
	if(mat[i][j]==line[n]){
		if(n == line.size()-1){
			
			return true;
		} else {
			return buscaUL(i-1, j-1, n+1);
		}
	} else {
		return false;
	}
	
}

bool buscaDR(int i,int j, int n){
	if(n==0)
		p = i, q = j;
	if(i>=mat.size() || j>=mat[i].size()|| n>=line.size())
		return false;
	
	//cout << line[n];
	if(mat[i][j]==line[n]){
		if(n == line.size()-1){

			return true;
		} else {
			return buscaDR(i+1, j+1, n+1);
		}
	} else {
		return false;
	}
	
}
bool buscaDL(int i,int j, int n){
	if(n==0)
		p = i, q = j;
	if(i<0 || i>=mat.size() || j<0 || j>=mat[i].size()||n>=line.size())
		return false;
	
	if(mat[i][j]==line[n]){
		if(n == line.size()-1){

			return true;
		} else {
			return buscaDL(i+1, j-1, n+1);
		}
	} else {
		return false;
	}
	
}

int main(){

	int i,j,k;
	int t, n, m;
	char aux;


	cin >> t;
	while(t--){
		getline(cin,line);
		line.clear();
		cin >> n >> m;

		mat.resize(n);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				cin >> aux;
				mat[i].push_back(tolower(aux));
			}
		}

		cin >> k;
		getline(cin,line);
		line.clear();
		for(i=0;i<k;i++){
			getline(cin,line);
			w.push_back(line);
			line.clear();
		}



		for(int words=0;words<w.size();words++){
			line.clear();
			line = w[words];
			for(i=0;i<line.size();i++)
				line[i] = tolower(line[i]) ;
			bool found =false;

			for(i=0;i<n && !found;i++){
				for(j=0;j<m && !found;j++){
					found = true;
					if(buscaUp(i,j,0)) {
						cout << p+1 << " " << q+1<< endl;
					} else if (buscaDown(i,j,0)){
						cout << p+1 << " " << q+1<< endl;
					} else if(buscaLeft(i,j,0)){
						cout << p+1 << " " << q+1<< endl;

					} else if(buscaRight(i,j,0)){
						cout << p+1 << " " << q+1<< endl;

					} else if(buscaUL(i,j,0)){
						cout << p+1 << " " << q+1<< endl;

					} else if(buscaUR(i,j,0)){
						cout << p+1 << " " << q+1<< endl;

					} else if(buscaDL(i,j,0)){
						cout << p+1 << " " << q+1<< endl;

					} else if(buscaDR(i,j,0)){
						cout << p+1 << " " << q+1<< endl;
						
					} else {
						found = false;
					}
						
				}
			}
		}
		if(t>0)
			cout << endl;
		mat.clear();
		w.clear();
	}
	return 0;
}
