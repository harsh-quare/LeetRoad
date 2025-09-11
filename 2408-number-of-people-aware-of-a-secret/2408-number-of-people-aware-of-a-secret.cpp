class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int day, int forget, int delay, vector<int>& dp){  // total number of people who know secret on day "day"
        if(day == 1) return 1;

        if(dp[day] != -1) return dp[day];

        int res = 0;
        for(int prev = day-forget+1; prev <= day-delay; prev++){
            if(prev > 0){
                res = (res + solve(prev, forget, delay, dp) % MOD) % MOD;
            }
        }

        return dp[day] = res;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        int ans = 0;
        vector<int> dp(n+1, -1);
        for(int day = n-forget+1; day <= n; day++){
            if(day > 0){
                ans =(ans + solve(day, forget, delay, dp) % MOD) % MOD;
            }
        }

        return ans;
    }
};