class Solution {
    using pii = pair<int, pair<int, int>>;
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        int ans = 0;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        // push all the edge cells with their heights
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    pq.push({heightMap[i][j], {i, j}});
                    vis[i][j] = 1;
                }
            }
        } 

        vector<int> dirx = {-1, 0, 1, 0, -1};
        while(!pq.empty()){
            int h = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for(int i = 0; i < 4; i++){
                int new_x = x + dirx[i];
                int new_y = y + dirx[i+1];

                if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && !vis[new_x][new_y]){
                    ans += max(0, h - heightMap[new_x][new_y]);
                    vis[new_x][new_y] = true;
                    pq.push({max(h, heightMap[new_x][new_y]), {new_x, new_y}});
                }
            }
        }

        return ans;
    }
};