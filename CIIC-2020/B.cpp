#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll ultima_salida(ll peso, ll inicio, ll frecuencia, ll largo){
	
	ll aux = peso;
	aux = aux - largo - inicio;
	if(aux<0){
		return -1;
	}
	ll q = aux/frecuencia;
	
	return inicio+q*frecuencia;
}

int main(){
	//dsjklsadjlasddsjksad
	int n, m;
	long long l;
	cin>>n>>m>>l;
	
	vector<ll> peso(n, -1);
	vector<vector<long long> > bus(m, vector<long long>(3));
	vector<vector<pair<int,int> > > edges(n);
	
	for(int i = 0; i<m; i++){
		int a, b;
		long long c, d, e;
		cin>>a>>b>>c>>d>>e;
		bus[i][0] = c;
		bus[i][1] = d;
		bus[i][2] = e;
		
		pair<int, int> x(a, i);
		edges[b].push_back(x);
	}
	
	priority_queue<ii> q;
	pair<ll, int> inicial(l, n-1);
	q.push(inicial);
	
	while(q.size()>0){
		pair<ll,int> x = q.top();
		q.pop();
		ll pesox = x.first;
		int nodo = x.second;
		
		for(int i = 0; i<edges[nodo].size(); i++){
			
			if(peso[edges[nodo][i].first]<ultima_salida(pesox, bus[edges[nodo][i].second][1], bus[edges[nodo][i].second][2], bus[edges[nodo][i].second][0])){
				peso[edges[nodo][i].first] = ultima_salida(pesox, bus[edges[nodo][i].second][1], bus[edges[nodo][i].second][2], bus[edges[nodo][i].second][0]);
				pair<ll,int> nuevo(peso[edges[nodo][i].first], edges[nodo][i].first);
				q.push(nuevo);
			}
			
		}
		
	}
	
	cout<<peso[0]<<endl;
	
	return 0;
}
