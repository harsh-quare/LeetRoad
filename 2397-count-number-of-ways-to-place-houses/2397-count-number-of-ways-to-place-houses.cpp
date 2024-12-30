class Solution {
public:
    const int mod= 1e9 + 7;
    int countHousePlacements(int n) {
        if(n == 1) return 4;
        vector<int> dp(n, 0);
        dp[0] = 2;
        dp[1] = 3;

        for(int i = 2; i < n; i++){
            dp[i] = (dp[i-1] + dp[i-2]) % mod;
        }

        long long ans = dp[n-1];
        ans = ans*ans % mod;

        return ans;
    }
};