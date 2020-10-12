#include<bits/stdc++.h>
using namespace std;

int main(){
	
	
	int n, k;
	cin>>n>>k;
	long long sum = 0;
	
	for(int i = 1; i<=n; i++){
		
		long long q = n/i;
		long long p = i;
		for(int j = 0; j<k-1; j++){
			p = (p*i)%1000000000;
		}
		if(k==0) p = 1;
		long long r = (p*q)%1000000000;
		sum = (sum+r)%1000000000;
		
	}
	
	cout<<sum;
	
	return 0;
}
