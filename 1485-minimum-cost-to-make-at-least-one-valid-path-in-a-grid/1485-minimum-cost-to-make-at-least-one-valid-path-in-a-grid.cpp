class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        //DIjkstra's
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>> >pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e4));
        pq.push({0, {0, 0}}); //{d, {i,j}}
        dist[0][0] = 0;

        vector<pair<int, int>> dirx = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        //store directions' representations in map for efficient lookup when needed.
        map<pair<int, int>, int> mp;
        mp[{0,1}] = 1;
        mp[{0,-1}] = 2;
        mp[{1,0}] = 3;
        mp[{-1,0}] = 4;

        while(!pq.empty()){
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == n-1 && y == m-1) return dist[x][y];  //early stopping

            for(int i = 0; i < 4; i++){
                int nx = x + dirx[i].first;
                int ny = y + dirx[i].second;

                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    if(grid[x][y] == mp[dirx[i]]){  // if we are moving in the same direction as given, no extra cost required
                        if(dist[nx][ny] > d){
                            dist[nx][ny] = d;
                            pq.push({dist[nx][ny], {nx, ny}});
                        }
                    }
                    else{
                        //else when we are moving in some other direction than in given cell, then we need extra 1 cost to move in that direction, bcz we would need to change the dirction sign in that direction
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