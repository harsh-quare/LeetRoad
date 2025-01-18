class Solution {
public:
    bool sameDirx(int x, int y, int nx, int ny, vector<vector<int>>& grid){
        if( (grid[x][y] == 1 && (x == nx && ny == y+1)) || 
            (grid[x][y] == 2 && (x == nx && ny == y-1)) ||
            (grid[x][y] == 3 && (x+1 == nx && ny == y)) ||
            (grid[x][y] == 4 && (x-1 == nx && ny == y)) 
           ) return true;
           
        return false;
    }
    vector<vector<int>> dirx = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int minCost(vector<vector<int>>& grid) {
        // BFS from (0, 0)
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int cost = node.first;
            int x = node.second.first;
            int y = node.second.second;

            if(x == n-1 && y == m-1) return cost;

            for(int i = 0; i < 4; i++){
                int nx = x + dirx[i][0];
                int ny = y + dirx[i][1];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    int newCost = cost + (sameDirx(x, y, nx, ny, grid) == true ? 0 : 1);
                    
                    if(newCost < dist[nx][ny]){
                        dist[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }

        return -1;
    }
};