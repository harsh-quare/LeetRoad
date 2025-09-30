class Solution {
public:
    int solve(vector<int>& values, int i, int j, vector<vector<int>>& dp){
        if(j - i <= 1) return 0;  // if there are no points between i and j, no triangle can be formed

        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;

        for(int k = i+1; k < j; k++){
            int wt = (values[i] * values[k] * values[j])
                      + solve(values, i, k, dp) 
                      + solve(values, k, j, dp);

            ans = min(ans, wt);
        }

        return dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(values, 0, n-1, dp);
    }
};

// T.C. => O(n^3)
// S.C. => O(n^2)