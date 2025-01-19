class Solution {
private:
    bool isSafe(int i, int j, int m, int n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        //priority queue (min-heap) to always process the cell with the minimum height
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        //add all the boundary cells to the priority queue and mark them as visited
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                //boundary cells (first row, last row, first column, last column)
                if(i == 0 || j == 0 || i == m - 1 || j == n - 1){
                    pq.push({heightMap[i][j], {i, j}});
                    vis[i][j] = true;
                }
            }
        }

        vector<vector<int>> dirx = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int water = 0;  //to keep track of the total trapped water

        while(!pq.empty()){
            auto p = pq.top(); 
            pq.pop();

            int height = p.first;  // Height of the current cell
            int row = p.second.first;  // Row of the current cell
            int col = p.second.second;  // Column of the current cell

            for(auto& dir : dirx){
                int nextRow = row + dir[0];
                int nextCol = col + dir[1];

                // If the neighboring cell is within bounds and not visited
                if(isSafe(nextRow, nextCol, m, n) && vis[nextRow][nextCol] == false){
                    //calculate water trapped at this neighboring cell
                    water += max(0, height - heightMap[nextRow][nextCol]);
                    //push the next cell with the max of its own height or the current height
                    pq.push({max(height, heightMap[nextRow][nextCol]), {nextRow, nextCol}});
                    vis[nextRow][nextCol] = true;
                }
            }
        }

        //return the total trapped water
        return water;
    }
};