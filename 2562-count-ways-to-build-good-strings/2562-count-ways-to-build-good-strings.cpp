class Solution {
public:
const int mod = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);
        
        // dp[i] => Number of good strings of length i

        dp[0] = 1; // Base case: only 1 way to create an empty string. ""

        for(int len = 1; len <= high; len++){
            if(len - zero >= 0){
                dp[len] = (dp[len]%mod + dp[len - zero]%mod)%mod;
            }
            if(len - one >= 0){
                dp[len] = (dp[len]%mod + dp[len - one]%mod)%mod;
            }
        }

        int cnt = 0;
        for(int i = low; i <= high; i++){
            cnt = (cnt + dp[i] % mod) % mod;
        }

        return cnt;
    }
};