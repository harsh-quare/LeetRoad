class Solution {
public:
    int solve(int i, int curOr, int maxOr, int n, vector<int>& nums, vector<vector<int>>& dp){
        if(i >= n){
            return (curOr == maxOr);
        }

        if(dp[i][curOr] != -1) return dp[i][curOr];

        int skip = solve(i+1, curOr, maxOr, n, nums, dp);

        int take = solve(i+1, curOr | nums[i], maxOr, n, nums, dp);

        return dp[i][curOr] = (take + skip);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = nums[0];
        for(int& x: nums){
            maxOr |= x;
        }

        vector<vector<int>> dp(n, vector<int>(maxOr + 1, -1));

        return solve(0, 0, maxOr, n, nums, dp);
    }
};