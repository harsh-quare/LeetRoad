class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> rowc(n, 0);
        vector<int> colc(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    rowc[i]++;
                    colc[j]++;
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && (rowc[i] > 1 || colc[j] > 1)) cnt++;
            }
        }

        return cnt;
    }
};