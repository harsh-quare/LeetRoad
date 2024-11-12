class Solution {
public:
    // int solve(int id, bool buy, int fee, vector<int>& arr, int n, vector<vector<int>>& dp){
    //     if(id >= n) return 0;

    //     if(dp[id][buy] != -1) return dp[id][buy];

    //     int profit = 0;

    //     //at the point of selling, the net profit would be (sell_price - buy_price - fee)

    //     if(buy == 1){
    //         int buy_ans = -arr[id] + solve(id + 1, !buy, fee, arr, n, dp);
    //         int skip_ans = 0 + solve(id+1, buy, fee, arr, n, dp);

    //         profit = max(buy_ans, skip_ans);
    //     }

    //     if(buy == 0){
    //         int sell_ans = arr[id] - fee + solve(id+1, !buy, fee, arr, n, dp);
    //         int skip_ans = 0 + solve(id+1, buy, fee, arr, n, dp);

    //         profit = max(sell_ans, skip_ans);
    //     }

    //     return dp[id][buy] = profit;
    // }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // kisi bhi ek moment pe fee charge krni h, either sell krte time or buy krte time

        vector<int> next(2, 0), cur(2, 0);

        for(int id = n-1; id >= 0; id--){
            for(int buy = 0; buy <= 1; buy++){

                int profit = 0;
                
                if(buy == 1){
                    //buy
                    profit = max(-prices[id] + next[!buy], 0 + next[buy]);
                }

                if(buy == 0){
                    //sell, and fee charge kr lena
                    profit = max(prices[id] - fee + next[!buy], 0 + next[buy]);
                }

                cur[buy] = profit;
            }
            next = cur;
        }
        
        return cur[1];
    }
};