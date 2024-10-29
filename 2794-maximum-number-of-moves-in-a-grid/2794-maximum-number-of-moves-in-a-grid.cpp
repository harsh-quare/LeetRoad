class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& grid, int m, int n, int prev, vector<vector<int>>& dp){
    //     if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] <= prev) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int upDiag = solve(i-1, j+1, grid, m, n, grid[i][j], dp);
    //     int right = solve(i, j+1, grid, m, n, grid[i][j], dp);
    //     int downDiag = solve(i+1, j+1, grid, m, n, grid[i][j], dp);

    //     return dp[i][j] = 1 + max(upDiag, max(right, downDiag));
    // }
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int ans = 0;
        for(int i = 0; i < m; i++){  //initializing last column to 1
            dp[i][n-1] = 1;
        }

        for(int j = n-2; j >= 0; j--){
            for(int i = 0; i < m; i++){
                int val = grid[i][j];

                int moves = (val < grid[i][j+1]) ? dp[i][j+1] : 0;
                if(i > 0 && val < grid[i-1][j+1]) moves = max(moves, dp[i-1][j+1]);
                if(i < m-1 && val < grid[i+1][j+1]) moves = max(moves, dp[i+1][j+1]);

                dp[i][j] = 1 + moves;
            }
        }

        for(int i = 0; i < m; i++){
            ans = max(ans, dp[i][0]);
        }

        return ans-1;  //subtracting 1 as per initial setup
    }
};