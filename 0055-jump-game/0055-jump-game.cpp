class Solution {
public:
    bool solve(vector<int>& nums, int id, vector<int>& dp){
        int n = nums.size();
        if(id == n-1){
            return true;
        }

        if(dp[id] != -1) return dp[id];

        //take, 1,2,...nums[id] steps and check if you can reach or not
        for(int i = 1; i <= nums[id]; i++){
            if(solve(nums, id+i, dp)) return dp[id] = true;
        }
        return dp[id] = false;
    }
    bool canJump(vector<int>& nums) {
        //try all ways
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, 0, dp);
    }
};