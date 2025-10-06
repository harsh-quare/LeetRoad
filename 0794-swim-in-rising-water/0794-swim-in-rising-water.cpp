class Solution {
    using pii = pair<int, pair<int, int>>;
public:
    int swimInWater(vector<vector<int>>& grid) {
        // find min time in which yo can get to (n-1,n-1) cell starting from (0, 0)
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;

        vector<int> dirx = {-1, 0, 1, 0, -1};
        while(!pq.empty()){
            int curTime = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == n-1 && y == n-1) return curTime;

            for(int i = 0; i < 4; i++){
                int nx = x + dirx[i];
                int ny = y + dirx[i+1];

                if(nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    pq.push({max(curTime, grid[nx][ny]), {nx, ny}});
                }
            }
        }

        return -1;
    }
};