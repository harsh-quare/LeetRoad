class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> vis1(n, vector<int>(m, 0));
        vector<vector<int>> vis2(n, vector<int>(m, 0));

        queue<pair<int, int>> q1;
        queue<pair<int, int>> q2;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0){
                    vis1[i][j] = 1;
                    q1.push({i, j});
                }
                if(i == n-1 || j == m-1){
                    vis2[i][j] = 1;
                    q2.push({i, j});
                }
            }
        }

        vector<int> dirx = {-1, 0, 1, 0, -1};
        while(!q1.empty()){
            auto coords = q1.front();
            q1.pop();

            int r = coords.first;
            int c = coords.second;

            for(int i = 0; i < 4; i++){
                int nr = r + dirx[i];
                int nc = c + dirx[i+1];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis1[nr][nc] && heights[nr][nc] >= heights[r][c]){
                    vis1[nr][nc] = 1;
                    q1.push({nr, nc});
                }
            }
        }

        while(!q2.empty()){
            auto coords = q2.front();
            q2.pop();

            int r = coords.first;
            int c = coords.second;

            for(int i = 0; i < 4; i++){
                int nr = r + dirx[i];
                int nc = c + dirx[i+1];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis2[nr][nc] && heights[nr][nc] >= heights[r][c]){
                    vis2[nr][nc] = 1;
                    q2.push({nr, nc});
                }
            }
        }

        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis1[i][j] && vis2[i][j]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};