class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        //DIjkstra's
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        pq.push({0,{0,0}});
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while(!pq.empty()){
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == n-1 && y == m-1) return d;  //early stopping

            for(int i = 0; i < 4; i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]){
                    pq.push({d + grid[nx][ny], {nx, ny}});
                    vis[nx][ny] = 1;
                }
            }
        }

        return -1;
    }
};