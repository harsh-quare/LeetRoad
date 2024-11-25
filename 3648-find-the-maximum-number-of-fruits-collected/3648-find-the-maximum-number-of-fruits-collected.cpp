class Solution {
public:
    // Observe the problem carefully

    // Each child can only make n-1 moves
    
    // Child starting from (0,0) will always take minimum of (n-1) steps to reach target cell, i.e. diagonal path
    // all the other paths will result in more than n-1 steps. So, the path of (0,0) is fixed: Diagonal

    // Child from (0, n-1) can't cross the diagonal path of child c1, because if it does, it won't be able to reach
    // the target cell in n-1 steps, so the valid space of c2 is above the diagonal only

    // Similarly, child from (n-1, 0) can't cross the diagonal path of c1, because if it does, it won't be able to reach
    // the target cell in n-1 steps, so the valid space of c3 is below the diagonal only

    // Solve all these problem individually to get the max fruits possible

    int solveForC3(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp, int n){
        // Out of Boundary: either crosses grid boundary or crosses the diagonal of c1 (valid space: below diagonal: i>j)
        if(x < 0 || y < 0 || x >= n || y >= n){
            return -1e9;  
        }

        if(x == n-1 && y == n-1) return 0;  //already counted in diagonal path, just return back

        if(dp[x][y] != -1) return dp[x][y];

        int op1 = grid[x][y] + solveForC3(x-1, y+1, grid, dp, n);

        int op2 = grid[x][y] + solveForC3(x, y+1, grid, dp, n);

        int op3 = grid[x][y] + solveForC3(x+1, y+1, grid, dp, n);

        return dp[x][y] = max({op1, op2, op3});
    }

    int solveForC2(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp, int n){
        // Out of Boundary: either crosses grid boundary or crosses the diagonal of c1 (valid space: above diagonal: i<j)
        if(x < 0 || y < 0 || x >= n || y >= n){
            return -1e9;
        }

        if(x == n-1 && y == n-1) return 0;  //already counted in diagonal path, just return back

        if(dp[x][y] != -1) return dp[x][y];

        int op1 = grid[x][y] + solveForC2(x+1, y-1, grid, dp, n);

        int op2 = grid[x][y] + solveForC2(x+1, y, grid, dp, n);

        int op3 = grid[x][y] + solveForC2(x+1, y+1, grid, dp, n);

        return dp[x][y] = max({op1, op2, op3});
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();

        int fruits_ch1 = 0;  // C1 follows diagonal path, also takes target cell fruits
        for(int i = 0; i < n; i++) {
            fruits_ch1 += fruits[i][i];
            fruits[i][i] = 0;  // I don't want these cells to be considered again
        }

        vector<vector<int>> dp1(n, vector<int>(n, -1));
        int fruits_ch2 = solveForC2(0, n-1, fruits, dp1, n);
        
        vector<vector<int>> dp2(n, vector<int>(n, -1));
        int fruits_ch3 = solveForC3(n-1, 0, fruits, dp2, n);

        return fruits_ch1 + fruits_ch2 + fruits_ch3;
    }
};