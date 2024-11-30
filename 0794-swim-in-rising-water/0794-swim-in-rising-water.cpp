class Solution {
public:
    #define pip pair<int, pair<int, int>>
    vector<vector<int>> dirx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int swimInWater(vector<vector<int>>& grid) {
        // minimum of all maximum elevetions in all paths
        // muje apne path me se max value chahiye
        // and woh max value saare paths me se minimum honi chahiye, vahi final answer h
        int n = grid.size();

        priority_queue<pip, vector<pip>, greater<pip>> pq;
        int cur_time = grid[0][0];  
        pq.push({cur_time, {0, 0}});

        // vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        // dist[0][0] = 0;

        vector<vector<bool>>vis(n, vector<bool>(n, 0));
        vis[0][0] = true;

        while(!pq.empty()){
            int time = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == n-1 && y == n-1) return time;

            for(auto& dir: dirx){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]){
                    int new_time = max(time, grid[nx][ny]);
                    pq.push({new_time, {nx, ny}});
                    vis[nx][ny] = true;
                }
            }
        }

        return -1;
    }
};