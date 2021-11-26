class Solution {
public:
    vector<int> help;
    int answer(vector<int>& nums,int i){
        if(i>nums.size()-1) return 0;
        if(help[i]!=-1) return help[i];
        else{
            //anwer(nums,i+1)--> you ignore number at position i and move to next position
            //answer(nums,i+2)--> you take the number at position i and then move to i+2 position
            //Take the maximum of this two cases and store it for memoization
            help[i] = max(answer(nums,i+1),nums[i]+answer(nums,i+2));
            return help[i];
        }
    }
    int rob(vector<int>& nums) {
        help.resize(nums.size());
        fill(help.begin(),help.end(),-1);
        return answer(nums,0);
    }
};
