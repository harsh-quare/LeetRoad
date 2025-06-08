class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, bool buy, vector<int>& prices, int n){
        if(i >= n){
            if(buy == 0) return 0;
            else return INT_MIN/2;  // hamne ek stock buy kr liya, but sell nhi kiya and array finish ho gya
        }

        if(dp[i][buy] != INT_MIN) return dp[i][buy];

        int ans = INT_MIN;

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
        dp.assign(n+1, vector<int>(2, INT_MIN));
        return solve(0, 0, prices, n);
    }
};