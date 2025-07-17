class Solution {
public:
    int solve(int i, int diff, vector<int>& nums, vector<vector<int>>& dp){
        // backward check
        if(i < 0) return 0;

        if(dp[i][diff + 500] != -1) return dp[i][diff + 500];

        int cnt = 0;
        for(int j = i-1; j >= 0; j--){
            if(nums[i] - nums[j] == diff){
                cnt = max(cnt, 1 + solve(j, diff, nums, dp));
            }
        }

        return dp[i][diff + 500] = cnt;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;

        vector<vector<int>> dp(n+1, vector<int>(1001, -1));

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                // {i,j} is the last pair of each subseq
                int diff = nums[j] - nums[i];

                ans = max(ans, 2 + solve(i, diff, nums, dp));  // what is the max length of subseq with diff as common difference in the array part [0,...,i-1]
            }
        }

        return ans;
    }
};