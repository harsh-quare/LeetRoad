class Solution {
public:
    vector<pair<int, int>> dirx = {
        {-1, -1}, // top-left
        {-1, 1}, // top-right
        {1, -1}, // bottom-left
        {1, 1}  // bottom-right
    };

    vector<int> turnClockWiseDir = {1, 3, 0, 2};  // these are the new indexes of the dirx after making a turn from each dirx
    int dfs(int x, int y, int curDir, bool turned, int seqIdx, vector<vector<int>>& grid, int n, int m){
        int len = 1;
        int nextVal = (seqIdx % 2 == 0) ? 2 : 0;

        int nx = x + dirx[curDir].first;
        int ny = y + dirx[curDir].second;

        // if valid next guy in same dirx, get the ans after including it
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == nextVal){
            len = max(len, 1 + dfs(nx, ny, curDir, turned, seqIdx + 1, grid, n, m));
        }

        // if no turn has been made yet, try to make a clock wise turn and get the ans
        if(!turned){
            int new_dir = turnClockWiseDir[curDir];
            int tx = x + dirx[new_dir].first;
            int ty = y + dirx[new_dir].second;

            if(tx >= 0 && tx < n && ty >= 0 && ty < m && grid[tx][ty] == nextVal){
                len = max(len, 1 + dfs(tx, ty, new_dir, !turned, seqIdx + 1, grid, n, m));
            }
        }

        return len;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    for(int dir = 0; dir < 4; dir++){
                        ans = max(ans, dfs(i, j, dir, false, 0, grid, n, m));
                    }
                }
            }
        }

        return ans;
    }
};