class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[amount+1];
        fill(dp, dp+amount+1, INT_MAX);
        dp[0]= 0;
        
        for(auto coin : coins)
        {
            for(int j =1; j<=amount; j++)
            {
                if(coin<=j && dp[j-coin]!=INT_MAX)
                    dp[j] = min(dp[j], dp[j-coin]+1);
            }
        }
        return dp[amount]!=INT_MAX?dp[amount]:-1;
    }
};
