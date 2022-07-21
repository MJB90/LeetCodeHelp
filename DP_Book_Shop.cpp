#include<bits/stdc++.h>
using namespace std;

int mts = 1e9+7;

int main(){
	int n,X;
	cin>>n>>X;
	
	vector<int> prices(n+1),pages(n+1);
	
	for(int i=1;i<=n;i++){
		cin>>prices[i];
	}
	
	for(int i=1;i<=n;i++){
		cin>>pages[i];
	}
	
	vector<int> v(X+1,0);
	vector<vector<int> > dp(n+1,v);
	
	for(int i=1;i<=n;i++){
		for(int x=0;x<=X;x++){
			if(x==0) dp[i][x] = 0;
			else{
			
			int op1 = (i==1)?0:dp[i-1][x];
			int op2 = (prices[i]>x)?0:pages[i]+dp[i-1][x-prices[i]];
			dp[i][x] = max(op1,op2);	
			}
		}
	}
	
	cout<<dp[n][X];
	
	
}
