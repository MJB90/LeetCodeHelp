class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        
        int suff = nums[nums.size()-1],pref=nums[0];
        
        for(int i=1;i<nums.size();i++){
            ans[i]=pref;
            pref *=nums[i];
        }
        
        for(int i=nums.size()-2;i>=0;i--){
            ans[i]*=suff;
            suff *=nums[i];
        }
        
        return ans;
    }
};
