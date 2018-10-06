#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > terra, terra2;

int main(){

	int i,j,k,aux;
	int n,r,c;

	cin >> n >> r >>c >> k;
	while(n||r||c||k){
		terra.resize(r);
		terra2.resize(r);

		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				cin >> aux;
				terra[i].push_back(aux);
				
			}
			terra2[i].assign(c, 0);
		}

		

		for(aux=1;aux<=k;aux++){
			if(aux%2!=0){
				for(i=0;i<r;i++){
					for(j=0;j<c;j++){
						bool found = false;
						terra2[i][j] = terra[i][j]; 

						if(i<r-1) {
							if(((terra[i+1][j]+1)%n) == terra[i][j] ) {
								terra2[i][j] = terra[i+1][j]; 
								found = true;
							}
								
						} 

						if(j<c-1  && !found){
							if(((terra[i][j+1]+1)%n) == terra[i][j]){
								terra2[i][j] = terra[i][j+1];
								found= true;
							}
								
						}

						if(i>0 && !found){
							if(((terra[i-1][j]+1)%n) == terra[i][j] ){
								terra2[i][j] = terra[i-1][j];
								found = true;
							}
								
						}
						if(j>0  && !found){
							if(((terra[i][j-1]+1)%n) == terra[i][j]){
								terra2[i][j] = terra[i][j-1]; 
							}
								
						}
						found = false;
					}
				}

		

			} else {

			
				for(i=0;i<r;i++){
					for(j=0;j<c;j++){
						bool found=false;
						terra[i][j] = terra2[i][j]; 
						if(i<r-1) {
							if(((terra2[i+1][j]+1)%n) == terra2[i][j]){
								terra[i][j] = terra2[i+1][j]; 
								found = true;
							}
								
						} 

						if(j<c-1  && !found){
							if(((terra2[i][j+1]+1)%n) == terra2[i][j]){
								terra[i][j] = terra2[i][j+1];
								found = true;
							}
								
						}

						if(i>0  && !found){
							if(((terra2[i-1][j]+1)%n) == terra2[i][j]){
								terra[i][j] = terra2[i-1][j];
								found = true;
							}
								
						}
						if(j>0  && !found){
							if(((terra2[i][j-1]+1)%n) == terra2[i][j]){
								terra[i][j] = terra2[i][j-1]; 
							}
								
						}
						found = false;
					}
				}
			}
		}

		if(k%2==0){

			for(i=0;i<r;i++){
				for(j=0;j<c;j++){
					cout << terra[i][j] << " " ;
				}
				cout << endl;
			}

		} else {
			for(i=0;i<r;i++){
				for(j=0;j<c;j++){
					cout << terra2[i][j]<< " ";
				}
				cout << endl;
			}

		}



		terra.clear();
		terra2.clear();
		cin >> n >> r>>c >> k;
	}

	return 0;
}