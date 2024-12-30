class Solution {
public:
    const int mod = 1e9 + 7;
    long long solve(int zero, int one, int low, int high, int len, vector<int>& dp){
        if(len > high) return 0;

        if(dp[len] != -1) return dp[len];

        long long cnt = (len >= low) ? 1 : 0;  //already checked for len <= high

        cnt = (cnt + solve(zero, one, low, high, len + zero, dp)) % mod;
        cnt = (cnt + solve(zero, one, low, high, len + one, dp)) % mod;

        return dp[len] = cnt;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return solve(zero, one, low, high, 0, dp);
    }
};