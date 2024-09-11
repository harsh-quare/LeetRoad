class Solution {
public:
    int solve(int id, vector<int>& nums, vector<int>& dp){
        if(id >= nums.size()-1){
            return 0;
        }

        if(dp[id] != -1) return dp[id];

        int ans = 1e5;
        for(int i = 1; i <= nums[id]; i++){
            ans = min(ans, 1 + solve(id+i, nums, dp));
        }

        return dp[id] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
    }
};