class Solution {
public:
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
        if(i >= nums1.size() || j >= nums2.size()){
            return INT_MIN;
        }

        if(dp[i][j] != -1) return dp[i][j];

        // op-1: take both: take the dot
        int op1 = nums1[i]*nums2[j] + max(0, solve(i+1, j+1, nums1, nums2, dp));

        // op-2: skip 'i'
        int op2 = solve(i+1, j, nums1, nums2, dp);

        // op-3: skip 'j'
        int op3 = solve(i, j+1, nums1, nums2, dp);

        return dp[i][j] = max(op1, max(op2, op3));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));

        int ans = solve(0, 0, nums1, nums2, dp);

        return ans;
    }
};