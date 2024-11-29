class Solution {
public:
    #define pip pair<int, pair<int, int>>
    vector<vector<int>> dirx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;

        priority_queue<pip, vector<pip>, greater<pip>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        
        while(!pq.empty()){
            int t = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == m-1 && y == n-1) return dist[x][y];

            if(vis[x][y] == true) continue;

            vis[x][y] = true;

            for(auto& dir: dirx){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

                if(grid[nx][ny] <= t + 1){
                    dist[nx][ny] = t + 1;
                    pq.push({t+1, {nx, ny}});
                }
                else{
                    int diff_time = grid[nx][ny] - t;

                    if(diff_time % 2 == 0){
                        dist[nx][ny] = grid[nx][ny] + 1;
                        pq.push({dist[nx][ny], {nx, ny}});
                    }
                    else{
                        dist[nx][ny] = grid[nx][ny];
                        pq.push({dist[nx][ny], {nx, ny}});
                    }
                }
            }
        }

        return -1;
    }
};