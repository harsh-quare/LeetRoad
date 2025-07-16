class Solution {
public:
    // int solve(int i, int prevId, vector<int>& nums, vector<vector<int>> &dp){
    //     if(i == nums.size()) return 0;
    //     if(dp[i][prevId + 1] != -1) return dp[i][prevId + 1];

    //     int notTake = solve(i+1, prevId, nums, dp);
    //     int take = 0;
    //     if(prevId == -1 || nums[i] > nums[prevId]){
    //         take = 1 + solve(i+1, i, nums, dp);
    //     }

    //     return dp[i][prevId + 1] = max(take, notTake);
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = n-1; i >= 0; i--){
            for(int prevId = i-1; prevId >= -1; prevId--){
                int notTake = dp[i+1][prevId+1];
                int take = 0;
                if(prevId == -1 || nums[i] > nums[prevId]){
                    take = 1 + dp[i+1][i+1];
                }

                dp[i][prevId+1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }
};