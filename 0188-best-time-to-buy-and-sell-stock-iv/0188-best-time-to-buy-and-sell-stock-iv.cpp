class Solution {
public:
    // int solve(int i, bool holding, int txs, vector<int>& nums, int n, int k, vector<vector<vector<int>>>& dp){
    //     if(i >= n || txs >= k){
    //         return 0;
    //     }

    //     if(dp[i][holding][txs] != -1) return dp[i][holding][txs]; 
        
    //     int ans = 0;

    //     if(!holding){
    //         // op1: skip
    //         ans = max(ans, solve(i+1, holding, txs, nums, n, k, dp));
    //         // op2: buy
    //         ans = max(ans, -nums[i] + solve(i+1, !holding, txs, nums, n, k, dp));
    //     }
    //     else{
    //         // op1: skip
    //         ans = max(ans, solve(i+1, holding, txs, nums, n, k, dp));
    //         // op2: buy
    //         ans = max(ans, nums[i] + solve(i+1, !holding, txs + 1, nums, n, k, dp));
    //     }

    //     return dp[i][holding][txs] = ans;
    // }
    int maxProfit(int k, vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        // return solve(0, 0, 0, nums, n, k, dp);

        for(int i = n-1; i >= 0; i--){
            for(int holding = 0; holding <= 1; holding++){
                for(int txs = k-1; txs >= 0; txs--){  // total k transcations are allowed
                    int ans = 0;

                    if(!holding){
                        // op1: skip
                        ans = max(ans, dp[i+1][holding][txs]);
                        // op2: buy
                        ans = max(ans, -nums[i] + dp[i+1][!holding][txs]);
                    }
                    else{
                        // op1: skip
                        ans = max(ans, dp[i+1][holding][txs]);
                        // op2: buy
                        ans = max(ans, nums[i] + dp[i+1][!holding][txs+1]);
                    }

                    dp[i][holding][txs] = ans;
                }
            }
        }

        return dp[0][0][0];
    }
};