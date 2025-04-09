class Solution {
public:
    bool targetSum(vector<int>& nums, int i, int tar, int n, vector<vector<int>> &dp){
        if(i >= n || tar < 0) return false;
        if(tar == 0) return true;

        if(dp[i][tar] != -1) return dp[i][tar];

        // take current element
        bool take = targetSum(nums, i+1, tar - nums[i], n, dp);
        // notTake current element
        bool notTake = targetSum(nums, i+1, tar, n, dp);

        return dp[i][tar] = take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % 2 != 0) return false;

        // try all ways to create one subsets with its sum = total / 2, second subset will surely exist
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(total+1, -1));
        return targetSum(nums, 0, total / 2, n, dp);
    }
};