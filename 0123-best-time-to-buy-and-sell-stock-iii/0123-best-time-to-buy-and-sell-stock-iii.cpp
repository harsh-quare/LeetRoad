class Solution {
public:
    int solve(int id, bool buy,int cap, vector<int>& a, int n, vector<vector<vector<int>>> &dp){
        if(id >= n || cap <= 0) return 0;

        if(dp[id][buy][cap] != -1) return dp[id][buy][cap];

        int profit = 0;

        if(buy == 1){
            int buy_ans = -a[id] + solve(id+1, !buy, cap, a, n, dp);
            int skip_ans = 0 + solve(id+1, buy, cap, a, n, dp);

            profit = max(buy_ans, skip_ans);
        }

        if(buy == 0){
            int sell_ans = a[id] + solve(id+1, !buy, cap-1, a, n, dp);
            int skip_ans = 0 + solve(id+1, buy, cap, a, n, dp);

            profit = max(sell_ans, skip_ans);
        }

        return dp[id][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(3, -1)));
        return solve(0, 1, 2, prices, n, dp);
    }
};