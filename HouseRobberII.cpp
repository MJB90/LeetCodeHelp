class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int maxNum = 0;
        if (n <= 3) {
            for (const int& x : nums) {
                maxNum = max(maxNum, x);
            }
            return maxNum;
        }
        
        vector<int> memo(n, 0);
        memo[0] = nums[0];
        memo[1] = nums[1];
        memo[2] = nums[0] + nums[2];
        
        for (int i = 3; i < n - 1; i++) {
            memo[i] = max(memo[i-2] + nums[i], memo[i-3] + nums[i]);
        }
        int sum1 = max(memo[n-2], memo[n-3]);

        vector<int> memo2(n, 0);
        memo2[1] = nums[1];
        memo2[2] = nums[2];
        memo2[3] = memo2[1] + nums[3];

        for (int i = 4; i < n; i++) {
            memo2[i] = max(memo2[i-2] + nums[i], memo2[i-3] + nums[i]);
        }
        int sum2 = max(memo2[n-1], memo2[n-2]);
        return max(sum1, sum2);
    }
};
