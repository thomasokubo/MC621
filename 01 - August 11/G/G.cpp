#include <bits/stdc++.h>
#define MAXN 10001000
using namespace std;

vector<pair <int,int> > w;
vector<int> s;
vector<int> res;
int l[MAXN], l_id[MAXN], p[MAXN];


void reconstruct(int end){
	int x = end;
	stack<int> st;
	for(; p[x]>=0; x = p[x]) st.push(w[x].second);
	res.push_back(w[x].second+1);
	for(; !st.empty(); st.pop()) res.push_back(st.top()+1); 
}

int main(){

	int i,j,k,aux;
	int a, b, lis=0, lis_id=0;

	k=0;
	while(cin >> a >> b){
		w.push_back(make_pair((-1)*a,k));
		s.push_back(b);
		k++;
	}

	sort(w.begin(), w.end());

	for(i=0;i<k;i++){
		aux = s[w[i].second];
		int pos = lower_bound(l, l+lis, aux) - l;
		l[pos] = aux;
		l_id[pos]= i;
		p[i] = pos?l_id[pos-1]:-1;

		if(pos+1 > lis){
			lis = pos+1;
			lis_id = i;
		}
	}

	cout << lis<< endl;
	reconstruct(lis_id);
	for(i=res.size()-1; i>=0; i--) cout << res[i] << endl;

	return 0;
}