class Solution {
public:
    int solve(vector<int>& nums, int tar, int i, int sum, vector<vector<int>>& dp){
        if(i >= nums.size()){
            if(sum == tar){
                return 1;
            }
            return 0;
        }

        if(dp[i][sum + 1000] != -1) return dp[i][sum + 1000];

        int plus = solve(nums, tar, i+1, sum + nums[i], dp);
        int mns = solve(nums, tar, i+1, sum - nums[i], dp);

        return dp[i][sum + 1000] = plus + mns;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(2001, -1));
        return solve(nums, target, 0, 0, dp);
    }
};