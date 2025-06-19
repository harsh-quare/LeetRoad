class Solution {
public:
    // int solve(int i, bool holding, int txCnt, vector<int>& nums, int n, vector<vector<vector<int>>>& dp){
    //     if(i >= n) return 0;
    //     if(txCnt >= 2){
    //         // this path should no longer be in consideration, as no more further stock transaction can be performed, already reached limit, so no more profit can come from this path
    //         return 0;
    //     }

    //     if(dp[i][holding][txCnt] != -1) return dp[i][holding][txCnt];

    //     int ans = 0;

    //     // not holding currrently
    //     if(!holding){
    //         // op1: skip
    //         ans = max(ans, solve(i+1, holding, txCnt, nums, n, dp));
    //         //op2: buy
    //         ans = max(ans, -nums[i] + solve(i+1, !holding, txCnt, nums, n, dp));
    //     }
    //     else{
    //         // op1: skip
    //         ans = max(ans, solve(i+1, holding, txCnt, nums, n, dp));
    //         //op2: sell
    //         ans = max(ans, nums[i] + solve(i+1, !holding, txCnt + 1, nums, n, dp));  // increment the txCnt, when stock transaction finished
    //     }

    //     return dp[i][holding][txCnt] = ans;
    // }
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int i = n-1; i >= 0; i--){
            for(int holding = 0; holding <= 1; holding++){
                for(int txCnt = 2; txCnt >= 0; txCnt--){
                    int ans = 0;

                    // not holding currrently
                    if(!holding){
                        // op1: skip
                        ans = max(ans, dp[i+1][holding][txCnt]);
                        //op2: buy
                        ans = max(ans, -nums[i] + dp[i+1][!holding][txCnt]);
                    }
                    else{
                        // op1: skip
                        ans = max(ans, dp[i+1][holding][txCnt]);
                        //op2: sell
                        if(txCnt + 1 <= 2) ans = max(ans, nums[i] + dp[i+1][!holding][txCnt + 1]);
                    }

                    dp[i][holding][txCnt] = ans;
                }
            }
        }

        return dp[0][0][0];
    }
};