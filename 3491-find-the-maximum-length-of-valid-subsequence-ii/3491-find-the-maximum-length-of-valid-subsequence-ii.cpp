class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        // row = 0 is for mod0
        // row = 1 is for mod1
        // row = 2 is for mod2
        // ...
        // row = k-1 is for mod(k-1)
        vector<vector<int>> dp(k, vector<int>(n, 1));
        int maxLen = 1;

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int mod = (nums[i] + nums[j]) % k;

                dp[mod][i] = max(dp[mod][i], 1 + dp[mod][j]);
                maxLen = max(maxLen, dp[mod][i]);
            }
        }

        return maxLen;
    }
};

// %k => 0,1,2,...k-1