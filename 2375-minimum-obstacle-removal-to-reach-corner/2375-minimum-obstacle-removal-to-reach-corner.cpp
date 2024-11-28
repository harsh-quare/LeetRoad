class Solution {
public:
    // 0-1 BFS
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dirx = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        deque<pair<int, int>> dq{{0, 0}};        //starting at (0,0)
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        while(!dq.empty()){
            int x = dq.front().first;
            int y = dq.front().second;
            dq.pop_front();

            int d = dist[x][y];

            if(x == m-1 && y == n-1) return dist[x][y];

            for(int k = 0; k < 4; k++){
                int newX = x + dx[k];
                int newY = y + dy[k];

                if(newX >= 0 && newY >= 0 && newX < m && newY < n){
                    int wt = (grid[newX][newY] == 1) ? 1 : 0;  //agar new cell me jaha ja rhe ho, woh obstacle h, to usko remove krna padega, means edge weight 1

                    if(d + wt < dist[newX][newY]){
                        dist[newX][newY] = d + wt;
                        grid[newX][newY] == 0 ? dq.push_front({newX, newY}) : dq.push_back({newX, newY});  //agar new cell me obstacle h to, usko push_back kro, qki ham har iteration me front se nodes lete h, to jisme fewer obstacle h usko process pahle krna priority h
                    }
                }
            }
        }

        return dist[m-1][n-1];
    }
};