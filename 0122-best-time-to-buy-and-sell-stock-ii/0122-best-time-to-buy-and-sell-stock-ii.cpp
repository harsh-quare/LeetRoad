class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, bool buy, vector<int>& prices, int n){
        if(i >= n){
            return 0;
        }

        if(dp[i][buy] != -1) return dp[i][buy];

        int ans = 0;

        if(buy == 0){
            // free h, ham buy kr skte h, ya skip kr skte h
            
            // op-1: skip
            ans = max(ans, solve(i+1, buy, prices, n));

            //op-2: buy kr lo
            ans = max(ans, -prices[i] + solve(i, 1, prices, n));
        }
        else if(buy == 1){
            // ham ya to skip kr skte h ya fir sell kr skte h
            // op-1: skip
            ans = max(ans, solve(i+1, buy, prices, n));

            //op-2: sell kr do
            ans = max(ans, prices[i] + solve(i+1, 0, prices, n));
        }

        return dp[i][buy] = ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 2 states: 0 => free, 1 => buy kiya h
        dp.assign(n+1, vector<int>(2, -1));
        return solve(0, 0, prices, n);
    }
};