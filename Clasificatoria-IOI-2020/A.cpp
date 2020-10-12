#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > dp;
vector<pair<int,int> > foto2;
vector<pair<int,int> > foto;
vector<int> marco;
int DP(int n, int m){
	
	if(dp[n][m]!=-1){
		return dp[n][m];
	}
	
	if(marco[m-1]>=foto[n-1].second){
		dp[n][m] = max(DP(n-1, m-1) + 1, DP(n, m-1));
		dp[n][m] = max(DP(n-1,m), dp[n][m]);
		
		return dp[n][m];
	}
	
	dp[n][m] = max(DP(n-1,m), DP(n,m-1));
	return dp[n][m];
	
}

int main(){
	
	int n, m;
	cin>>n>>m;
	
	dp.resize(n+1,vector<int>(m+1,-1));
	
	for(int i = 0; i<n; i++){
		int a, b;
		cin>>a>>b;
		pair<int, int> x(a,b);
		foto2.push_back(x);
	}
	sort(foto2.begin(),foto2.end());
	
	for(int i = n-1; i>=0; i--){
		int a = foto2[i].first;
		int b = foto2[i].second;
		pair<int,int> x(b,a);
		foto.push_back(x);
	}
	
	stable_sort(foto.begin(),foto.end());
	
	for(int i = 0; i<m; i++){
		int a;
		cin>>a;
		marco.push_back(a);
	}
	sort(marco.begin(), marco.end());
	
	dp[0][0] = 0;
	for(int i = 0; i<=n; i++){
		dp[i][0] = 0;
	}
	for(int i = 0; i<=m; i++){
		dp[0][i] = 0;
	}
	
	cout<<DP(n,m);
	
	return 0;
}
