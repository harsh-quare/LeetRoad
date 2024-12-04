class Solution {
public:
    #define pip pair<int, pair<int, int>>
    vector<vector<int>> dirx = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int minTimeToReach(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pip, vector<pip>, greater<pip>> pq;
        pq.push({0, {0, 0}});

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vis[0][0] = true;

        while(!pq.empty()){
            int time = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == n-1 && y == m-1) return time;

            for(auto& dir: dirx){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]){
                    int new_time = max(time, grid[nx][ny]);
                    if(grid[nx][ny] <= new_time){
                        vis[nx][ny] = true;
                        pq.push({new_time+1, {nx, ny}});
                    }                    
                }
            }
        }

        return -1;
    }
};