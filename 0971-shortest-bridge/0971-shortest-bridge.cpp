class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid, int n, queue<pair<int,int>>& q, vector<vector<int>>& vis){
        if(r < 0 || c < 0 || r >= n || c >= n || grid[r][c] == 0 || vis[r][c] == 1) return ;

        if(grid[r][c] == 1 && vis[r][c] == 0) q.push({r, c});
        vis[r][c] = 1;

        dfs(r+1, c, grid, n, q, vis);
        dfs(r-1, c, grid, n, q, vis);
        dfs(r, c+1, grid, n, q, vis);
        dfs(r, c-1, grid, n, q, vis);
    }

    int shortestBridge(vector<vector<int>>& grid){
        int n = grid.size();
        queue<pair<int,int>> q; //{i, j}
        vector<vector<int>> vis(n, vector<int>(n, 0));
        bool found = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    dfs(i, j, grid, n, q, vis);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }

        int dirx[4] = {-1, 1, 0, 0};
        int diry[4] = {0, 0, -1, 1};
        int step = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++){
                    int nx = x + dirx[i];
                    int ny = y + diry[i];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && vis[nx][ny] == 0){
                        if(grid[nx][ny] == 1) return step;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
            step++;
        }

        return -1;
    }
};