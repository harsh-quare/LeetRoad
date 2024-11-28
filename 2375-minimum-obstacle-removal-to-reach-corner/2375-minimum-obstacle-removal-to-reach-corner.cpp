class Solution {
public:
    // Dijkstra
    #define pip pair<int, pair<int, int>>

    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<pip, vector<pip>, greater<pip>> pq;       
        pq.push({0, {0, 0}});  //0 obstacles at (0,0)  : {wt, {i,j}}

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));  // dist[i][j] = minimum distance/obstacle count from (0,0) to (i,j)
        dist[0][0] = 0;

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        while(!pq.empty()){
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == m-1 && y == n-1) return dist[x][y];  // or return d

            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && ny >= 0 && nx < m && ny < n){
                    int wt = (grid[nx][ny] == 1) ? 1 : 0;  //agar new cell obstacle h, to usko remove krna padega, means edge weight 1

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