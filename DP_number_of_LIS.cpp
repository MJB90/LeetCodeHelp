class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        vector<int> cnt(nums.size(),0);
        int n = nums.size();
        
        int maxLis=0,maxCount=0;
        for(int i=n-1;i>=0;i--){
            int mlen=1,mcnt=1;
            
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    int len = dp[j];
                    int ct = cnt[j];
                    
                    if(len+1>mlen){
                        mlen = len+1;
                        mcnt = ct;
                    }
                    else if(len+1==mlen){
                        mcnt += ct;
                    }
                }
            }
                if(mlen>maxLis){
                    maxLis = mlen;
                    maxCount = mcnt;
                }
                else if(mlen==maxLis){
                    maxCount += mcnt;
                }
                
                dp[i] = mlen;
                cnt[i] = mcnt;
        }
        
        return maxCount;
    }
};
