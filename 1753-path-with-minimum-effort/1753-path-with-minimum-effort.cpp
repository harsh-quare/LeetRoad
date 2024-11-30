class Solution {
public:
    #define pip pair<int, pair<int, int>>
    vector<vector<int>> dirx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pip, vector<pip>, greater<pip>> pq;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            int effort = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == n-1 && y == m-1) return effort;

            for(auto& dir: dirx){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m){

                    int new_effort = max(effort, abs(grid[x][y] - grid[nx][ny]));
                    if(new_effort < dist[nx][ny]){
                        dist[nx][ny] = new_effort;
                        pq.push({new_effort, {nx, ny}});
                    }
                }
            }
        }

        return -1;
    }
};