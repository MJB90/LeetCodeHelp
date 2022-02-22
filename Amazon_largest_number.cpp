class Solution {
public:
    static bool cmp(int &a ,int &b){
        string x = to_string(a) + to_string(b);
        string y = to_string(b) + to_string(a);
        
        return x>y;
    }
    string largestNumber(vector<int>& nums) {
        string result ="";
        sort(nums.begin(),nums.end(),cmp);
        bool onlyZero = true;
        for(auto num:nums){
            result += to_string(num);
            if(num!=0) onlyZero = false;
        }
        return onlyZero?"0":result;
    }
};
