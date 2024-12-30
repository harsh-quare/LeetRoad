class Solution {
public:
    int dp[3001][1001];
    const int mod = 1e9 + 7;
    // value of pos can go to -999, because the lowest starting point can be 1, and max number of steps allowed are 1000, so if we take all negative steps from 1, then we can reach to -999, to handle that, we added 1000 to all
    int solve(int pos, int tar, int k){
        if(k <= 0){
            if(pos == tar) return 1;
            return 0;
        }

        if(dp[pos + 1000][k] != -1) return dp[pos + 1000][k];

        int left = solve(pos-1, tar, k-1) % mod;
        int right = solve(pos+1, tar, k-1) % mod;

        return dp[pos+1000][k] = (left + right) % mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(startPos, endPos, k);
    }
};