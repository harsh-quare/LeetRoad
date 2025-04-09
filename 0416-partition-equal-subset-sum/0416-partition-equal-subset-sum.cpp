class Solution {
public:
    // bool targetSum(vector<int>& nums, int i, int tar, int n, vector<vector<int>> &dp){
    //     if(i >= n || tar < 0) return false;
    //     if(tar == 0) return true;

    //     if(dp[i][tar] != -1) return dp[i][tar];

    //     // take current element
    //     bool take = targetSum(nums, i+1, tar - nums[i], n, dp);
    //     // notTake current element
    //     bool notTake = targetSum(nums, i+1, tar, n, dp);

    //     return dp[i][tar] = take | notTake;
    // }
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % 2 != 0) return false;

        // try all ways to create one subsets with its sum = total / 2, second subset will surely exist
        int n = nums.size();
        int k = total / 2;
        vector<vector<bool>> dp(n+1, vector<bool>(k+1, 0));
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }

        for(int i = 1; i < n; i++){
            for(int tar = 1; tar <= k; tar++){
                bool notTake = dp[i-1][tar];

                bool take = false;
                if(tar >= nums[i]){
                    take = dp[i-1][tar - nums[i]];
                }

                dp[i][tar] = (take | notTake);
            }
        }
        return dp[n-1][k];
    }
};