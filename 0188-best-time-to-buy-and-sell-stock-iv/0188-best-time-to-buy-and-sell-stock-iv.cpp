class Solution {
public:
    // vector<vector<vector<int>>> dp;
    // int solve(int i, bool buy, int k, vector<int>& prices, int n){
    //     if(i == n || k == 0) return 0;

    //     if(dp[i][buy][k] != -1) return dp[i][buy][k];

    //     int ans = 0;

    //     if(buy == 0){
    //         //skip
    //         ans = max(ans, solve(i+1, buy, k, prices, n));

    //         // buy
    //         if(k > 0) ans = max(ans, -prices[i] + solve(i+1, !buy, k, prices, n));
    //     }
    //     else{
    //         // skip
    //         ans = max(ans, solve(i+1, buy, k, prices, n));

    //         // sell
    //         if(k > 0) ans = max(ans, prices[i] + solve(i+1, !buy, k-1, prices, n));
    //     }

    //     return dp[i][buy][k] = ans;
    // }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp (n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        vector<vector<int>> cur(2, vector<int>(k+1, 0)), nxt(2, vector<int>(k+1, 0));
        // return solve(0, 0, k, prices, n);

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= k; cap++){
                    int ans = 0;

                    if(buy == 0){
                        //skip
                        ans = max(ans, nxt[buy][cap]);

                        // buy
                        ans = max(ans, -prices[i] + nxt[!buy][cap]);
                    }
                    else{
                        // skip
                        ans = max(ans, nxt[buy][cap]);

                        // sell
                        ans = max(ans, prices[i] + nxt[!buy][cap-1]);
                    }

                    cur[buy][cap] = ans;
                }
            }

            nxt = cur;
        }

        return cur[0][k];
    }
};