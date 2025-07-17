class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        // Variation of LIS problem
        int n = nums.size();
        if(n <= 2) return n;

        vector<vector<int>> dp(n+1, vector<int>(1001, 0));
        // dp[i][diff] = longest arith. subseq ending at ith index with common diff = diff

        int ans = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int diff = nums[i] - nums[j] + 500;  // +500 to tackle negative diffs

                dp[i][diff] = (dp[j][diff] > 0) ? 1 + dp[j][diff] : 2;
                // agar jth wala koi subseq bana rha h, to uski length me 1 add krke
                // or agar uski subseq len 1 h, means single element, to current diff ke sath i,j ka ek pair with len=2 ban jayega

                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
};