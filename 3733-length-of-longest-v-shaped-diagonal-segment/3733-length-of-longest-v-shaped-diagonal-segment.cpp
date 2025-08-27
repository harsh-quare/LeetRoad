class Solution {
public:
    vector<pair<int, int>> dirx = {
        {-1, -1}, // top-left
        {-1,  1}, // top-right
        { 1, -1}, // bottom-left
        { 1,  1}  // bottom-right
    };

    //clockwise turn mapping for each direction
    vector<int> turnCW = {1, 3, 0, 2};  // tl(0) -> tr(1); tr(1) -> br(3); bl(2) -> tl(0); br(3) -> bl(2)

    int dfs(int x, int y, int curDir, bool turned, int seqIdx, vector<vector<int>>& grid, int n, int m) {
        int len = 1;
        int nextVal = (seqIdx % 2 == 0) ? 2 : 0;

        //move in current direction
        int nx = x + dirx[curDir].first;
        int ny = y + dirx[curDir].second;

        if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == nextVal){
            len = max(len, 1 + dfs(nx, ny, curDir, turned, seqIdx + 1, grid, n, m));
        }

        if(!turned){
            int new_dir = turnCW[curDir];  // current direction ke liye clock wise turn konsa h
            int tx = x + dirx[new_dir].first;
            int ty = y + dirx[new_dir].second;
            if(tx >= 0 && tx < n && ty >= 0 && ty < m && grid[tx][ty] == nextVal){
                len = max(len, 1 + dfs(tx, ty, new_dir, true, seqIdx + 1, grid, n, m));
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
                    for(int d = 0; d < 4; d++){
                        ans = max(ans, dfs(i, j, d, false, 0, grid, n, m));
                    }
                }
            }
        }
        return ans;
    }
};