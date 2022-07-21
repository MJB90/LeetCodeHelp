#include<bits/stdc++.h>
using namespace std;

int mts = 1e9+7;
int main(){
	int n;
	cin>>n;
	
	vector<char> c(n,'.');
	vector<vector<char> > grid(n,c);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>grid[i][j];
		}
	}
	
	vector<int> v(n,0);
	vector<vector<int> > dp(n,v);
	
	for(int i=0;i<n;i++){
		if(grid[0][i]=='.') dp[0][i] = 1;
		else break;
	}
	
	for(int i=0;i<n;i++){
		if(grid[i][0]=='.') dp[i][0] = 1;
		else break;
	}
	
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			(grid[i][j]=='.')?dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mts:0;
		}
	}
	cout<<dp[n-1][n-1];
}
