class Solution {
public:
    // Dijkstra's
    #define pip pair<int, pair<int, int>>
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<pip, vector<pip>, greater<pip>> pq;
        pq.push({0, {0,0}});

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        vector<vector<int>> dirx = {{-1, 0}, {1, 0}, {0,-1}, {0,1}};

        while(!pq.empty()){
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == m-1 && y == n-1) return d; // or dist[x][y]

            for(auto& dir: dirx){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                    int wt = (grid[nx][ny] == 1) ? 1 : 0;  //if obstacle in new cell, wt=1, else wt=0

                    if(d + wt < dist[nx][ny]){
                        dist[nx][ny] = d + wt;
                        pq.push({d+wt, {nx, ny}});
                    }
                }
            }
        }

        return dist[m-1][n-1];
    }
};