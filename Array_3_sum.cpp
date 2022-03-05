class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> answer;
        map<vector<int> , int> mp;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            
            int target = nums[i]*(-1);
            int j = i+1,k=nums.size()-1;
            
            while(k>=i+1 && j<nums.size() && j<k){
                if(nums[k]+nums[j]==target){
                   vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    sort(temp.begin(),temp.end());
                    if(mp.find(temp)==mp.end()){
                         answer.push_back(temp);
                         mp[temp] = 1;
                    }
                    k--;
                    j++;
                    if(nums[i]==0 && nums[j]==0 && nums[k]==0) break;
                }
                else if(nums[k]+nums[j]<target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return answer;
        
    }
};
