class Solution {
public:
    // int solve(int id, bool buy,int cap, vector<int>& a, int n, vector<vector<vector<int>>> &dp){
    //     if(id >= n || cap <= 0) return 0;

    //     if(dp[id][buy][cap] != -1) return dp[id][buy][cap];

    //     int profit = 0;

    //     if(buy == 1){
    //         int buy_ans = -a[id] + solve(id+1, !buy, cap, a, n, dp);
    //         int skip_ans = 0 + solve(id+1, buy, cap, a, n, dp);

    //         profit = max(buy_ans, skip_ans);
    //     }

    //     if(buy == 0){
    //         int sell_ans = a[id] + solve(id+1, !buy, cap-1, a, n, dp);
    //         int skip_ans = 0 + solve(id+1, buy, cap, a, n, dp);

    //         profit = max(sell_ans, skip_ans);
    //     }

    //     return dp[id][buy][cap] = profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(3, 0)));
        
        //base case: when cap == 0, put zeros, already done while declaring dp
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < 2; j++){
        //         dp[i][j][0] = 0;
        //     }
        // }

        for(int id = n-1; id >= 0; id--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= 2; cap++){
                    int profit = 0;

                    if(buy == 1){
                        int buy_ans = -prices[id] + dp[id+1][!buy][cap];
                        int skip_ans = 0 + dp[id+1][buy][cap];

                        profit = max(buy_ans, skip_ans);
                    }

                    if(buy == 0){
                        int sell_ans = prices[id] + dp[id+1][!buy][cap-1];
                        int skip_ans = 0 + dp[id+1][buy][cap];

                        profit = max(sell_ans, skip_ans);
                    }

                    dp[id][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};