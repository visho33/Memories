#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n, m, l;
	cin>>n>>m>>l;
	
	vector<vector<int> > bus(m, vector<int>(5));
	vector<int> casa;
	
	for(int i = 0; i<m; i++){
		int a, b, c, d, e;
		cin>>a>>b>>c>>d>>e;
		if(b!=n-1){
			cout<<"-1";
			return 0;
		}
		if(a==0){
			casa.push_back(i);
		}
		bus[i][0] = a;
		bus[i][1] = b;
		bus[i][2] = c;
		bus[i][3] = d;
		bus[i][4] = e;
	}
	
	int maxi = -1;
	for(int i = 0; i<casa.size(); i++){
		int aux = l;
		aux = aux - bus[casa[i]][2]- bus[casa[i]][3];
		if(aux<0){
			continue;
		}
		int q = aux/bus[casa[i]][4];
		maxi = max(maxi,bus[casa[i]][3]+ q*bus[casa[i]][4]);
	}
	
	cout<<maxi<<endl;
	
	return 0;
}
