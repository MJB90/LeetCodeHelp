#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,x;
	cin>>n;
	cin>>x;
	
	vector<int> coins(n);
	
	for(int i=0;i<n;i++){
		cin>>coins[i];
	}
	
	vector<int> dp(x+1,INT_MAX);
	dp[0] = 0;
	for(int s=1;s<=x;s++){
		for(int j=0;j<n;j++){
			if(s-coins[j]>=0 && dp[s-coins[j]]!=INT_MAX){
				dp[s] = min(1+dp[s-coins[j]],dp[s]);
			}
		}
	}
	
	if(dp[x]==INT_MAX) cout<<-1;
	else cout<<dp[x];
}
