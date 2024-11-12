class Solution {
public:
    // int solve(int id, bool buy, int n, vector<int>& nums, vector<vector<int>>& dp){
    //     if(id >= n) return 0;

    //     if(dp[id][buy] != -1) return dp[id][buy];

    //     //I have two options, either buy or sell
    //     int profit = 0;

    //     if(buy == 1){
    //         //I can buy another stock
    //         //If i'm buying current stock, the profit would be: futureSellingPrice - curPrice
    //         //means it's resulting in the addition of (-curPrice)
    //         int buy_ans = -nums[id] + solve(id+1, 0, n, nums, dp);
    //         int skip_ans = 0 + solve(id+1, 1, n, nums, dp);

    //         profit = max(buy_ans, skip_ans);
    //     }

    //     if(buy == 0){
    //         //I can sell
    //         int sell_ans = nums[id] + solve(id+1, 1, n, nums, dp);  //you can buy in future if you sell today
    //         int skip_ans = 0 + solve(id+1, 0, n, nums, dp);

    //         profit = max(sell_ans, skip_ans);
    //     }

    //     return dp[id][buy] = profit;
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // Create a DP table to memoize results
        vector<long> next(2, 0), cur(2, 0);  

        // Base condition: When we have no stocks left, the profit is 0.
        next[0] = next[1] = 0;

        long profit;

        // Loop through the array in reverse order
        for(int ind = n - 1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                if(buy == 0){ // We can buy the stock
                    profit = max(0 + next[0], -prices[ind] + next[1]);
                }

                if(buy == 1){ // We can sell the stock
                    profit = max(0 + next[1], prices[ind] + next[0]);
                }

                cur[buy] = profit;
            }
            next = cur;
        }

        // The maximum profit is stored in cur[0] after all calculations
        return cur[0];
    }
};