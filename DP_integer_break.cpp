class Solution {
public:
    vector<int> dp;
    
    int helper(int num,int n){
        if(num==0 || dp[num]!=-1) return dp[num];
        
        //This if condition is to make sure that only num that is smaller than n 
        //should have num as the largest 
        if(num==n){
            dp[num] = 0;
        }
        else dp[num]=num;
        
        for(int i=1;i<num;i++){
           int val = helper(i,n) * helper(num-i,n);
            dp[num] = max(dp[num],val);
        }
        return dp[num];
    }
    int integerBreak(int n) {
        dp.clear();
        dp.resize(n+1);
        for(int i=0;i<=n;i++){
            dp[i] = -1;
        }
        dp[0]=0;
        return helper(n,n);
    }
};
