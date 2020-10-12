#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	int n, t;
	cin>>n>>t;
	
	vector<vector<ll> > p;
	vector<int> indices;
	
	for(int i = 0; i<n; i++){
		ll a, b, c; // puntaje, factor, tiempo
		cin>>a>>b>>c;
		vector<ll> d;
		d.push_back(a);
		d.push_back(b);
		d.push_back(c);
		p.push_back(d);
		indices.push_back(i);
	}
	
	ll maxi = 0;
	
	do{
		ll tiempo = 0;
		ll sum = 0;
		ll x = 0;
		
		for(int i = 0; i<indices.size(); i++){
			if(tiempo+p[indices[i]][2]<=t){
				tiempo = tiempo +p[indices[i]][2];
				sum = sum + max(p[indices[i]][0]- tiempo*p[indices[i]][1], x);
			}
			else{
				break;
			}
		}
		
		
		maxi = max(maxi, sum);
			
	}while(next_permutation(indices.begin(), indices.end()));
	
	cout<<maxi<<endl;
	
	return 0;
}
