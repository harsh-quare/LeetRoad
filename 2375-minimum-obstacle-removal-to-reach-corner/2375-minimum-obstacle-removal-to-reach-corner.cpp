class Solution {
public:
    // 0-1 BFS
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        deque<pair<int, int>> dq;
        dq.push_front({0,0});

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        vector<vector<int>> dirx = {{-1, 0}, {1, 0}, {0,-1}, {0,1}};

        while(!dq.empty()){
            int x = dq.front().first;
            int y = dq.front().second;
            dq.pop_front();

            int d = dist[x][y];

            if(x == m-1 && y == n-1) return dist[x][y];  // or d

            for(auto& dir: dirx){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                    int wt = (grid[nx][ny] == 1) ? 1 : 0;  //if obstacle in new cell, wt=1, else wt=0

                    if(d + wt < dist[nx][ny]){
                        dist[nx][ny] = d + wt;
                        if(grid[nx][ny] == 0) dq.push_front({nx, ny});
                        else dq.push_back({nx, ny});
                    }
                }
            }
        }

        return dist[m-1][n-1];
    }
};