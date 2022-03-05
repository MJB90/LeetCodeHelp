class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        
        int l=0,r=0;
        int farthest=0;
        
        while(r<nums.size()-1){
            for(int i=0;i<=r;i++){
                farthest = max(farthest,i+nums[i]);
            }
            l=r+1;
            r=farthest;
            ans++;
        }
        return ans;
    }
};
