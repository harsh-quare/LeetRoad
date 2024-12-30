class Solution {
public:
    const int mod = 1e9 + 7;
    int solve(int n, vector<long long>& dp){
        if(n <= 0) return 0;

        if(dp[n] != -1) return dp[n];

        int take= 1 + solve(n-2, dp) % mod;
        int not_take = solve(n-1, dp) % mod;

        return dp[n] = (take + not_take) % mod;
    }
    int countHousePlacements(int n) {
        vector<long long> dp(n+1, -1);
        int ans = 1 + solve(n, dp);
        return ((long long)ans*ans) % mod;
    }
};