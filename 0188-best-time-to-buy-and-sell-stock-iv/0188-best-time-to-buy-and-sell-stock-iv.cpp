class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int i, bool buy, int k, vector<int>& prices, int n){
        if(i == n || k == 0) return 0;

        if(dp[i][buy][k] != -1) return dp[i][buy][k];

        int ans = 0;

        if(buy == 0){
            //skip
            ans = max(ans, solve(i+1, buy, k, prices, n));

            // buy
            if(k > 0) ans = max(ans, -prices[i] + solve(i+1, !buy, k, prices, n));
        }
        else{
            // skip
            ans = max(ans, solve(i+1, buy, k, prices, n));

            // sell
            if(k > 0) ans = max(ans, prices[i] + solve(i+1, !buy, k-1, prices, n));
        }

        return dp[i][buy][k] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp.assign(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(0, 0, k, prices, n);
    }
};