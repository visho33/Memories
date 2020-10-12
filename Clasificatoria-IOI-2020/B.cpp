#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n, m;
	cin>>n>>m;
	
	vector<vector<int> > verde(n, vector<int>(m));
	vector<vector<int> > amarilla(n,vector<int>(m));
	vector<vector<int> > rojas(0);
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			char c; cin>>c;
			if(j>0){
				verde[i][j] = verde[i][j-1];
			}
			else{
				verde[i][j] = 0;
			}
			if(i>0){
				amarilla[i][j] = amarilla[i-1][j];
			}
			else{
				amarilla[i][j] = 0;
			}
			if(c=='R'){
				vector<int> b;
				b.push_back(i);
				b.push_back(j);
				rojas.push_back(b);
			}
			if(c=='V'){
					verde[i][j]++;
				
			}
			if(c=='A'){
					amarilla[i][j]++;
				
			}
		}
	}
	
	
	long long suma = 0;
	
	for(int i = 0; i<rojas.size();i++){
		int amari = amarilla[n-1][rojas[i][1]] - amarilla[rojas[i][0]][rojas[i][1]];
		int ver = verde[rojas[i][0]][m-1] - verde[rojas[i][0]][rojas[i][1]];
		suma = suma + amari*ver;
	}
	cout<<suma<<endl;
	
	return 0;
}
