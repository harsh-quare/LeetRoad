class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& tr, vector<vector<int>>& dp){
    //     // i+1 elements in ith row
    //     if(i >= tr.size() || j >= tr[i].size()) return 0;

    //     if(dp[i][j] != INT_MAX) return dp[i][j];

    //     int ans = tr[i][j];

    //     // go to i or i+1
    //     ans += min(solve(i+1, j, tr, dp), solve(i+1, j+1, tr, dp));

    //     return dp[i][j] = ans;
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        vector<int> prev(n+1, 0);
        for(int i = n-1; i >= 0; i--){
            vector<int> cur(i+1, 0);
            for(int j = 0; j <= i; j++){
                int res = triangle[i][j];

                int op1 = 0, op2 = 0;
                if(i < n-1) {
                    op1 = prev[j];
                    op2 = prev[j+1];
                }

                res += min(op1, op2);

                cur[j] = res;
            }
            prev = cur;
        }
        return prev[0];
    }
};