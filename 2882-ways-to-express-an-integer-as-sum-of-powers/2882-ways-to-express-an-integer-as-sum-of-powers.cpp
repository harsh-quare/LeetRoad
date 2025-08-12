class Solution {
public:
    const int mod = 1e9 + 7;
    int solve(int num, int x, int cur, vector<vector<int>>& dp){
        if(num == 0) return 1;  // only one way
        if(num < 0) return 0;

        int val = pow(cur, x);
        if(val > num) return 0;

        if(dp[num][cur] != -1) return dp[num][cur];

        int take = solve(num - val, x, cur + 1, dp) % mod;
        int skip = solve(num, x, cur + 1, dp) % mod;

        return dp[num][cur] = (take + skip) % mod;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(n, x, 1, dp);
    }
};