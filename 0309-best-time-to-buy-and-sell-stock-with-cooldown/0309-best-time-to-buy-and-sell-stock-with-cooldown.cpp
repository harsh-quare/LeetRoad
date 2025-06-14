class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, bool buy, vector<int>& prices, int n){
        if(i >= n) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int ans = 0;
        
        if(buy == 0){
            //skip
            ans = max(ans, solve(i+1, buy, prices, n));
            //buy
            ans = max(ans, -prices[i] + solve(i+1, 1, prices, n));
        }
        else{
            //skip
            ans = max(ans, solve(i+1, buy, prices, n));
            //sell => remember the cooldown
            ans = max(ans, prices[i] + solve(i+2, 0, prices, n));
        }

        return dp[i][buy] = ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n+1, vector<int>(2, -1));
        return solve(0, 0, prices, n);  // 0=> free, 1 => bought, active tx
    }
};