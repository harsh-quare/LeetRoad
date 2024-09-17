class Solution {
public:
    bool sameDir(int x, int y, int nx, int ny, vector<vector<int>>& grid, int n, int m){
        int dir = grid[x][y];
        int dx = nx-x;
        int dy = ny-y;
        
        int move = -1;
        if(dx == 0 && dy == 1) move = 1;
        else if(dx == 0 && dy == -1) move = 2;
        else if(dx == 1 && dy == 0) move = 3;
        else if(dx == -1 && dy == 0) move = 4;

        if(dir == move) return true;
        return false;
    }
    int minCost(vector<vector<int>>& grid) {
        //DIjkstra's
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>> >pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e4));
        pq.push({0, {0, 0}}); //{d, {i,j}}
        dist[0][0] = 0;

        int dirx[4] = {-1, 0, 1, 0};
        int diry[4] = {0, 1, 0, -1};

        while(!pq.empty()){
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + dirx[i];
                int ny = y + diry[i];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    if(sameDir(x, y, nx, ny, grid, n, m)){
                        if(dist[nx][ny] > d){
                            dist[nx][ny] = d;
                            pq.push({dist[nx][ny], {nx, ny}});
                        }
                    }
                    else{
                        if(dist[nx][ny] > 1 + d){
                            dist[nx][ny] = 1 + d;
                            pq.push({dist[nx][ny], {nx, ny}});
                        }
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};