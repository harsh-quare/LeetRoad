class Solution {
public:
    int solve(int i, int remTarget, vector<int>& nums, vector<vector<int>>& dp){
        if(remTarget == 0) return 0;  // when target is zero that means we found set of elements that sum up to target
        if(i >= nums.size() || remTarget < 0){ // if target is less then 0 or i is greater than nums size then its invalid case and just return with very small number     
            return -1001;
        }

        if(dp[i][remTarget] != -1) return dp[i][remTarget];

        // skip
        int skip = solve(i+1, remTarget, nums, dp);

        // pick
        int pick = 1 + solve(i+1, remTarget - nums[i], nums, dp);  // add 1 length to ans

        return dp[i][remTarget] = max(skip, pick);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        int ans = solve(0, target, nums, dp); //curId, curLenSubSeq, remainingTarget, nums
        return (ans > 0) ? ans : -1;
    }
};