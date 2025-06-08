class Solution {
public:
    vector<vector<vector<long long>>> dp;
    long long solve(int i, int state, int k, vector<int>& prices, int n){
        if(i == n){
            if(state == 0) return 0;
            return LLONG_MIN/2;  // state = 1 or 2 => incomplete transaction => invalidate the path
        }

        if(dp[i][state][k] != LLONG_MIN) return dp[i][state][k];

        long long ans = LLONG_MIN;

        if(state == 0){
            //skip
            ans = max(ans, solve(i+1, state, k, prices, n));
            //buy => ensure, you only start this tx if the k > 0
            if(k > 0) ans = max(ans, -prices[i] + solve(i+1, 1, k, prices, n));
            //shortSell => ensure, you only start this tx if the k > 0
            if(k > 0) ans = max(ans, prices[i] + solve(i+1, 2, k, prices, n));
        }
        else if(state == 1){
            //skip
            ans = max(ans, solve(i+1, state, k, prices, n));
            //sell => normal tx
            if(k > 0) ans = max(ans, prices[i] + solve(i+1, 0, k-1, prices, n));
        }
        else if(state == 2){
            // skip
            ans = max(ans, solve(i+1, state, k, prices, n));
            //shortSell kiya tha, buy krlo
            if(k > 0) ans = max(ans, -prices[i] + solve(i+1, 0, k-1, prices, n));
        }

        return dp[i][state][k] = ans;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        dp.assign(n+1, vector<vector<long long>>(3, vector<long long>(k+1, LLONG_MIN)));
        return solve(0, 0, k, prices, n);
    }
};