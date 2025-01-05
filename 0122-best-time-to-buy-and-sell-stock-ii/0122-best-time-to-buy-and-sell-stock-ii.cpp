class Solution {
public:
    int solve(int id, bool buy, int n, vector<int>& nums, vector<vector<int>>& dp){
        if(id >= n) return 0;

        if(dp[id][buy] != -1) return dp[id][buy];

        int profit = 0;
        
        if(buy == 1){
            //you can buy
            int buy_ans = solve(id + 1, !buy, n, nums, dp) - nums[id];
            int skip_ans = solve(id + 1, buy, n, nums, dp);

            profit = max(skip_ans, buy_ans);
        }

        else{
            //you need to sell
            int sell_ans = solve(id + 1, !buy, n, nums, dp) + nums[id]; //after selling, you are again allowd to buy
            int skip_ans = solve(id + 1, buy, n, nums, dp);

            profit = max(sell_ans, skip_ans);
        }

        return dp[id][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, n, prices, dp); // id, buy or not, size, array
    }
};