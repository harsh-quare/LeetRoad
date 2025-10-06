class Solution {
    using pii = pair<int, pair<int, int>>;
public:
    int swimInWater(vector<vector<int>>& grid) {
        // find min time in which yo can get to (n-1,n-1) cell starting from (0, 0)
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({dist[0][0], {0, 0}});

        vector<int> dirx = {-1, 0, 1, 0, -1};
        while(!pq.empty()){
            int curTime = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + dirx[i];
                int ny = y + dirx[i+1];

                if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                    int minReqTime = max(curTime, grid[nx][ny]);
                    if(minReqTime < dist[nx][ny]){
                        dist[nx][ny] = minReqTime;
                        pq.push({dist[nx][ny], {nx, ny}});
                    }
                }
            }
        }

        return dist[n-1][n-1];
    }
};