#include <bits/stdc++.h>
using namespace std;
#define MAXN 10001000

string P, T,line;
long long int b[MAXN], n, m, big;

void kmpPreprocess(){
    long long int i=0, j=-1;
    b[0] = -1;
    m = P.size();
    while(i<m){
        while(j>=0 && P[i]!=P[j]) j = b[j];
        i++;
        j++;
        b[i] = j;
    }
}

int kmpSearch(){
    long long int i=0, j=0, big = 0, index=0;
    n = T.size();
    while(i<n){
        while(j>=0 && T[i]!=P[j]) j = b[j];
        i++;
        j++;

    }
    return j;
}

int main(){

    long long int i,j,k;
    getline(cin, T);
    while(T.size() > 0){
        P = string(T.rbegin(), T.rend());
        kmpPreprocess();

        int res = kmpSearch()+1;

        for(i=0;i<T.size();i++)
            cout << T[i];

        for(i=T.size()-res; i>=0;i--)
            cout << T[i];
 
        cout << endl;

        T.clear();
        P.clear();
        getline(cin, T);
    }

    return 0;
}