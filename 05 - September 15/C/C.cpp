#include <bits/stdc++.h>
using namespace std;

#define MAXN 10001000
#define left(i) (i<<1)
#define right(i) ((i<<1)+1)
#define ll long long int

ll tree[MAXN], lazy[MAXN], arr[MAXN];

void update_tree(ll node, ll start, ll end, ll l, ll r, ll val){
	if(lazy[node]!=0){
		tree[node] += (end-start+1)*lazy[node];
		if(start!=end)		{
			lazy[left(node)] += lazy[node];
			lazy[right(node)] += lazy[node];
		}

		lazy[node] = 0;
	}

	if(start>end || start>r || end<l) return;

	if(start>=l && end<=r){
		tree[node] += (end-start+1)*val;
		if(start!=end){
			lazy[left(node)] += val;
			lazy[right(node)] += val;
		}

		return;
	}

	ll mid = (start+end)/2;
	update_tree(left(node), start, mid, l, r,val);
	update_tree(right(node), mid+1, end, l, r,val);

	tree[node] = tree[left(node)] + tree[right(node)];

}


ll query_tree(ll node, ll start, ll end, ll l, ll r){

	if(start>end || start>r || end<l) return 0;

	if(lazy[node]!=0){
		tree[node] += (end-start+1)*lazy[node];
		if(start!=end){
			lazy[left(node)] += lazy[node];
			lazy[right(node)] += lazy[node];
		}

		lazy[node] = 0;
	}

	if(start>=l && end <= r) return tree[node];

	ll mid = (start+end)/2;

	ll p1 = query_tree(left(node), start, mid, l, r);
	ll p2 = query_tree(right(node),mid+1, end, l, r);

	return p1+p2;
}

int main(){
	ll i,j,k,aux;
	ll t, n, c, v, p, q;

	cin >> t;
	while(t--){

		memset(tree, 0, sizeof tree);
		memset(lazy, 0, sizeof lazy);
		cin >> n >> c;
		for(i=0;i<c;i++){
			cin >> aux;
			if(!aux){
				cin >> p >> q>> v;
				update_tree(1, 1, n, p, q, v);
			} else {
				cin >> p >> q;
				cout << query_tree(1, 1, n, p, q) <<endl;
			}
		}
	}

	return 0;
}