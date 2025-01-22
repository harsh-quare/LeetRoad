class Solution {
public:
    vector<vector<int>> dirx = {{-1, 0}, {0,1},{1,0},{0,-1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // basic bfs
        // get the distance of each cell
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(isWater[i][j] == 1){
                    q.push({i, j});
                    dist[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            auto p = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + dirx[i][0];
                int ny = y + dirx[i][1];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]){
                    if(dist[nx][ny] > dist[x][y] + 1){
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return dist;
    }
};