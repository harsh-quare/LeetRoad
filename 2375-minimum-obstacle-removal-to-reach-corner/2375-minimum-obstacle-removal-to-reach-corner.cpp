class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        //DIjkstra's
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        pq.push({0,{0,0}});
        dist[0][0] = 0;
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while(!pq.empty()){
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == n-1 && y == m-1) return dist[x][y];  //early stopping

            for(int i = 0; i < 4; i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    if(grid[x][y] == 1){
                        //obstacle present: cost will be increased
                        if(1+d < dist[nx][ny]){
                            dist[nx][ny] = 1 + d;
                            pq.push({dist[nx][ny], {nx, ny}});
                        }
                    }
                    else{
                        if(d < dist[nx][ny]){
                            dist[nx][ny] = d;
                            pq.push({dist[nx][ny], {nx, ny}});
                        }
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};