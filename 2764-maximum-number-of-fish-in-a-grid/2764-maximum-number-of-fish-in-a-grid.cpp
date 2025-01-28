class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, int n, int m, int& curr){
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] <= 0){
            return ;
        }

        curr += grid[i][j];
        grid[i][j] = 0;  //mark visited

        dfs(i+1, j, grid, n, m, curr);
        dfs(i-1, j, grid, n, m, curr);
        dfs(i, j+1, grid, n, m, curr);
        dfs(i, j-1, grid, n, m, curr);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Problem wants us to find maximum sum of a connected component
        int maxi = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // visited ki jagah, I will be modifying the input array, non zero values ko zero bna dunga
                if(grid[i][j] > 0){
                    int curSum = 0;
                    dfs(i, j, grid, n, m, curSum);
                    maxi = max(maxi, curSum);
                }
            }
        }

        return maxi;
    }
};