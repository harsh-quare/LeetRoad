class Solution {
public:
    // All 4 directions are written in adjacently 90 degrees clock wise to each other. for dirx[0], dirx[1] is the new dirx after clockwise 90 degree turn. for i => i+1 ===> i => (i+1) % 4 
    vector<pair<int, int>> dirx = {
        {1,   1},  // bottom-right
        {1,  -1}, // bottom-left
        {-1, -1}, // top-left
        {-1,  1}  // top-right
    };

    int dp[501][501][4][2];

    int dfs(int x, int y, int curDir, bool turned, int nextVal, vector<vector<int>>& grid, int n, int m){
        if(dp[x][y][curDir][turned] != -1) return dp[x][y][curDir][turned];

        int nx = x + dirx[curDir].first;
        int ny = y + dirx[curDir].second;

        if(nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != nextVal){
            return 0;
        }

        int len = 0;

        // keep moving in the same direction
        len = max(len, 1 + dfs(nx, ny, curDir, turned, (nextVal == 2) ? 0 : 2, grid, n, m));

        // make a turn if possible
        if(!turned){
            len = max(len, 1 + dfs(nx, ny, (curDir + 1) % 4, !turned, (nextVal == 2) ? 0 : 2, grid, n, m));
        }

        return dp[x][y][curDir][turned] = len;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        // vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(m, vector<vector<int>>(4, vector<int>(2, -1))));
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    for(int d = 0; d <= 3; d++){
                        ans = max(ans, 1 + dfs(i, j, d, false, 2, grid, n, m));
                    }
                }
            }
        }

        return ans;
    }
};