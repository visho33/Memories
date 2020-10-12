#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n, m;
	cin>>n>>m;
	
	char grilla[n][m];
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			char c; cin>>c;
			grilla[i][j] = c;
		}
	}
	
	long long suma = 0;
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(grilla[i][j] == 'R'){
				
				int asum = 0;
				int vsum = 0;
				
				for(int k = i+1; k<n;k++){
					
					if(grilla[k][j] == 'A'){
						asum++;
					}
					
				}
				
				for(int l = j+1; l<m; l++){
					if(grilla[i][l] == 'V'){
						vsum++;
					}
				}
				suma = suma + asum*vsum;
			}
		}
	}
	
	cout<<suma<<endl;
	
	return 0;
}
