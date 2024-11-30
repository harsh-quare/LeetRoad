class Solution {
public:
    // Standard BFS, with some conditions
    // level wise traverse krna chahte h, current level pe ek obstacle hataya to fir next time k-1 bachne chahiye, uska track rkhne ke liye, visited 3-dimensional hoga
    vector<vector<int>> dirx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(k+1, 0))); 
        //the state at each cell will be like (x, y, removals): for each cell, there might be differenct states, that's why need to maintain visited array according to the all three guys
        vis[0][0][k] = 1;  // i, j, elimination power left

        queue<vector<int>> q;
        q.push({0, 0, k});
        int level = 0;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int x = q.front()[0];
                int y = q.front()[1];
                int removal = q.front()[2];
                q.pop();

                if(x == n-1 && y == m-1) return level;  //as soon as you get to the dest cell, return min steps

                for(auto& dir: dirx){
                    int nx = x + dir[0];
                    int ny = y + dir[1];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                        if(grid[nx][ny] == 1 && removal > 0 && !vis[nx][ny][removal-1]){
                            q.push({nx, ny, removal-1});
                            vis[nx][ny][removal-1] = 1;
                        }
                        else if(grid[nx][ny] == 0 && !vis[nx][ny][removal]){
                            q.push({nx, ny, removal});
                            vis[nx][ny][removal] = 1;
                        }
                    }
                }
            }
            level++;
        }

        return -1;
    }
};