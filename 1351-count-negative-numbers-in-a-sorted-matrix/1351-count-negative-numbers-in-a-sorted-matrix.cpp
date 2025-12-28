class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        for(int r = 0; r < n; r++){
            int idx = grid[r].end() - upper_bound(grid[r].begin(), grid[r].end(), 0, greater<int>());
            cnt += idx;
        }

        return cnt;
    }
};

// 4  3  2  -1
// 3  2  1  -1
// 1  1 -1  -2
//-1 -1 -2  -3 