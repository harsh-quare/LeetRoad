class Solution {
public:
    // int dfs(int i, int j, vector<vector<int>>& grid, int n, int m){
    //     if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] <= 0) return 0;
    //     int cur = grid[i][j];
    //     grid[i][j] = 0;

    //     cur += dfs(i+1, j, grid, n, m);
    //     cur += dfs(i-1, j, grid, n, m);
    //     cur += dfs(i, j-1, grid, n, m);
    //     cur += dfs(i, j+1, grid, n, m);

    //     return cur;
    // }

    vector<vector<int>> dirx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxi = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] > 0){
                    // bfs or dfs anything can be used
                    // maxi = max(maxi, dfs(i, j, grid, n, m));

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    int cur = grid[i][j];
                    grid[i][j] = 0;

                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for(int k = 0; k < 4; k++){
                            int nx = x + dirx[k][0];
                            int ny = y + dirx[k][1];

                            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] > 0){
                                q.push({nx, ny});
                                cur += grid[nx][ny];
                                grid[nx][ny] = 0;
                            }
                        }
                    }

                    maxi = max(maxi, cur);
                }
            }
        }

        return maxi;
    }
};