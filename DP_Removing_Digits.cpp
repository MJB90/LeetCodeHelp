#include<bits/stdc++.h>
using namespace std;

int mts = 1e9+7;

int findWays(int n,vector<int> &dp){
	if(n==0) return 0;
	
	if(dp[n]!=INT_MAX) return dp[n];
	else{
		int k = n;
		
		while(k>0){
			if(k%10>0){
				dp[n] = min(dp[n],(1+findWays(n-k%10,dp)%mts));
			}
			k = k/10;
		}
	}
	return dp[n];
}
int main(){
	int n;
	cin>>n;
	vector<int> dp(n+1,INT_MAX);
	cout<<findWays(n,dp);
}
