class Solution {
public:
    // int solve(int id, bool buy, int n, vector<int>& arr, vector<vector<int>> &dp){
    //     if(id >= n) return 0;

    //     if(dp[id][buy] != -1) return dp[id][buy];

    //     int profit = 0;

    //     if(buy == 1){
    //         int buy_ans = -arr[id] + solve(id+1, !buy, n, arr, dp);
    //         int skip_ans = 0 + solve(id+1, buy, n, arr, dp);

    //         profit = max(buy_ans, skip_ans);
    //     }

    //     if(buy == 0){
    //         int sell_ans = arr[id] + solve(id + 2, !buy, n, arr, dp);  //if you decide to sell here, then the next point when you will be allowed to buy is id + 2, so directly jump to that
    //         int skip_ans = 0 + solve(id+1, buy, n, arr, dp);

    //         profit = max(sell_ans, skip_ans);
    //     }

    //     return dp[id][buy] = profit;
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, 0));
        vector<int> next2(2, 0), next1(2, 0), cur(2, 0);

        for(int id = n-1; id >= 0; id--){
            for(int buy = 0; buy <= 1; buy++){
                int profit = 0;

                if(buy == 1){
                    int buy_ans = -prices[id] + next1[!buy];
                    int skip_ans = 0 + next1[buy];

                    profit = max(buy_ans, skip_ans);
                }

                if(buy == 0){
                    int sell_ans = prices[id] + next2[!buy]; //if you decide to sell here, then the next point when you will be allowed to buy is id + 2, so directly jump to that
                    int skip_ans = 0 + next1[buy];

                    profit = max(sell_ans, skip_ans);
                }

                cur[buy] = profit;
            }
            next2 = next1;
            next1 = cur;
        }
        return cur[1];
    }
};