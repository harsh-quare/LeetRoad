class Solution {
public:
    vector<int> dirX = {-1, 0, 1, 0};
    vector<int> dirY = {0, -1, 0, 1};

    void bfs(int n, int m, vector<vector<int>>& heights, vector<vector<int>>& visited, queue<pair<int, int>>& q){
        while(!q.empty()){
            auto coords = q.front();
            q.pop();

            int r = coords.first;
            int c = coords.second;

            for(int i = 0; i < 4; i++){
                int nr = r + dirX[i];
                int nc = c + dirY[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && heights[nr][nc] >= heights[r][c]){
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacificVisited(n, vector<int>(m, 0));
        vector<vector<int>> atlanticVisited(n, vector<int>(m, 0));

        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;

        for(int i = 0; i < n; i++){
            pacificVisited[i][0] = 1;
            atlanticVisited[i][m - 1] = 1;
            pacificQueue.push({i, 0});
            atlanticQueue.push({i, m - 1});
        }

        for(int j = 0; j < m; j++){
            pacificVisited[0][j] = 1;
            atlanticVisited[n - 1][j] = 1;
            pacificQueue.push({0, j});
            atlanticQueue.push({n - 1, j});
        }

        bfs(n, m, heights, pacificVisited, pacificQueue);
        bfs(n, m, heights, atlanticVisited, atlanticQueue);

        vector<vector<int>> result;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pacificVisited[i][j] && atlanticVisited[i][j]){
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
