class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int> &prices,int pos,int buying){
        if(pos>=prices.size()) return 0;
        if(dp[pos][buying]!=-1) return dp[pos][buying];
        
        int buy,sell,cooldown;
        cooldown = helper(prices,pos+1,buying);
        if(buying){
            buy = helper(prices,pos+1,!buying)-prices[pos];
            dp[pos][buying] = max(buy,cooldown);
        }
        else{
            sell = helper(prices,pos+2,!buying) + prices[pos];
            dp[pos][buying] = max(sell,cooldown);
        }
        
        return dp[pos][buying];
    }
    int maxProfit(vector<int>& prices) {
        dp.clear();
        dp.resize(prices.size());
        for(int i=0;i<prices.size();i++){
            dp[i].resize(2);
        }
        
        for(int i=0;i<prices.size();i++){
        for(int j=0;j<dp[i].size();j++){
            dp[i][j]=-1;
        }
        }
        return helper(prices,0,1);
    }
};
