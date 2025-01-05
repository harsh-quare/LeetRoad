class Solution {
public:
    // int solve(int id, bool buy, int n, vector<int>& nums, vector<vector<int>>& dp){
    //     if(id >= n) return 0;

    //     if(dp[id][buy] != -1) return dp[id][buy];

    //     int profit = 0;
        
    //     if(buy == 1){
    //         //you can buy
    //         int buy_ans = solve(id + 1, !buy, n, nums, dp) - nums[id];
    //         int skip_ans = solve(id + 1, buy, n, nums, dp);

    //         profit = max(skip_ans, buy_ans);
    //     }

    //     else{
    //         //you need to sell
    //         int sell_ans = solve(id + 1, !buy, n, nums, dp) + nums[id]; //after selling, you are again allowd to buy
    //         int skip_ans = solve(id + 1, buy, n, nums, dp);

    //         profit = max(sell_ans, skip_ans);
    //     }

    //     return dp[id][buy] = profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int id = n-1; id >= 0; id--){
            int profit = 0;
            for(int buy = 0; buy < 2; buy++){
                if(buy == 1){
                    //you can buy
                    int buy_ans = dp[id+1][!buy] - prices[id];
                    int skip_ans = dp[id+1][buy];

                    profit = max(skip_ans, buy_ans);
                }
                
                if(buy == 0){
                    //you need to sell
                    int sell_ans = dp[id+1][!buy] + prices[id]; //after selling, you are again allowd to buy
                    int skip_ans = dp[id+1][buy];

                    profit = max(sell_ans, skip_ans);
                }

                dp[id][buy] = profit;
            }
        }
        return dp[0][1];
    }
};