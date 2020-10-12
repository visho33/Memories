#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	int n, t;
	cin>>n>>t;
	
	ll puntaje;
	vector<ll> penalizacion;
	
	for(int i = 0; i<n; i++){
		ll a, b, c;
		cin>>a>>b>>c;
		penalizacion.push_back(b);
		puntaje = a;
	}
	penalizacion.push_back(0);
	
	sort(penalizacion.begin(), penalizacion.end());
	
	vector<int> xd(penalizacion.size());
	
	xd[0] = 0;
	for(int i = 1; i<xd.size(); i++){
		xd[i] = xd[i-1]+penalizacion[i];
	}
	
	ll x = min(t,n);
	
	ll sum = 0;
	ll tx = 1;
	int i = x;
	
	while(tx<=t && i>0){
		
		if(puntaje-tx*penalizacion[i]>xd[i-1]){
			sum+=(puntaje-tx*penalizacion[i]);
		}
		tx++;
		i--;
	}
	
	cout<<sum<<endl;
	
	return 0;
}
