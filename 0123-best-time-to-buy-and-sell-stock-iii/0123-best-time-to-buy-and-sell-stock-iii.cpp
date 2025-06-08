class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int i, bool buy, int cap, vector<int>& prices, int n){
        if(i == n || cap <= 0){
            return 0;
        }

        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];

        int ans = 0;

        if(buy == 0){  // you are free to skip or buy a stock
            // op-1: skip
            ans = max(ans, solve(i+1, buy, cap, prices, n));

            // op-2: buy the stock
            ans = max(ans, -prices[i] + solve(i+1, 1, cap, prices, n));
        }
        else{
            // already bought a stock, can either skip or sell
            // op-1: skip
            ans = max(ans, solve(i+1, buy, cap, prices, n));

            // op-2: sell the stock => 1 transaction completed
            if(cap > 0) ans = max(ans, prices[i] + solve(i+1, 0, cap-1, prices, n));
        }

        return dp[i][buy][cap] = ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n+1, vector<vector<int>> (2, vector<int>(3, -1)));
        return solve(0, 0, 2, prices, n);  // i, buy, capacity
    }
};