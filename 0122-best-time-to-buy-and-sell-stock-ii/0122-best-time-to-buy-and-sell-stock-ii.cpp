class Solution {
public:
    int solve(int i, bool holding, vector<int>& nums, int n, vector<vector<int>>& dp){
        if(i >= n){
            return 0;
        }

        if(dp[i][holding] != -1) return dp[i][holding];

        int ans = 0;

        // if not holding currently
        if(!holding){
            // op1: skip
            ans = max(ans, solve(i+1, holding, nums, n, dp));
            // op2: buy
            ans = max(ans, -nums[i] + solve(i+1, !holding, nums, n, dp));
        }
        else{
            // op1: skip
            ans = max(ans, solve(i+1, holding, nums, n, dp));
            // op2: buy
            ans = max(ans, nums[i] + solve(i+1, !holding, nums, n, dp));
        }

        return dp[i][holding] = ans;
    }
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(0, 0, nums, n, dp);
    }
};