class Solution {
public:
    #define pip pair<int, pair<int, int>>
    vector<vector<int>> dirx = {{-1,0}, {1, 0}, {0,-1}, {0,1}};
    int minTimeToReach(vector<vector<int>>& grid) {
        //Dijkstra's
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<pip, vector<pip>, greater<pip>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> dist(m ,vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        vector<vector<bool>> vis(m ,vector<bool>(n, 0));

        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int t = pq.top().first;
            pq.pop();

            int stepTime = ((x+y) % 2 == 0) ? 1 : 2;  //cost

            if(x == m-1 && y == n-1) return t;

            if(vis[x][y] == true) continue;
            vis[x][y] = true;

            for(auto& dir: dirx){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                    if(dist[nx][ny] > stepTime + max(t, grid[nx][ny])){
                        dist[nx][ny] = stepTime + max(t, grid[nx][ny]);
                        pq.push({dist[nx][ny], {nx, ny}});
                    }
                }
            }
        }

        return dist[m-1][n-1];
    }
};