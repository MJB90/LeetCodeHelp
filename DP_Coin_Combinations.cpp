#include<bits/stdc++.h>
using namespace std;

int mts = 1e9+7;

int main(){
int n,x;
	cin>>n;
	cin>>x;
	
	vector<int> coins(n);
	
	for(int i=0;i<n;i++){
		cin>>coins[i];
	}
	vector<int> dp(x+1,0);
	
	for(int amt =1;amt<=x;amt++){
		for(int c=0;c<coins.size();c++){
			if(amt-coins[c]==0){
				dp[amt] = (dp[amt]+1)%mts;
			}
			else if(amt-coins[c]>0){
				dp[amt] = (dp[amt] + dp[amt-coins[c]])%mts;
			}
			else break;
		}
	}
	cout<<dp[x];
}
