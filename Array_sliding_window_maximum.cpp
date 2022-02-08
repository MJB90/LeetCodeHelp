class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> maxVal;
        
        int l=0,r = 0;
        
        vector<int> answer;
        
        while(r<nums.size()){
            
            while(!maxVal.empty() && maxVal.back()<nums[r]){
                maxVal.pop_back();
            }
            
            maxVal.push_back(nums[r]);
            
            if(r-l+1==k){
                answer.push_back(maxVal.front());
                if(nums[l]==maxVal.front()) maxVal.pop_front();
                l++;
            }
            
            r++;
        }
        return answer;
    }
};
