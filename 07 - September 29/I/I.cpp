#include<bits/stdc++.h>
using namespace std;

int main(){
	map<int, int> map;
	int t1,t2,t3,t4,t5,sum=0,maximo=-1;
	cin >> t1 >> t2 >> t3 >> t4 >> t5;
	vector<int> v;
	v.push_back(t1);
	v.push_back(t2);
	v.push_back(t3);
	v.push_back(t4);
	v.push_back(t5);
	map[t1]++;
	map[t2]++;
	map[t3]++;
	map[t4]++;
	map[t5]++;
	for (int i = 0; i < 5; ++i){
		if (map[v[i]] <2){
			map[v[i]] = 0;
		}else if(map[v[i]] >3){
			map[v[i]] = 3;
		}
	}

	
	sum = t1+t2+t3+t4+t5;
	if (map[t1] >1 || map[t2] >1 || map[t3] >1 || map[t4]>1 || map[t5] >1){
		//maximo = max(t1*map[t1], max(t2*map[t2], max(t3*map[t3], max(t4*map[t4], t5*map[t5]))));
		for (int i = 0; i < 5; ++i){
			maximo = max(maximo, v[i]*map[v[i]]);
		}
		/*for (int i = 0; i < 5; ++i){
			if (v[i] * map[v[i]] == maximo && map[v[i]] > 1){
				if (map[v[i]] == 2){
					sum-= v[i]*2;
				}else{
					sum-=v[i]*3;
				}
				break;
			}
		}*/
		sum -= maximo;
	}
	cout << sum << endl;
return 0; 
}