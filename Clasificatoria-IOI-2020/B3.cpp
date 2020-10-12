#include<bits/stdc++.h>
using namespace std;

int main(){
	
	
	int n, m;
	cin>>n>>m;
	
	long long sum = 0;
	vector<int> caso(m, 0);
	
	for(int i = 0; i<n; i++){
		int contador = 0;
		string s;
		cin>>s;
		for(int j = m-1; j>=0; j--){
			if(s[j] == 'A') sum+=caso[j];
			if(s[j] == 'V') contador++;
			if(s[j] == 'R') caso[j]+=contador;
		}
	}
	
	cout<<sum;
	
	
	return 0;
}
