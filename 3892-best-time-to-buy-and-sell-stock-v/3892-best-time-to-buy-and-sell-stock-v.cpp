class Solution {
public:
    vector<vector<vector<long long>>> dp;
    long long solve(int i, int k, int state, vector<int>& prices, int n){
        if(i == n){
            if(state == 0) return 0;  // free h, to 0 return kr denge, means koi active transaction ke time ham array end nhi kr rhe
            // other wise ya to koi stock buy kr rkha h, ya fir sell kr rkha h, dono cases me LLONG_MIN bhej do taaki ye path consider na ho
            else return LLONG_MIN/2;
        }

        if(dp[i][k][state] != LLONG_MIN) return dp[i][k][state];

        long long ans = LLONG_MIN;

        // if bought a stock earlier
        if(state == 0){
            //op-1: do nothing
            ans = max(ans, solve(i+1, k, state, prices, n));

            //op-2: buy today, a long stock
            ans = max(ans, -prices[i] + solve(i+1, k, 1, prices, n));

            //op-3: sell short today, shortSell
            ans = max(ans, prices[i] + solve(i+1, k, 2, prices, n));
        }
        else if(state == 1){
            // op-1: skip today
            ans = max(ans, solve(i+1, k, state, prices, n));

            // op-2: sell krna h
            if(k > 0) ans = max(ans, prices[i] + solve(i+1, k-1, 0, prices, n)); // tx complete ho gya, state ko 0 kr do
        }
        else if(state == 2){
            // op-1: skip today
            ans = max(ans, solve(i+1, k, state, prices, n));

            // op-2: buy krna krna h
            if(k > 0) ans = max(ans, -prices[i] + solve(i+1, k-1, 0, prices, n)); // tx complete ho gya, state ko 0 kr do
        }

        return dp[i][k][state] = ans;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        dp.assign(n+1, vector<vector<long long>> (k+1, vector<long long> (3, LLONG_MIN)));
        
        // 3 states, 0 => free, 1 => buy kr rkha h, sell krna pdega, 2 => short sell kr rkha h, buy krna padega
        return solve(0, k, 0, prices, n);
    }
};
