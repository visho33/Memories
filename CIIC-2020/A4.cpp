#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll> > dp(1001, vector<ll>(2001,-1));
vector<int> puntaje(1001);
vector<int> tiempo(1001);

ll DP(int n, int k){
	
	if(dp[n][k]!=-1){
		return dp[n][k];
	}
	
	if(k-tiempo[n]>=0){
		dp[n][k] = max(DP(n-1, k), DP(n-1, k-tiempo[n]) + puntaje[n]);
	}
	else{
		dp[n][k] = DP(n-1, k);
	}
	
	return dp[n][k];
}

int main(){
	
	int n, t;
	cin>>n>>t;
	
	for(int i = 1; i<=n; i++){
		ll a, b, c;
		cin>>a>>b>>c;
		puntaje[i] = a;
		tiempo[i] = c;
	}
	
	for(int i = 0; i<1001; i++){
		dp[i][0] = 0;
	}
	for(int i = 0; i<2001; i++){
		dp[0][i] = 0;
	}
	
	cout<<DP(n, t)<<endl;
	
	return 0;
}
