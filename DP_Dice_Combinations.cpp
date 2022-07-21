#include<bits/stdc++.h>
using namespace std;

int mts = 1e9+7;
int calculateWays(int n,vector<int> &dp){
	if(n==1 || n==0 ) return 1;
	else if(n==2) return 2;
	else if(n==3) return 4;
	else if(n<0) return 0;
	
	if(dp[n]!=-1) return dp[n];
	else{
		int val = 0;
		for(int i=1;i<=6;i++){
			val = (val%mts + calculateWays(n-i,dp)%mts)%mts;
		}
		return dp[n]= val;
	}
	
}
int main(){
	int n;
	cin>>n;
	vector<int> dp(n+1,-1);
	cout<<calculateWays(n,dp);
}
