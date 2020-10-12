#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){
	
	int n;
	cin>>n;
	vector<vector<int> > corredores;
	priority_queue<ii,vector<ii>,greater<ii> > q;
	vector<int> avanzar(n);
	
	for(int i = 0; i<n; i++){
		int a, ba, c;
		cin>>a>>ba>>c;
		vector<int> b;
		b.push_back(a);
		b.push_back(ba);
		b.push_back(c);
		corredores.push_back(b);
		avanzar[n] = a;
	}
	
	vector<bool> turbito(300,false);
	vector<int> turbito2(300,0);
	int m;
	cin>>m;
	for(int i = 0; i<m; i++){
		int c; cin>>c;
		turbito[c] = true;
	}
	
	int llegue = 0;
	vector<int> tiempo(n);
	vector<int> pos(n,0);
	vector<int> turbo(n);
	
	for(int i = 0; i<n; i++){
		avanzar[i] = corredores[i][0];
	}
	
	int k = 1;
	while(llegue!=n){
		vector<int> turbito3(300,0);
		for(int i = 0; i<n; i++){
			
			if(pos[i]==300){
				continue;
			}
			
			if(turbo[i]>0){	
				pos[i]++;
				
				if(pos[i]==300){
					tiempo[i] = k;
					llegue++;
				}
				
				if(turbo[i]==1){
					int h = pos[i]/100;
					avanzar[i] = corredores[i][h];
				}
				
				turbo[i]--;
				continue;
			}
			
			avanzar[i]--;
			
			if(avanzar[i] == 0){
				pos[i]++;
				
				if(pos[i]==300){
					tiempo[i] = k;
					llegue++;
				}
				
				if(turbito[pos[i]] == true){
					turbo[i] = turbito2[pos[i]]%20;
					turbito3[pos[i]]++;
				}
				int h = pos[i]/100;
				avanzar[i] = corredores[i][h];
				
			}
			
		}
		k++;
		for(int i = 0; i<300; i++){
			turbito2[i]+=turbito3[i];
		}
	}
	
	
	for(int i = 0; i<n; i++){
		cout<<tiempo[i]<<endl;
	}
	
	return 0;
}
