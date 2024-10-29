class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, int m, int n, int prev, vector<vector<int>>& dp){
        if(i < 0 || j < 0 || i >= m || j >= n) return 0;
        if(j != 0 && grid[i][j] <= prev) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int upDiag = solve(i-1, j+1, grid, m, n, grid[i][j], dp);
        int right = solve(i, j+1, grid, m, n, grid[i][j], dp);
        int downDiag = solve(i+1, j+1, grid, m, n, grid[i][j], dp);

        return dp[i][j] = 1 + max(upDiag, max(right, downDiag));
    }
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        int ans = 0;
        for(int i = 0; i < m; i++){
            ans = max(ans, solve(i, 0, grid, m, n, grid[i][0], dp));
        }

        return ans-1;
    }
};